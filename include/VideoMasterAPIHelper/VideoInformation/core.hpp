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

#include "VideoMasterAPIHelper/handle_manager.hpp"

#include "VideoMasterHD_Core.h"

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Deltacast
{
struct VideoFormat
{
   uint32_t width;
   uint32_t height;
   bool     progressive;
   uint32_t framerate;
};

struct VideoMasterVideoInformation
{
   virtual uint32_t                          get_buffer_type() = 0;
   virtual uint32_t                          get_nb_buffer_types() = 0;
   virtual uint32_t                          get_stream_processing_mode() = 0;
   virtual std::vector<uint32_t>             get_board_properties(uint32_t channel_index) = 0;
   virtual std::optional<VideoFormat>        get_video_format(Helper::StreamHandle& stream_handle) = 0;
   virtual std::optional<bool>               update_stream_properties_values(VideoFormat video_format) = 0;
   virtual std::optional<Helper::ApiSuccess> configure_stream(Helper::StreamHandle&) = 0;
   virtual void                              print(std::ostream& os) const = 0;
   virtual std::optional<uint32_t>           get_genlock_source_properties() = 0;
   virtual std::optional<uint32_t>           get_genlock_status_properties() = 0;

   std::unordered_map<uint32_t, uint32_t> stream_properties_values;
};
}  // namespace Deltacast