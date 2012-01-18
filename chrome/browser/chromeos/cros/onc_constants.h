// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_CROS_ONC_CONSTANTS_H_
#define CHROME_BROWSER_CHROMEOS_CROS_ONC_CONSTANTS_H_
#pragma once

namespace chromeos {

// Constants for ONC properties.
namespace onc {

extern const char kGUID[];
extern const char kProxySettings[];
extern const char kName[];
extern const char kRemove[];
extern const char kType[];
extern const char kVPN[];
extern const char kWiFi[];

namespace wifi {
extern const char kAutoConnect[];
extern const char kEAP[];
extern const char kHiddenSSID[];
extern const char kPassphrase[];
extern const char kProxyURL[];
extern const char kSSID[];
extern const char kSecurity[];
}  // namespace wifi

namespace eap {
extern const char kAnonymousIdentity[];
extern const char kClientCertPattern[];
extern const char kClientCertRef[];
extern const char kClientCertType[];
extern const char kIdentity[];
extern const char kInner[];
extern const char kOuter[];
extern const char kPassword[];
extern const char kSaveCredentials[];
extern const char kServerCARef[];
extern const char kUseSystemCAs[];
}  // namespace eap

namespace vpn {
extern const char kAuthNoCache[];
extern const char kAuthRetry[];
extern const char kAuth[];
extern const char kAuthenticationType[];
extern const char kCipher[];
extern const char kClientCertPattern[];
extern const char kClientCertRef[];
extern const char kClientCertType[];
extern const char kCompLZO[];
extern const char kCompNoAdapt[];
extern const char kGroup[];
extern const char kHost[];
extern const char kIKEVersion[];
extern const char kIPsec[];
extern const char kKeyDirection[];
extern const char kL2TP[];
extern const char kNsCertType[];
extern const char kOpenVPN[];
extern const char kPSK[];
extern const char kPassword[];
extern const char kPort[];
extern const char kProto[];
extern const char kPushPeerInfo[];
extern const char kRemoteCertEKU[];
extern const char kRemoteCertKU[];
extern const char kRemoteCertTLS[];
extern const char kRenegSec[];
extern const char kSaveCredentials[];
extern const char kServerCARef[];
extern const char kServerCertRef[];
extern const char kServerPollTimeout[];
extern const char kShaper[];
extern const char kStaticChallenge[];
extern const char kTLSAuthContents[];
extern const char kTLSRemote[];
extern const char kType[];
extern const char kUsername[];
}  // namespace vpn

namespace proxy {
extern const char kDirect[];
extern const char kExcludeDomains[];
extern const char kFtp[];
extern const char kHost[];
extern const char kHttp[];
extern const char kHttps[];
extern const char kManual[];
extern const char kPAC[];
extern const char kPort[];
extern const char kSocks[];
extern const char kType[];
extern const char kWPAD[];
}  // namespace proxy

}  // namespace onc

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_CROS_ONC_CONSTANTS_H_
// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_CROS_ONC_CONSTANTS_H_
#define CHROME_BROWSER_CHROMEOS_CROS_ONC_CONSTANTS_H_
#pragma once

namespace chromeos {

// Constants for ONC properties.
namespace onc {

extern const char kGUID[];
extern const char kName[];
extern const char kRemove[];
extern const char kType[];
extern const char kVPN[];
extern const char kWiFi[];

namespace wifi {
extern const char kAutoConnect[];
extern const char kEAP[];
extern const char kHiddenSSID[];
extern const char kPassphrase[];
extern const char kProxyURL[];
extern const char kSSID[];
extern const char kSecurity[];
}  // namespace wifi

namespace eap {
extern const char kAnonymousIdentity[];
extern const char kClientCertPattern[];
extern const char kClientCertRef[];
extern const char kClientCertType[];
extern const char kIdentity[];
extern const char kInner[];
extern const char kOuter[];
extern const char kPassword[];
extern const char kSaveCredentials[];
extern const char kServerCARef[];
extern const char kUseSystemCAs[];
}  // namespace eap

namespace vpn {
extern const char kAuthNoCache[];
extern const char kAuthRetry[];
extern const char kAuth[];
extern const char kAuthenticationType[];
extern const char kCipher[];
extern const char kClientCertPattern[];
extern const char kClientCertRef[];
extern const char kClientCertType[];
extern const char kCompLZO[];
extern const char kCompNoAdapt[];
extern const char kGroup[];
extern const char kHost[];
extern const char kIKEVersion[];
extern const char kIPsec[];
extern const char kKeyDirection[];
extern const char kL2TP[];
extern const char kNsCertType[];
extern const char kOpenVPN[];
extern const char kPSK[];
extern const char kPassword[];
extern const char kPort[];
extern const char kProto[];
extern const char kPushPeerInfo[];
extern const char kRemoteCertEKU[];
extern const char kRemoteCertKU[];
extern const char kRemoteCertTLS[];
extern const char kRenegSec[];
extern const char kSaveCredentials[];
extern const char kServerCARef[];
extern const char kServerCertRef[];
extern const char kServerPollTimeout[];
extern const char kShaper[];
extern const char kStaticChallenge[];
extern const char kTLSAuthContents[];
extern const char kTLSRemote[];
extern const char kType[];
extern const char kUsername[];
}  // namespace vpn

}  // namespace onc

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_CROS_ONC_CONSTANTS_H_
