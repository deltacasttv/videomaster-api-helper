#include "VideoInformation/core.hpp"

std::ostream& operator<<(std::ostream& os, const Deltacast::VideoMasterVideoInformation& v_info)
{
    v_info.print(os);
    return os;
}