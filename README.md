# videomaster-api-helper

Helper classes and functions for accessing and developing on top of the VideoMaster SDK

# How to use as a dependency

You can easily use this library with cmake:

```
# your project declaration 
# ...

FetchContent_Declare(
    VideoMasterAPIHelper
    GIT_REPOSITORY  https://github.com/deltacasttv/videomaster-api-helper.git
    SOURCE_DIR      "${CMAKE_SOURCE_DIR}/deps/api_helper"
)

FetchContent_MakeAvailable(VideoMasterAPIHelper)
target_link_libraries(${PROJECT_NAME} PRIVATE VideoMasterAPIHelper)
```

This library needs the VideoMaster SDK; if the project using this helper does not link to VideoMaster, you can place the SDK in the `deps/VideoMaster` folder and use the provided `FindVideoMaster.cmake` in the cmake folder (`CMAKE_MODULE_PATH=cmake`).

# Code snippets

Using ApiSuccess:

```cpp
#include "VideoMasterAPIHelper/api_success.hpp"

...

Deltacast::Helper::ApiSuccess api_success;
if (!(api_success = VHD_SetStreamProperty(*handle(), VHD_CORE_SP_TRANSFER_SCHEME, VHD_TRANSFER_SLAVED))
    || !(api_success = VHD_SetStreamProperty(*handle(), VHD_SDI_SP_VIDEO_STANDARD, signal_info.video_standard))
    || !(api_success = VHD_SetStreamProperty(*handle(), VHD_SDI_SP_INTERFACE, signal_info.interface)))
{
    // Print the error name and error code
    std::cout << "ERROR for " << _name << ": Cannot configure stream (" << api_success << ")" << std::endl;
}

...

```

Using HandleManager:

```cpp
#include "VideoMasterAPIHelper/handle_manager.hpp"
#include "VideoMasterHD_Core.h"

// device.hpp
class Device
{
private:
    Device() = delete;
    Device(const Device&) = delete;
    Device& operator=(const Device&) = delete;

    Device(int device_index, std::unique_ptr<Helper::BoardHandle> device_handle)
        : _device_index(device_index)
        , _device_handle(std::move(device_handle))
    {
    }

public:
    static std::unique_ptr<Device> create(int device_index);

    int& index() { return _device_index; }
    Helper::BoardHandle& handle() { return *_device_handle; }

private:
    int _device_index;
    std::unique_ptr<Helper::BoardHandle> _device_handle;
};

// device.cpp
std::unique_ptr<Deltacast::Device> Deltacast::Device::create(int device_index)
{
    auto device_handle = Helper::get_board_handle(device_index);
    if (!device_handle)
        return nullptr;
    
    return std::unique_ptr<Device>(new Device(device_index, std::move(device_handle)));
}

// main.cpp
#include "device.hpp"
#include <iostream>

int main() {
    int device_id = 0;

    std::cout << "Opening device " << device_id << std::endl;
    auto device = Deltacast::Device::create(device_id);
    if (!device) {
        std::cout << "Error opening the device " << device_id << std::endl;
        return -1;
    }

    return 0;
}

// the board handle underlaying object is freed when the device object goes out of scope
```

Use can see more examples in projects using this library:

https://github.com/deltacasttv/overlay-from-live-content

https://github.com/deltacasttv/videomaster-input-viewer