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
const std::unordered_map<uint32_t, VHD_GENLOCKSOURCE> id_to_rx_genlock_source = {
   { 0, VHD_GENLOCK_RX0 }, { 1, VHD_GENLOCK_RX1 },   { 2, VHD_GENLOCK_RX2 },
   { 3, VHD_GENLOCK_RX3 }, { 4, VHD_GENLOCK_RX4 },   { 5, VHD_GENLOCK_RX5 },
   { 6, VHD_GENLOCK_RX6 }, { 7, VHD_GENLOCK_RX7 },   { 8, VHD_GENLOCK_RX8 },
   { 9, VHD_GENLOCK_RX9 }, { 10, VHD_GENLOCK_RX10 }, { 11, VHD_GENLOCK_RX11 },
};

const std::vector<uint32_t> stream_properties_names = { VHD_SDI_SP_VIDEO_STANDARD,
                                                        VHD_SDI_SP_INTERFACE,
                                                        VHD_SDI_SP_CLOCK_SYSTEM };

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
VideoMasterSdiVideoInformation::get_video_format(Helper::StreamHandle& stream_handle)
{
   Helper::ApiSuccess api_success;
   ULONG              width, height, framerate;
   BOOL32             interlaced;

   if (stream_properties_values.find(VHD_SDI_SP_VIDEO_STANDARD) == stream_properties_values.end())
   {
      std::cout << "ERROR: Video standard not set" << std::endl;
      return {};
   }

   VHD_VIDEOSTANDARD video_standard = (VHD_VIDEOSTANDARD)stream_properties_values.at(
       VHD_SDI_SP_VIDEO_STANDARD);

   api_success = VHD_GetVideoCharacteristics(video_standard, &width, &height, &interlaced,
                                             &framerate);

   if (!api_success)
   {
      std::cout << "ERROR: Cannot get video characteristics (" << api_success << ")" << std::endl;
      return {};
   }
   return VideoFormat{ width, height, !interlaced, framerate };
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
VideoMasterSdiVideoInformation::configure_stream(Helper::StreamHandle& stream_handle)
{
   Helper::ApiSuccess api_success;
   for (auto& stream_prop : stream_properties_values)
   {
      api_success = VHD_SetStreamProperty(*stream_handle, stream_prop.first, stream_prop.second);
   }

   return api_success;
}

void VideoMasterSdiVideoInformation::print(std::ostream& os) const
{
   os << "SDI";
}

std::unordered_map<uint32_t, uint32_t>
VideoMasterSdiVideoInformation::get_stream_properties_values(Helper::StreamHandle& stream_handle)
{
   Helper::ApiSuccess                     api_success;
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
      // cache those values for get_video_format()
      stream_properties_values[a] = value;
   }
   return stream_props;
}

std::optional<uint32_t> VideoMasterSdiVideoInformation::get_genlock_source_properties()
{
   return VHD_SDI_BP_GENLOCK_SOURCE;
}

std::optional<uint32_t> VideoMasterSdiVideoInformation::get_genlock_status_properties()
{
   return VHD_SDI_BP_GENLOCK_STATUS;
}

bool VideoMasterSdiVideoInformation::configure_genlock(Helper::BoardHandle& board,
                                                  uint32_t             genlock_channel_index)
{
   if (stream_properties_values.find(VHD_SDI_SP_VIDEO_STANDARD) == stream_properties_values.end())
   {
      std::cout << "ERROR: Video standard not set" << std::endl;
      return false;
   }

   if (stream_properties_values.find(VHD_SDI_SP_CLOCK_SYSTEM) == stream_properties_values.end())
   {
      std::cout << "ERROR: Clock divisor not set" << std::endl;
      return false;
   }

   Helper::ApiSuccess api_success;
   if (!(api_success = VHD_SetBoardProperty(*board, get_genlock_source_properties().value(),
                                            id_to_rx_genlock_source.at(genlock_channel_index))) ||
       !(api_success = VHD_SetBoardProperty(
             *board, VHD_SDI_BP_GENLOCK_VIDEO_STANDARD, stream_properties_values[VHD_SDI_SP_VIDEO_STANDARD])) ||
       !(api_success = VHD_SetBoardProperty(*board, VHD_SDI_BP_CLOCK_SYSTEM, stream_properties_values[VHD_SDI_SP_CLOCK_SYSTEM])))
   {
      std::cout << "ERROR: Cannot configure genlock (" << api_success << ")" << std::endl;
      return false;
   }

   return true;
}

std::optional<uint32_t> VideoMasterSdiVideoInformation::get_genlock_tx_properties()
{
   return VHD_SDI_SP_TX_GENLOCK;
}

}  // namespace Deltacast

std::ostream& operator<<(std::ostream& os, const Deltacast::VideoMasterSdiVideoInformation& v_info)
{
    v_info.print(os);
    return os;
}