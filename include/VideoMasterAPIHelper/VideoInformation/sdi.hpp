/*
 * Copyright (c) 2022, DELTACAST.TV.
 *
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

#include "core.hpp"

#include "VideoMasterHD_Sdi.h"

namespace Deltacast
{

struct VideoMasterSdiVideoInformation : public VideoMasterVideoInformation
{
   uint32_t                          get_buffer_type() override;
   uint32_t                          get_nb_buffer_types() override;
   uint32_t                          get_stream_processing_mode() override;
   std::vector<uint32_t>             get_board_properties(uint32_t channel_index) override;
   std::optional<VideoFormat>        get_video_format(Helper::StreamHandle& stream_handle) override;
   std::optional<bool>               update_stream_properties_values(VideoFormat video_format) override;
   std::optional<Helper::ApiSuccess> configure_stream(Helper::StreamHandle&) override;
   void                              print(std::ostream& os) const;
   void                              detect_incoming_signal_properties(Helper::BoardHandle& board, int channel_index);
   std::optional<uint32_t>           get_genlock_source_properties() override;

   VHD_VIDEOSTANDARD video_standard = NB_VHD_VIDEOSTANDARDS;
   VHD_CLOCKDIVISOR clock_divisor;
   VHD_INTERFACE interface;
};

std::ostream& operator<<(std::ostream& os, const VideoMasterSdiVideoInformation& v_info)
{
    v_info.print(os);
    return os;
}

}  // namespace Deltacast