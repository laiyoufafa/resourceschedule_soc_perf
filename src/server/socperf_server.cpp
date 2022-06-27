/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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

#include "socperf_server.h"

namespace OHOS {
namespace SOCPERF {
const bool REGISTER_RESULT =
    SystemAbility::MakeAndRegisterAbility(DelayedSingleton<SocPerfServer>::GetInstance().get());

SocPerfServer::SocPerfServer() : SystemAbility(SOC_PERF_SERVICE_SA_ID, true)
{
}

SocPerfServer::~SocPerfServer()
{
}

void SocPerfServer::OnStart()
{
    if (!Publish(DelayedSingleton<SocPerfServer>::GetInstance().get())) {
        SOC_PERF_LOGE("%{public}s, Register SystemAbility for SocPerf FAILED.", __func__);
        return;
    }
    if (!socPerf.Init()) {
        SOC_PERF_LOGE("%{public}s, SocPerf Init FAILED", __func__);
        return;
    }
}

void SocPerfServer::OnStop()
{
}

void SocPerfServer::PerfRequest(int32_t cmdId, const std::string& msg)
{
    socPerf.PerfRequest(cmdId, msg);
}

void SocPerfServer::PerfRequestEx(int32_t cmdId, bool onOffTag, const std::string& msg)
{
    socPerf.PerfRequestEx(cmdId, onOffTag, msg);
}

void SocPerfServer::PowerRequest(int32_t cmdId, const std::string& msg)
{
    socPerf.PowerRequest(cmdId, msg);
}

void SocPerfServer::PowerRequestEx(int32_t cmdId, bool onOffTag, const std::string& msg)
{
    socPerf.PowerRequestEx(cmdId, onOffTag, msg);
}

void SocPerfServer::PowerLimitBoost(bool onOffTag, const std::string& msg)
{
    socPerf.PowerLimitBoost(onOffTag, msg);
}

void SocPerfServer::ThermalRequest(int32_t cmdId, const std::string& msg)
{
    socPerf.ThermalRequest(cmdId, msg);
}

void SocPerfServer::ThermalRequestEx(int32_t cmdId, bool onOffTag, const std::string& msg)
{
    socPerf.ThermalRequestEx(cmdId, onOffTag, msg);
}

void SocPerfServer::ThermalLimitBoost(bool onOffTag, const std::string& msg)
{
    socPerf.ThermalLimitBoost(onOffTag, msg);
}

void SocPerfServer::LimitRequest(int32_t clientId,
    const std::vector<int32_t>& tags, const std::vector<int32_t>& configs, const std::string& msg)
{
    socPerf.LimitRequest(clientId, tags, configs, msg);
}
} // namespace SOCPERF
} // namespace OHOS
