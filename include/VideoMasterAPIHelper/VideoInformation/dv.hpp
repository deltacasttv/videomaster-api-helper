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

#pragma once

#include "core.hpp"

#include "VideoMasterHD_Dv.h"

namespace Deltacast
{
   namespace Helper
   {

struct DvVideoInformation : public VideoInformation
{
   uint32_t                   get_buffer_type() override;
   uint32_t                   get_nb_buffer_types() override;
   uint32_t                   get_stream_processing_mode() override;
   std::vector<uint32_t>      get_board_properties(uint32_t channel_index) override;
   std::optional<VideoFormat> get_video_format(StreamHandle& stream_handle) override;
   void                       print(std::ostream& os) const;
   std::unordered_map<uint32_t, uint32_t>  get_stream_properties_values(StreamHandle&) override;
   std::optional<ApiSuccess>  set_stream_properties_values(StreamHandle&, std::unordered_map<uint32_t, uint32_t> properties) override;
   std::optional<uint32_t>    get_sync_source_properties() override;
   std::optional<uint32_t>    get_sync_status_properties() override;
   bool                       configure_sync(BoardHandle& board, uint32_t sync_channel_index) override;
   std::optional<uint32_t>    get_sync_tx_properties() override;
};
   }  // namespace Helper
}  // namespace Deltacast