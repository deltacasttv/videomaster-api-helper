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

#include "VideoInformation/sdi.hpp"

namespace Deltacast
{
const std::unordered_map<uint32_t, VHD_SDI_BOARDPROPERTY> id_to_rx_video_standard_prop = {
   { 0, VHD_SDI_BP_RX0_STANDARD },   { 1, VHD_SDI_BP_RX1_STANDARD },
   { 2, VHD_SDI_BP_RX2_STANDARD },   { 3, VHD_SDI_BP_RX3_STANDARD },
   { 4, VHD_SDI_BP_RX4_STANDARD },   { 5, VHD_SDI_BP_RX5_STANDARD },
   { 6, VHD_SDI_BP_RX6_STANDARD },   { 7, VHD_SDI_BP_RX7_STANDARD },
   { 8, VHD_SDI_BP_RX8_STANDARD },   { 9, VHD_SDI_BP_RX9_STANDARD },
   { 10, VHD_SDI_BP_RX10_STANDARD }, { 11, VHD_SDI_BP_RX11_STANDARD },
};

const std::unordered_map<uint32_t, VHD_SDI_BOARDPROPERTY> id_to_rx_video_interface_prop = {
   { 0, VHD_SDI_BP_RX0_INTERFACE },   { 1, VHD_SDI_BP_RX1_INTERFACE },
   { 2, VHD_SDI_BP_RX2_INTERFACE },   { 3, VHD_SDI_BP_RX3_INTERFACE },
   { 4, VHD_SDI_BP_RX4_INTERFACE },   { 5, VHD_SDI_BP_RX5_INTERFACE },
   { 6, VHD_SDI_BP_RX6_INTERFACE },   { 7, VHD_SDI_BP_RX7_INTERFACE },
   { 8, VHD_SDI_BP_RX8_INTERFACE },   { 9, VHD_SDI_BP_RX9_INTERFACE },
   { 10, VHD_SDI_BP_RX10_INTERFACE }, { 11, VHD_SDI_BP_RX11_INTERFACE },
};

const std::unordered_map<uint32_t, VHD_SDI_BOARDPROPERTY> id_to_rx_clock_divisor_prop = {
   { 0, VHD_SDI_BP_RX0_CLOCK_DIV },   { 1, VHD_SDI_BP_RX1_CLOCK_DIV },
   { 2, VHD_SDI_BP_RX2_CLOCK_DIV },   { 3, VHD_SDI_BP_RX3_CLOCK_DIV },
   { 4, VHD_SDI_BP_RX4_CLOCK_DIV },   { 5, VHD_SDI_BP_RX5_CLOCK_DIV },
   { 6, VHD_SDI_BP_RX6_CLOCK_DIV },   { 7, VHD_SDI_BP_RX7_CLOCK_DIV },
   { 8, VHD_SDI_BP_RX8_CLOCK_DIV },   { 9, VHD_SDI_BP_RX9_CLOCK_DIV },
   { 10, VHD_SDI_BP_RX10_CLOCK_DIV }, { 11, VHD_SDI_BP_RX11_CLOCK_DIV },
};

const std::unordered_map<VHD_VIDEOSTANDARD, VHD_INTERFACE> default_interfaces = {
   { VHD_VIDEOSTD_S259M_PAL, VHD_INTERFACE_SD_259 },
   { VHD_VIDEOSTD_S259M_NTSC_487, VHD_INTERFACE_SD_259 },
   { VHD_VIDEOSTD_S259M_NTSC_480, VHD_INTERFACE_SD_259 },

   { VHD_VIDEOSTD_S296M_720p_24Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S296M_720p_25Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S296M_720p_30Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S296M_720p_50Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S296M_720p_60Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080i_50Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080i_60Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080p_24Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080p_25Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080p_30Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080psf_24Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080psf_25Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S274M_1080psf_30Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S2048M_2048p_24Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S2048M_2048p_25Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S2048M_2048p_30Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S2048M_2048psf_24Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S2048M_2048psf_25Hz, VHD_INTERFACE_HD_292_1 },
   { VHD_VIDEOSTD_S2048M_2048psf_30Hz, VHD_INTERFACE_HD_292_1 },

   { VHD_VIDEOSTD_S274M_1080p_50Hz, VHD_INTERFACE_3G_A_425_1 },
   { VHD_VIDEOSTD_S274M_1080p_60Hz, VHD_INTERFACE_3G_A_425_1 },
   { VHD_VIDEOSTD_S2048M_2048p_60Hz, VHD_INTERFACE_3G_A_425_1 },
   { VHD_VIDEOSTD_S2048M_2048p_50Hz, VHD_INTERFACE_3G_A_425_1 },
   { VHD_VIDEOSTD_S2048M_2048p_48Hz, VHD_INTERFACE_3G_A_425_1 },

   { VHD_VIDEOSTD_3840x2160p_24Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_3840x2160p_25Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_3840x2160p_30Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_3840x2160psf_24Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_3840x2160psf_25Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_3840x2160psf_30Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_4096x2160p_24Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_4096x2160p_25Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_4096x2160p_30Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_4096x2160psf_24Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_4096x2160psf_25Hz, VHD_INTERFACE_6G_2081_10 },
   { VHD_VIDEOSTD_4096x2160psf_30Hz, VHD_INTERFACE_6G_2081_10 },

   { VHD_VIDEOSTD_3840x2160p_50Hz, VHD_INTERFACE_12G_2082_10 },
   { VHD_VIDEOSTD_3840x2160p_60Hz, VHD_INTERFACE_12G_2082_10 },
   { VHD_VIDEOSTD_4096x2160p_48Hz, VHD_INTERFACE_12G_2082_10 },
   { VHD_VIDEOSTD_4096x2160p_50Hz, VHD_INTERFACE_12G_2082_10 },
   { VHD_VIDEOSTD_4096x2160p_60Hz, VHD_INTERFACE_12G_2082_10 },

   { VHD_VIDEOSTD_7680x4320p_24Hz, VHD_INTERFACE_4X6G_2081_12 },
   { VHD_VIDEOSTD_7680x4320p_25Hz, VHD_INTERFACE_4X6G_2081_12 },
   { VHD_VIDEOSTD_7680x4320p_30Hz, VHD_INTERFACE_4X6G_2081_12 },
   { VHD_VIDEOSTD_8192x4320p_24Hz, VHD_INTERFACE_4X6G_2081_12 },
   { VHD_VIDEOSTD_8192x4320p_25Hz, VHD_INTERFACE_4X6G_2081_12 },
   { VHD_VIDEOSTD_8192x4320p_30Hz, VHD_INTERFACE_4X6G_2081_12 },

   { VHD_VIDEOSTD_7680x4320p_50Hz, VHD_INTERFACE_4X12G_2082_12 },
   { VHD_VIDEOSTD_7680x4320p_60Hz, VHD_INTERFACE_4X12G_2082_12 },
   { VHD_VIDEOSTD_8192x4320p_48Hz, VHD_INTERFACE_4X12G_2082_12 },
   { VHD_VIDEOSTD_8192x4320p_50Hz, VHD_INTERFACE_4X12G_2082_12 },
   { VHD_VIDEOSTD_8192x4320p_60Hz, VHD_INTERFACE_4X12G_2082_12 },
};

uint32_t VideoMasterSdiVideoInformation::get_buffer_type()
{
   return VHD_SDI_BT_VIDEO;
}

uint32_t VideoMasterSdiVideoInformation::get_nb_buffer_types()
{
   return NB_VHD_SDI_BUFFERTYPE;
}

uint32_t VideoMasterSdiVideoInformation::get_stream_processing_mode()
{
   return VHD_SDI_STPROC_DISJOINED_VIDEO;
}

std::vector<uint32_t> VideoMasterSdiVideoInformation::get_board_properties(uint32_t channel_index)
{
   return { (uint32_t)id_to_rx_video_standard_prop.at(channel_index),
            (uint32_t)id_to_rx_video_interface_prop.at(channel_index) };
}

std::optional<VideoFormat>
VideoMasterSdiVideoInformation::get_video_format(Helper::StreamHandle stream_handle)
{
   Helper::ApiSuccess api_success;
   ULONG              width, height, framerate;
   BOOL32             interlaced;

   if (video_standard == NB_VHD_VIDEOSTANDARDS)
   {
      std::cout << "ERROR: Video standard is unknown" << std::endl;
      return {};
   }

   api_success = VHD_GetVideoCharacteristics(video_standard, &width, &height, &interlaced,
                                             &framerate);

   if (!api_success)
   {
      std::cout << "ERROR: Cannot get video characteristics (" << api_success << ")" << std::endl;
      return {};
   }
   return VideoFormat{width, height, !interlaced, framerate};
}

std::optional<bool>
VideoMasterSdiVideoInformation::update_stream_properties_values(VideoFormat video_format)
{
   for (uint32_t video_standard = 0; video_standard < NB_VHD_VIDEOSTANDARDS; video_standard++)
   {
      ULONG              width, height, framerate;
      BOOL32             interlaced;
      Helper::ApiSuccess api_result;
      api_result = VHD_GetVideoCharacteristics((VHD_VIDEOSTANDARD)video_standard, &width, &height,
                                               &interlaced, &framerate);
      if (!api_result)
         return {};

      if (default_interfaces.find((VHD_VIDEOSTANDARD)video_standard) == default_interfaces.end())
         return {};

      if (width == video_format.width && height == video_format.height &&
          interlaced == !video_format.progressive && framerate == video_format.framerate)
      {
         stream_properties_values[VHD_SDI_SP_VIDEO_STANDARD] = video_standard;
         stream_properties_values[VHD_SDI_SP_INTERFACE] = default_interfaces.at(
             (VHD_VIDEOSTANDARD)video_standard);
         return true;
      }
   }

   return {};
}

std::optional<Helper::ApiSuccess>
VideoMasterSdiVideoInformation::configure_stream(Helper::StreamHandle stream_handle)
{
   Helper::ApiSuccess api_succes;
   for (auto& stream_prop : stream_properties_values)
   {
      api_succes = VHD_SetStreamProperty(*stream_handle, stream_prop.first, stream_prop.second);
      if (!api_succes)
         return { api_succes };
   }

   return api_succes;
}

void VideoMasterSdiVideoInformation::detect_incoming_signal_properties(Helper::BoardHandle board,
                                                                       int channel_index)
{
   Helper::ApiSuccess api_success;
   // detecting the incoming signal properties is a SDI only feature/behavior
   if ((id_to_rx_video_standard_prop.find(channel_index) == id_to_rx_video_standard_prop.end()) ||
       (id_to_rx_clock_divisor_prop.find(channel_index) == id_to_rx_clock_divisor_prop.end()) ||
       (id_to_rx_video_interface_prop.find(channel_index) == id_to_rx_video_interface_prop.end()))

      return;

   if (!(api_success = Helper::ApiSuccess{ VHD_GetBoardProperty(
             *board, id_to_rx_video_standard_prop.at(channel_index), (ULONG*)&video_standard) }) ||
       !(api_success = Helper::ApiSuccess{ VHD_GetBoardProperty(
             *board, id_to_rx_clock_divisor_prop.at(channel_index), (ULONG*)&clock_divisor) }) ||
       !(api_success = Helper::ApiSuccess{ VHD_GetBoardProperty(
             *board, id_to_rx_video_interface_prop.at(channel_index), (ULONG*)&interface) }))
   {
      std::cout << "ERROR: Cannot get incoming signal information (" << api_success << ")"
                << std::endl;
   }
}

void VideoMasterSdiVideoInformation::print(std::ostream& os) const
{
   os << "SDI Signal information:" << std::endl;
   os << "\t"
      << "video standard: " << Deltacast::Helper::enum_to_string(video_standard) << std::endl;
   os << "\t"
      << "clock divisor: " << Deltacast::Helper::enum_to_string(clock_divisor) << std::endl;
   os << "\t" << "interface: " << Deltacast::Helper::enum_to_string(interface)
      << std::endl;
}
}  // namespace Deltacast