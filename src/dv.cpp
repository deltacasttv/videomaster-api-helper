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

#include "VideoInformation/dv.hpp"

namespace Deltacast
{
   namespace Helper
   {

std::vector<uint32_t> stream_properties_names = {
   VHD_DV_SP_ACTIVE_WIDTH,
   VHD_DV_SP_ACTIVE_HEIGHT,
   VHD_DV_SP_INTERLACED,
   VHD_DV_SP_REFRESH_RATE,
};

uint32_t DvVideoInformation::get_buffer_type()
{
   return VHD_DV_BT_VIDEO;
}

uint32_t DvVideoInformation::get_nb_buffer_types()
{
   return NB_VHD_DV_BUFFERTYPE;
}

uint32_t DvVideoInformation::get_stream_processing_mode()
{
   return VHD_DV_STPROC_DISJOINED_VIDEO;
}

std::vector<uint32_t> DvVideoInformation::get_board_properties(uint32_t channel_index)
{
   return {};
}

std::optional<VideoFormat>
DvVideoInformation::get_video_format(StreamHandle& stream_handle)
{
   ULONG              width, height, framerate;
   BOOL32             interlaced;
   ApiSuccess api_success;

   auto props = get_stream_properties_values(stream_handle);

   if (props.find(VHD_DV_SP_ACTIVE_WIDTH) == props.end() ||
       props.find(VHD_DV_SP_ACTIVE_HEIGHT) == props.end() ||
       props.find(VHD_DV_SP_INTERLACED) == props.end() ||
       props.find(VHD_DV_SP_REFRESH_RATE) == props.end())
      return {};

   return VideoFormat{ props[VHD_DV_SP_ACTIVE_WIDTH],
                       props[VHD_DV_SP_ACTIVE_HEIGHT],
                       !props[VHD_DV_SP_INTERLACED],
                       props[VHD_DV_SP_REFRESH_RATE] };
}

std::optional<ApiSuccess>
DvVideoInformation::configure_stream(StreamHandle& stream_handle)
{
   ApiSuccess api_succes;
   auto               vf = get_video_format(stream_handle).value();
   api_succes = VHD_PresetTimingStreamProperties(*stream_handle, VHD_DV_STD_SMPTE, vf.width,
                                                 vf.height, vf.framerate, (ULONG)vf.progressive);

   return api_succes;
}

void DvVideoInformation::print(std::ostream& os) const
{
   os << "DV";
}

std::unordered_map<uint32_t, uint32_t>
DvVideoInformation::get_stream_properties_values(StreamHandle& stream_handle)
{
   ApiSuccess                     api_success;
   std::unordered_map<uint32_t, uint32_t> stream_props;
   for (auto a : stream_properties_names)
   {
      ULONG value;
      api_success = VHD_GetStreamProperty(*stream_handle, a, &value);
      if (!api_success)
      {
         std::cout << "Error getting stream property (" << api_success << ")" << std::endl;
         return {};
      }
      stream_props[a] = value;
   }
   return stream_props;
}

bool DvVideoInformation::set_stream_properties_values(StreamHandle& stream_handle, std::unordered_map<uint32_t, uint32_t> properties)
{
   if (properties.find(VHD_DV_SP_ACTIVE_WIDTH) == properties.end() ||
       properties.find(VHD_DV_SP_ACTIVE_HEIGHT) == properties.end() ||
       properties.find(VHD_DV_SP_INTERLACED) == properties.end() ||
       properties.find(VHD_DV_SP_REFRESH_RATE) == properties.end())
   {
      std::cout << "Error setting stream properties, required properties not found in arg" << std::endl;
      return false;
   }

   ApiSuccess api_succes;
   api_succes = VHD_PresetTimingStreamProperties(*stream_handle, VHD_DV_STD_SMPTE,
                                                properties[VHD_DV_SP_ACTIVE_WIDTH],
                                                properties[VHD_DV_SP_ACTIVE_HEIGHT],
                                                properties[VHD_DV_SP_REFRESH_RATE],
                                                (BOOL)properties[VHD_DV_SP_INTERLACED]);

   return (bool)api_succes;
}

std::optional<uint32_t> DvVideoInformation::get_sync_source_properties()
{
   return {};
}

std::optional<uint32_t> DvVideoInformation::get_sync_status_properties()
{
   return {};
}

bool DvVideoInformation::configure_sync(BoardHandle& board, uint32_t sync_channel_index)
{
   return true;
}

std::optional<uint32_t> DvVideoInformation::get_sync_tx_properties()
{
   return {};
}

   }  // namespace Helper
}  // namespace Deltacast