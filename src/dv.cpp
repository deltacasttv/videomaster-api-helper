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

      std::optional<ApiSuccess> DvVideoInformation::set_video_format(StreamHandle& stream_handle, VideoFormat vf)
      {
         std::unordered_map<uint32_t, uint32_t> stream_properties_values;
         stream_properties_values[VHD_DV_SP_ACTIVE_WIDTH] = vf.width;
         stream_properties_values[VHD_DV_SP_ACTIVE_HEIGHT] = vf.height;
         stream_properties_values[VHD_DV_SP_INTERLACED] = !vf.progressive;
         stream_properties_values[VHD_DV_SP_REFRESH_RATE] = vf.framerate;

         return set_stream_properties_values(stream_handle, stream_properties_values);
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

      std::optional<ApiSuccess> DvVideoInformation::set_stream_properties_values(StreamHandle& stream_handle, std::unordered_map<uint32_t, uint32_t> properties)
      {
         if (properties.find(VHD_DV_SP_ACTIVE_WIDTH) == properties.end() ||
            properties.find(VHD_DV_SP_ACTIVE_HEIGHT) == properties.end() ||
            properties.find(VHD_DV_SP_INTERLACED) == properties.end() ||
            properties.find(VHD_DV_SP_REFRESH_RATE) == properties.end())
         {
            std::cout << "Error setting stream properties, required properties not found in arg" << std::endl;
            return {};
         }

         ApiSuccess api_succes;
         api_succes = VHD_PresetTimingStreamProperties(*stream_handle, VHD_DV_STD_SMPTE,
                                                      properties[VHD_DV_SP_ACTIVE_WIDTH],
                                                      properties[VHD_DV_SP_ACTIVE_HEIGHT],
                                                      properties[VHD_DV_SP_REFRESH_RATE],
                                                      (BOOL)properties[VHD_DV_SP_INTERLACED]);

         return api_succes;
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

      std::unordered_map<uint32_t, uint32_t> DvVideoInformation::get_keyer_properties(BoardHandle& board)
      {
         std::unordered_map<uint32_t, uint32_t> keyer_properties;
         ApiSuccess api_success;
         ULONG value;
         api_success = VHD_GetBoardProperty(*board, VHD_CORE_BP_BOARD_TYPE, &value);
         if (!api_success)
         {
            std::cout << "Error getting board type (" << api_success << ")" << std::endl;
            return {};
         }

         if (value == VHD_BOARDTYPE_MIXEDINTERFACE) {
            // in the case of a mixed interface board the DV keyer is currently the second one
            keyer_properties[VHD_KEYER_BP_INPUT_A] = VHD_KEYER_BP_INPUT_A_1;
            keyer_properties[VHD_KEYER_BP_INPUT_B] = VHD_KEYER_BP_INPUT_B_1;
            keyer_properties[VHD_KEYER_BP_INPUT_K] = VHD_KEYER_BP_INPUT_K_1;
            keyer_properties[VHD_KEYER_BP_ALPHACLIP_MAX] = VHD_KEYER_BP_ALPHACLIP_MAX_1;
            keyer_properties[VHD_KEYER_BP_ALPHACLIP_MIN] = VHD_KEYER_BP_ALPHACLIP_MIN_1;
            keyer_properties[VHD_KEYER_BP_ALPHABLEND_FACTOR] = VHD_KEYER_BP_ALPHABLEND_FACTOR_1;
            keyer_properties[VHD_KEYER_BP_ENABLE] = VHD_KEYER_BP_ENABLE_1;
         } else {
            keyer_properties[VHD_KEYER_BP_INPUT_A] = VHD_KEYER_BP_INPUT_A_0;
            keyer_properties[VHD_KEYER_BP_INPUT_B] = VHD_KEYER_BP_INPUT_B_0;
            keyer_properties[VHD_KEYER_BP_INPUT_K] = VHD_KEYER_BP_INPUT_K_0;
            keyer_properties[VHD_KEYER_BP_ALPHACLIP_MAX] = VHD_KEYER_BP_ALPHACLIP_MAX_0;
            keyer_properties[VHD_KEYER_BP_ALPHACLIP_MIN] = VHD_KEYER_BP_ALPHACLIP_MIN_0;
            keyer_properties[VHD_KEYER_BP_ALPHABLEND_FACTOR] = VHD_KEYER_BP_ALPHABLEND_FACTOR_0;
            keyer_properties[VHD_KEYER_BP_ENABLE] = VHD_KEYER_BP_ENABLE_0;
         }

         return keyer_properties;
      }
   }  // namespace Helper
}  // namespace Deltacast