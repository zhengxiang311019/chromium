// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_DOM_UI_DOWNLOADS_DOM_HANDLER_H_
#define CHROME_BROWSER_DOM_UI_DOWNLOADS_DOM_HANDLER_H_
#pragma once

#include <vector>

#include "base/scoped_callback_factory.h"
#include "chrome/browser/dom_ui/dom_ui.h"
#include "chrome/browser/download/download_item.h"
#include "chrome/browser/download/download_manager.h"

class Value;

// The handler for Javascript messages related to the "downloads" view,
// also observes changes to the download manager.
class DownloadsDOMHandler : public DOMMessageHandler,
                            public DownloadManager::Observer,
                            public DownloadItem::Observer {
 public:
  explicit DownloadsDOMHandler(DownloadManager* dlm);
  virtual ~DownloadsDOMHandler();

  void Init();

  // DOMMessageHandler implementation.
  virtual void RegisterMessages();

  // DownloadItem::Observer interface
  virtual void OnDownloadUpdated(DownloadItem* download);
  virtual void OnDownloadFileCompleted(DownloadItem* download) { }
  virtual void OnDownloadOpened(DownloadItem* download) { }

  // DownloadManager::Observer interface
  virtual void ModelChanged();

  // Callback for the "getDownloads" message.
  void HandleGetDownloads(const Value* value);

  // Callback for the "openFile" message - opens the file in the shell.
  void HandleOpenFile(const Value* value);

  // Callback for the "drag" message - initiates a file object drag.
  void HandleDrag(const Value* value);

  // Callback for the "saveDangerous" message - specifies that the user
  // wishes to save a dangerous file.
  void HandleSaveDangerous(const Value* value);

  // Callback for the "discardDangerous" message - specifies that the user
  // wishes to discard (remove) a dangerous file.
  void HandleDiscardDangerous(const Value* value);

  // Callback for the "show" message - shows the file in explorer.
  void HandleShow(const Value* value);

  // Callback for the "pause" message - pauses the file download.
  void HandlePause(const Value* value);

  // Callback for the "remove" message - removes the file download from shelf
  // and list.
  void HandleRemove(const Value* value);

  // Callback for the "cancel" message - cancels the download.
  void HandleCancel(const Value* value);

  // Callback for the "clearAll" message - clears all the downloads.
  void HandleClearAll(const Value* value);

 private:
  // Send the current list of downloads to the page.
  void SendCurrentDownloads();

  // Clear all download items and their observers.
  void ClearDownloadItems();

  // Return the download that corresponds to a given id.
  DownloadItem* GetDownloadById(int id);

  // Return the download that is referred to in a given value.
  DownloadItem* GetDownloadByValue(const Value* value);

  // Current search text.
  std::wstring search_text_;

  // Our model
  DownloadManager* download_manager_;

  // The current set of visible DownloadItems for this view received from the
  // DownloadManager. DownloadManager owns the DownloadItems. The vector is
  // kept in order, sorted by ascending start time.
  typedef std::vector<DownloadItem*> OrderedDownloads;
  OrderedDownloads download_items_;

  base::ScopedCallbackFactory<DownloadsDOMHandler> callback_factory_;

  DISALLOW_COPY_AND_ASSIGN(DownloadsDOMHandler);
};

#endif  // CHROME_BROWSER_DOM_UI_DOWNLOADS_DOM_HANDLER_H_
