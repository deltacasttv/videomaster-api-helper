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

#include "VideoInformation/sdi.hpp"

namespace Deltacast
{
   namespace Helper
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

      const std::unordered_map<uint32_t, VHD_SDI_BOARDPROPERTY> id_to_rx_interface_prop = {
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

      uint32_t SdiVideoInformation::get_buffer_type()
      {
         return VHD_SDI_BT_VIDEO;
      }

      uint32_t SdiVideoInformation::get_nb_buffer_types()
      {
         return NB_VHD_SDI_BUFFERTYPE;
      }

      uint32_t SdiVideoInformation::get_stream_processing_mode()
      {
         return VHD_SDI_STPROC_DISJOINED_VIDEO;
      }

      std::vector<uint32_t> SdiVideoInformation::get_board_properties(uint32_t channel_index)
      {
         return { (uint32_t)id_to_rx_video_standard_prop.at(channel_index),
                  (uint32_t)id_to_rx_interface_prop.at(channel_index) };
      }

      std::optional<VideoFormat>
      SdiVideoInformation::get_video_format(StreamHandle& stream_handle)
      {
         ApiSuccess api_success;
         ULONG              width, height, framerate;
         BOOL32             interlaced;

         auto props = get_stream_properties_values(stream_handle);

         if (props.find(VHD_SDI_SP_VIDEO_STANDARD) == props.end())
         {
            std::cout << "ERROR: Video standard not set" << std::endl;
            return {};
         }

         VHD_VIDEOSTANDARD video_standard = (VHD_VIDEOSTANDARD)props.at(
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

      std::optional<ApiSuccess> SdiVideoInformation::set_video_format(StreamHandle& stream_handle, VideoFormat vf)
      {
         ApiSuccess api_success;
         std::unordered_map<uint32_t, uint32_t> stream_properties_values;
         for (uint32_t video_standard = 0; video_standard < NB_VHD_VIDEOSTANDARDS; video_standard++) {
            ULONG width, height, framerate;
            BOOL32 interlaced;
            api_success = VHD_GetVideoCharacteristics((VHD_VIDEOSTANDARD)video_standard,
                                                         &width,
                                                         &height,
                                                         &interlaced,
                                                         &framerate);
         if (!api_success) {
            std::cout << "Could not retrieve video characteristics" << std::endl;
            return api_success;
         }

         if (default_interfaces.find((VHD_VIDEOSTANDARD)video_standard) == default_interfaces.end()) {
            std::cout << "Could not retrieve video characteristics" << std::endl;
            return {};
         }

         if (width == vf.width && height == vf.height
            && interlaced == !vf.progressive && framerate == vf.framerate) {
            stream_properties_values[VHD_SDI_SP_VIDEO_STANDARD] = video_standard;
            stream_properties_values[VHD_SDI_SP_INTERFACE] =
                                       default_interfaces.at((VHD_VIDEOSTANDARD)video_standard);

            return set_stream_properties_values(stream_handle, stream_properties_values);
         }
      }

      return {};
      }

      void SdiVideoInformation::print(std::ostream& os) const
      {
         os << "SDI";
      }

      std::unordered_map<uint32_t, uint32_t>
      SdiVideoInformation::get_stream_properties_values(StreamHandle& stream_handle)
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

      std::optional<ApiSuccess> SdiVideoInformation::set_stream_properties_values(StreamHandle& stream_handle, std::unordered_map<uint32_t, uint32_t> properties)
      {
         if (properties.find(VHD_SDI_SP_VIDEO_STANDARD) == properties.end() ||
            properties.find(VHD_SDI_SP_INTERFACE) == properties.end() ||
            properties.find(VHD_SDI_SP_CLOCK_SYSTEM) == properties.end())
         {
            std::cout << "Error setting stream properties, required properties not found in arg" << std::endl;
            return {};
         }

         ApiSuccess api_success;

         for (auto element : properties)
         {
            ULONG value;
            api_success = VHD_SetStreamProperty(*stream_handle, element.first, element.second);
            if (element.first == VHD_SDI_SP_CLOCK_SYSTEM && !api_success)
               api_success = VHDERR_NOERROR; // Overriding the error for clock system to handle RX cases
            if (!api_success)
            {
               std::cout << "Error setting stream property (" << api_success << ")" << std::endl;
               break;
            }
         }
         return api_success;
      }

      std::optional<uint32_t> SdiVideoInformation::get_sync_source_properties()
      {
         return VHD_SDI_BP_GENLOCK_SOURCE;
      }

      std::optional<uint32_t> SdiVideoInformation::get_sync_status_properties()
      {
         return VHD_SDI_BP_GENLOCK_STATUS;
      }

      bool SdiVideoInformation::configure_sync(BoardHandle& board,
                                                            uint32_t sync_channel_index)
      {
         ULONG video_std, clock_divisor, interface;
         ApiSuccess api_success;
         if (!(api_success = VHD_GetBoardProperty(*board, id_to_rx_video_standard_prop.at(sync_channel_index), &video_std))
            || !(api_success = VHD_GetBoardProperty(*board, id_to_rx_clock_divisor_prop.at(sync_channel_index), &clock_divisor))
            || !(api_success = VHD_GetBoardProperty(*board, id_to_rx_interface_prop.at(sync_channel_index), &interface)))
         {
            std::cout << "ERROR: Cannot get incoming signal information (" << api_success << ")" << std::endl;
            return false;
         }

         if (!(api_success = VHD_SetBoardProperty(*board, get_sync_source_properties().value(),
                                                id_to_rx_genlock_source.at(sync_channel_index))) ||
            !(api_success = VHD_SetBoardProperty(
                  *board, VHD_SDI_BP_GENLOCK_VIDEO_STANDARD, video_std)) ||
            !(api_success = VHD_SetBoardProperty(*board, VHD_SDI_BP_CLOCK_SYSTEM, clock_divisor)))
         {
            std::cout << "ERROR: Cannot configure genlock (" << api_success << ")" << std::endl;
            return false;
         }

         return true;
      }

      std::optional<uint32_t> SdiVideoInformation::get_sync_tx_properties()
      {
         return VHD_SDI_SP_TX_GENLOCK;
      }
   }  // namespace Helper
}  // namespace Deltacast