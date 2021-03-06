// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

window.onload = function() {
  chrome.contextMenus.create(
      {"title":"Page item", contexts: ["page"]},
      function() {
        if (!chrome.extension.lastError) {
          chrome.contextMenus.create(
          {"title":"Frame item", contexts: ["frame"]},
          function() {
            if (!chrome.extension.lastError) {
              chrome.test.sendMessage("created items");
            }
          });
        }
      });
};
