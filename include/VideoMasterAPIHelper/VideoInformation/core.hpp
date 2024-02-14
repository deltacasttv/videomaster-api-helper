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

#pragma once

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

   bool operator!=(const VideoFormat& other) const
   {
      return (width != other.width) || (height != other.height) ||
             (progressive != other.progressive) || (framerate != other.framerate);
   }

   friend std::ostream& operator<<(std::ostream& os, const VideoFormat& video_format)
   {
      os << "\t" << "Width: " << video_format.width << std::endl;
      os << "\t" << "Height: " << video_format.height << std::endl;
      os << "\t" << "Progressive: " << video_format.progressive << std::endl;
      os << "\t" << "Framerate: " << video_format.framerate << std::endl;
      return os;
   }

};

struct VideoMasterVideoInformation
{
   virtual uint32_t                   get_buffer_type() = 0;
   virtual uint32_t                   get_nb_buffer_types() = 0;
   virtual uint32_t                   get_stream_processing_mode() = 0;
   virtual std::vector<uint32_t>      get_board_properties(uint32_t channel_index) = 0;
   virtual std::optional<VideoFormat> get_video_format(Helper::StreamHandle& stream_handle) = 0;
   virtual std::optional<Helper::ApiSuccess> configure_stream(Helper::StreamHandle&) = 0;
   virtual std::unordered_map<uint32_t, uint32_t>
                                   get_stream_properties_values(Helper::StreamHandle&) = 0;
   virtual void                    print(std::ostream& os) const = 0;
   virtual std::optional<uint32_t> get_genlock_source_properties() = 0;
   virtual std::optional<uint32_t> get_genlock_status_properties() = 0;
   virtual bool configure_genlock(Helper::BoardHandle& board, uint32_t genlock_channel_index) = 0;
   virtual std::optional<uint32_t> get_genlock_tx_properties() = 0;
};
}  // namespace Deltacast

std::ostream& operator<<(std::ostream& os, const Deltacast::VideoMasterVideoInformation& v_info);