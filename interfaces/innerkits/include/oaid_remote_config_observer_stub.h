/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_CLOUD_OAID_REMOTE_CONFIG_OBSERVER_STUB_H
#define OHOS_CLOUD_OAID_REMOTE_CONFIG_OBSERVER_STUB_H

#include "iremote_stub.h"
#include "oaid_iremote_config_observer.h"

namespace OHOS {
namespace Cloud {
class RemoteConfigObserverStub : public IRemoteStub<IRemoteConfigObserver> {
public:
    RemoteConfigObserverStub();
    virtual ~RemoteConfigObserverStub() override;

    /* *
     * Handle remote request.
     *
     * @param data Input param.
     * @param reply Output param.
     * @param option Message option.
     * @return int32_t, return ERR_OK on success, others on failure.
     */
    int32_t OnRemoteRequest(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option) override;

    // virtual int32_t OnOaidUpdated(const std::string& value) override;
    virtual void OnOaidUpdated(const std::string& value) override {}

private:
    int32_t HandleOAIDUpdate(MessageParcel& data, MessageParcel& reply);
};
} // namespace HaCloud
} // namespace OHOS
#endif // OHOS_CLOUD_OAID_REMOTE_CONFIG_OBSERVER_STUB_H