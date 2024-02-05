cmake_minimum_required(VERSION 3.15)
include(CMakePackageConfigHelpers)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(cmake/version.cmake)
git_version(GIT_VERSION)
set_version(${GIT_VERSION})

project(
    "VideoMasterAPIhelper"
    DESCRIPTION "Object library containing helper classes for the VideoMaster API"
    VERSION     ${PROJECT_VERSION}
    LANGUAGES CXX
)

configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/version.h.in
    ${CMAKE_SOURCE_DIR}/src/version.h
    @ONLY
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(${PROJECT_NAME}_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/api.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/enum_to_string.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/handle_manager.cpp
)

set(${PROJECT_NAME}_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/src/api.hpp
    ${CMAKE_CURRENT_LIST_DIR}/src/api_success.hpp
    ${CMAKE_CURRENT_LIST_DIR}/src/enum_to_string.hpp
    ${CMAKE_CURRENT_LIST_DIR}/src/handle_manager.hpp
    ${CMAKE_CURRENT_LIST_DIR}/src/resource_manager.hpp
    ${CMAKE_SOURCE_DIR}/src/version.h
)


add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
# cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH INCLUDE_PUBLIC_DIR)
# target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_PUBLIC_DIR})

# Looks like we cannot only link the dependency, we have to link the object libray too, not sure why
find_package(VideoMaster REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC VideoMaster::VideoMaster)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/VDMApiConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
 
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
