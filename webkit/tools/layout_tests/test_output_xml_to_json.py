#!/usr/bin/env python
# Copyright (c) 2010 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""
This is a script for generating JSON from JUnit XML output (generated by
google tests with --gtest_output=xml option).
"""
import logging
import optparse
import os
import sys
import time

from xml.dom import minidom

from layout_package import json_results_generator
from layout_package import path_utils
from layout_package import test_expectations

# Builder base URL where we have the archived test results.
BUILDER_BASE_URL = "http://build.chromium.org/buildbot/gtest-results/"

class JSONGeneratorFromXML(object):
  def __init__(self, options):
    self._options = options

    # Check the results directory
    if not os.path.exists(self._options.results_directory):
      os.mkdir(self._options.results_directory)

    results_xml_file = None
    try:
      results_xml_file = open(self._options.input_results_xml)
    except IOError, e:
      logging.fatal("Cannot open file %s", self._options.input_results_xml)
      sys.exit(1)

    summary = self._ParseTestResultsXML(
        minidom.parse(results_xml_file).documentElement)
    results_xml_file.close()

    json_results_generator.JSONResultsGenerator(
        self._options.builder_name, self._options.build_name,
        self._options.build_number, self._options.results_directory,
        self._options.builder_base_url,
        self._test_timings,
        self._failures, self._passed_tests, self._skipped_tests,
        self._tests_list)

  def _ParseTestResultsXML(self, node):
    self._tests_list = set()
    self._passed_tests = set()
    self._skipped_tests = set()
    self._test_timings = {}
    self._failures = {}

    testcases = node.getElementsByTagName('testcase')
    for testcase in testcases:
      name = testcase.getAttribute('name')
      classname = testcase.getAttribute('classname')
      test_name = "%s.%s" % (classname, name)

      status = testcase.getAttribute('status')
      if status == 'notrun':
        if name.startswith('DISABLED_'):
          self._skipped_tests.add(test_name)
        continue

      failures = testcase.getElementsByTagName('failure')
      if failures:
        self._failures[test_name] = test_expectations.TEXT
      else:
        self._passed_tests.add(test_name)

      self._test_timings[test_name] = float(testcase.getAttribute('time'))
      self._tests_list.add(test_name)


def main(options, args):
  """Parse the tests results and generate JSON files.

  Args:
    options: a dictionary of command line options
    args: a list of sub directories or files to test
  """

  if not options.test_type:
    logging.error("--test-type needs to be specified.")
    sys.exit(1)

  canon_test_type = options.test_type.replace("-", "_")
  if not options.input_results_xml:
    options.input_results_xml = "%s.xml" % (canon_test_type)
  if not options.builder_base_url:
    options.builder_base_url = "%s%s/" % (BUILDER_BASE_URL, options.test_type)

  JSONGeneratorFromXML(options)

  return

if '__main__' == __name__:
  option_parser = optparse.OptionParser()
  option_parser.add_option("", "--test-type", default="",
                           help="Test type that generated the results XML,"
                                " e.g. unit-tests.")
  option_parser.add_option("", "--results-directory", default="./",
                           help="Output results directory source dir.")
  option_parser.add_option("", "--input-results-xml", default="",
                           help="Test results xml file (input for us)."
                                " default is TEST_TYPE.xml")
  option_parser.add_option("", "--builder-base-url", default="",
                           help=("A URL where we have the archived test "
                                 "results. (default=%sTEST_TYPE_results/)"
                                 % BUILDER_BASE_URL))
  option_parser.add_option("", "--builder-name",
                           default="DUMMY_BUILDER_NAME",
                           help="The name of the builder shown on the "
                                "waterfall running this script e.g. WebKit.")
  option_parser.add_option("", "--build-name",
                           default="DUMMY_BUILD_NAME",
                           help="The name of the builder used in its path, "
                                "e.g. webkit-rel.")
  option_parser.add_option("", "--build-number",
                           default="DUMMY_BUILD_NUMBER",
                           help="The build number of the builder running"
                                "this script.")
  options, args = option_parser.parse_args()
  main(options, args)
