// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_COMMON_NACL_DEBUG_EXCEPTION_HANDLER_WIN_H_
#define CHROME_COMMON_NACL_DEBUG_EXCEPTION_HANDLER_WIN_H_
#pragma once

#include "base/callback.h"
#include "base/message_loop.h"

void NaClStartDebugExceptionHandlerThread(int32 nacl_process_id,
                                          base::MessageLoopProxy* message_loop,
                                          const base::Closure& on_connected);

#endif  // CHROME_COMMON_NACL_DEBUG_EXCEPTION_HANDLER_WIN_H_
