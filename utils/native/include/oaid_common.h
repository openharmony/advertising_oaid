/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#ifndef OHOS_CLOUD_OAID_COMMON_H
#define OHOS_CLOUD_OAID_COMMON_H

#include <map>
#include "oaid_hilog_wreapper.h"
#include "errors.h"

namespace OHOS {
namespace Cloud {
#if defined(__GNUC__) && (__GNUC__ >= 4)
    #define OAID_PUBLIC_API __attribute__((visibility ("default")))
    #define OAID_LOCAL_API __attribute__((visibility ("hidden")))
#else
    #define OAID_PUBLIC_API
    #define OAID_LOCAL_API
#endif

enum OAIDError : int32_t {
    ERR_OK = 0,
    ERR_INVALID_PARAM = 401,
    ERR_PERMISSION_ERROR = 403,
    ERR_SYSYTEM_ERROR = 17300001,
    ERR_NULL_POINTER = 17300002,
    ERR_WRITE_PARCEL_FAILED = 17300003,
};

static std::map<int32_t, std::string> oaidErrCodeMsgMap = {
    {ERR_INVALID_PARAM, "Invalid input parameter."},
    {ERR_SYSYTEM_ERROR, "System internal error."}
};
}  // namespace Cloud
}  // namespace OHOS
#endif  // OHOS_CLOUD_OAID_COMMON_H