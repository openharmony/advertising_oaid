/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is: distributed on an "AS is:"BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "oaid_service_proxy.h"
#include "iremote_broker.h"
#include "oaid_common.h"
#include "oaid_service_interface.h"
#include "oaid_service_ipc_interface_code.h"
#include "app_event_processor_mgr.h"
#include "app_event.h"

namespace OHOS {
namespace Cloud {
using namespace OHOS::HiviewDFX;

OAIDServiceProxy::OAIDServiceProxy(const sptr<IRemoteObject> &object) : IRemoteProxy<IOAIDService>(object)
{}

std::string OAIDServiceProxy::GetOAID()
{
    OAID_HILOGI(OAID_MODULE_CLIENT, "GetOAID Begin.");
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;

    if (!data.WriteInterfaceToken(GetDescriptor())) {
        OAID_HILOGE(OAID_MODULE_CLIENT, "Failed to write parcelable");
        return "";
    }

    int32_t result = Remote()->SendRequest(static_cast<uint32_t>(OAIDInterfaceCode::GET_OAID), data, reply, option);
    if (result != ERR_NONE) {
        OAID_HILOGE(OAID_MODULE_CLIENT, "Get OAID failed, error code is: %{public}d", result);
        return "";
    }
    auto oaid = reply.ReadString();

    return oaid;
}

int32_t OAIDServiceProxy::ResetOAID()
{
    OAID_HILOGI(OAID_MODULE_CLIENT, "Reset OAID Begin.");
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;

    if (!data.WriteInterfaceToken(GetDescriptor())) {
        OAID_HILOGE(OAID_MODULE_CLIENT, "Failed to write parcelable");
    }

    int32_t result = Remote()->SendRequest(static_cast<uint32_t>(OAIDInterfaceCode::RESET_OAID), data, reply, option);
    if (result != ERR_NONE) {
        OAID_HILOGE(OAID_MODULE_CLIENT, "Reset OAID failed, error code is: %{public}d", result);
    }
    OAID_HILOGI(OAID_MODULE_CLIENT, "Reset OAID End.");

    if (result == ERR_OK) {
        auto oaid = GetOAID();
        HiviewDFX::HiAppEvent::ReportConfig config;
        config.name = "ha_app_event";
        config.routeInfo = "AUTO";
        config.eventConfigs.clear();

        HiviewDFX::HiAppEvent::EventConfig eventConfig;
        eventConfig.domain = "CommonEvent";
        eventConfig.name = "ADS_ID_REFRESH";
        eventConfig.isRealTime = true;
        config.eventConfigs.push_back(eventConfig);
        HiviewDFX::HiAppEvent::AppEventProcessorMgr::AddProcessor(config);

        // 写事件
        HiviewDFX::HiAppEvent::Event event("CommonEvent", "ADS_ID_REFRESH", HiviewDFX::HiAppEvent::BEHAVIOR);
        std::string oaidKey = "oaid";
        event.AddParam("type", oaidKey);
        event.AddParam("id", oaid);
        HiviewDFX::HiAppEvent::Write(event);
        OAID_HILOGI(OAID_MODULE_CLIENT, "Reset OAID WriteEvent success!");
    }
    int32_t errorCode = reply.ReadInt32();
    OAID_HILOGI(OAID_MODULE_CLIENT, "Reset OAID End.errorCode = %{public}d", errorCode);
    return errorCode;
}
}  // namespace Cloud
}  // namespace OHOS