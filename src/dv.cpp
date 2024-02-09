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

#include "VideoInformation/dv.hpp"

namespace Deltacast
{

uint32_t VideoMasterDvVideoInformation::get_buffer_type()
{
   return VHD_DV_BT_VIDEO;
}

uint32_t VideoMasterDvVideoInformation::get_nb_buffer_types()
{
   return NB_VHD_DV_BUFFERTYPE;
}

uint32_t VideoMasterDvVideoInformation::get_stream_processing_mode()
{
   return VHD_DV_STPROC_DISJOINED_VIDEO;
}

std::vector<uint32_t> VideoMasterDvVideoInformation::get_board_properties(uint32_t channel_index)
{
   return {};
}

// std::unordered_map<Deltacast::VideoFormatProps, uint32_t>
// VideoMasterDvVideoInformation::get_stream_properties()
// {
//    return DV_STREAM_VIDEO_FORMAT;
// }

std::optional<VideoFormat>
VideoMasterDvVideoInformation::get_video_format(Helper::StreamHandle& stream_handle)
{
   ULONG              width, height, framerate;
   BOOL32             interlaced;
   Helper::ApiSuccess api_success;

   api_success = VHD_GetStreamProperty(*stream_handle, VHD_DV_SP_ACTIVE_WIDTH, &width);
   if (!api_success)
   {
      std::cout << "Error getting VHD_DV_SP_ACTIVE_WIDTH (" << api_success << ")" << std::endl;
      return {};
   }

   api_success = VHD_GetStreamProperty(*stream_handle, VHD_DV_SP_ACTIVE_HEIGHT, &height);
   if (!api_success)
   {
      std::cout << "Error getting VHD_DV_SP_ACTIVE_HEIGHT (" << api_success << ")" << std::endl;
      return {};
   }

   api_success = VHD_GetStreamProperty(*stream_handle, VHD_DV_SP_INTERLACED, (ULONG*)&interlaced);
   if (!api_success)
   {
      std::cout << "Error getting VHD_DV_SP_INTERLACED (" << api_success << ")" << std::endl;
      return {};
   }

   api_success = VHD_GetStreamProperty(*stream_handle, VHD_DV_SP_REFRESH_RATE, &framerate);
   if (!api_success)
   {
      std::cout << "Error getting VHD_DV_SP_ACTIVE_WIDTH (" << api_success << ")" << std::endl;
      return {};
   }

   return VideoFormat{ width, height, !interlaced, framerate };
}

std::optional<bool>
VideoMasterDvVideoInformation::update_stream_properties_values(VideoFormat video_format)
{
   stream_properties_values[VHD_DV_SP_ACTIVE_WIDTH] = video_format.width;
   stream_properties_values[VHD_DV_SP_ACTIVE_HEIGHT] = video_format.height;
   stream_properties_values[VHD_DV_SP_INTERLACED] = !video_format.progressive;
   stream_properties_values[VHD_DV_SP_REFRESH_RATE] = video_format.framerate;

   return true;
}

std::optional<Helper::ApiSuccess>
VideoMasterDvVideoInformation::configure_stream(Helper::StreamHandle& stream_handle)
{
   Helper::ApiSuccess api_succes;
   auto vf = get_video_format(stream_handle).value();
   api_succes = VHD_PresetTimingStreamProperties(*stream_handle, VHD_DV_STD_SMPTE, vf.width,
                                                 vf.height, vf.framerate, (ULONG)vf.progressive);

   return api_succes;
}

void VideoMasterDvVideoInformation::print(std::ostream& os) const
{
   os << "DV Signal" << std::endl;
}

std::optional<uint32_t> VideoMasterDvVideoInformation::get_genlock_source_properties()
{
   return { };
}

std::optional<uint32_t> VideoMasterDvVideoInformation::get_genlock_status_properties()
{
   return { };
}
}  // namespace Deltacast