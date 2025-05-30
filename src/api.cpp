/*
 * SPDX-FileCopyrightText: Copyright (c) DELTACAST.TV. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at * * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "api.hpp"

#include <iostream>

#include "VideoMasterHD_Core.h"
#include "api_success.hpp"

std::string Deltacast::Helper::get_api_version()
{
    return VHD_GetStringVersion();
}

int Deltacast::Helper::get_number_of_devices()
{
    ULONG number_of_devices = 0;
    ApiSuccess api_success{VHD_GetApiInfo(nullptr, &number_of_devices)};
    if (!api_success)
    {
        std::cout << "ERROR: Cannot get number of devices (" << api_success << ")" << std::endl;
        return 0;
    }

    return number_of_devices;
}