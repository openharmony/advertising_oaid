/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_CLOUD_OAID_IREMOTE_CONFIG_OBSERVER_H
#define OHOS_CLOUD_OAID_IREMOTE_CONFIG_OBSERVER_H

#include <string>

#include "iremote_broker.h"

namespace OHOS {
namespace Cloud {
class IRemoteConfigObserver : public IRemoteBroker {
public:
    DECLARE_INTERFACE_DESCRIPTOR(u"ohos.cloud.oaid.IRemoteConfigObserver");
    enum class RegisterObserverCode {
        OnOaidUpdated = 0,
    };
    virtual void OnOaidUpdated(const std::string& value) = 0;
};
} // namespace HaCloud
} // namespace OHOS
#endif // OHOS_CLOUD_HA_IREMOTE_CONFIG_OBSERVER_H