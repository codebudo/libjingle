/*
 * libjingle
 * Copyright 2011, Google Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TALK_APP_WEBRTC_SESSIONDESCRIPTIONPROVIDER_H_
#define TALK_APP_WEBRTC_SESSIONDESCRIPTIONPROVIDER_H_

#include "talk/session/phone/mediasession.h"
#include "talk/p2p/base/candidate.h"
#include "talk/p2p/base/sessiondescription.h"

namespace webrtc {

class SessionDescriptionProvider {
 public:
  // Creates a new SessionDescription based on |options|.
  // It does not affect the currently set local or remote SessionDescription.
  // Caller is owner of the created SessionDescription.
  virtual cricket::SessionDescription* CreateOffer(
      const cricket::MediaSessionOptions& options) = 0;

  // Creates a new SessionDescription based on |offer| and |options|.
  // It does not affect the currently set local or remote SessionDescription.
  // Caller is owner of the created SessionDescription.
  virtual cricket::SessionDescription* CreateAnswer(
      const cricket::SessionDescription* offer,
      const cricket::MediaSessionOptions& options) = 0;

  // Transfers ownership of session description.
  virtual void SetLocalDescription(const cricket::SessionDescription* desc,
                                   cricket::ContentAction type) = 0;
  virtual void SetRemoteDescription(cricket::SessionDescription* desc,
                                    cricket::ContentAction type) = 0;
  // Sets all the currently known remote candidates.
  virtual void SetRemoteCandidates(
      const std::vector<cricket::Candidate>& remote_candidates) = 0;

  // Current local session description.
  virtual const cricket::SessionDescription* local_description() const = 0;
  // Current remote session description.
  virtual const cricket::SessionDescription* remote_description() const = 0;

 protected:
  virtual ~SessionDescriptionProvider() {}
};

}  // namespace webrtc

#endif  // TALK_APP_WEBRTC_SESSIONDESCRIPTIONPROVIDER_H_
