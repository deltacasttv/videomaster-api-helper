cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/../cmake/version.h.in
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/version.h
    @ONLY
)

set(${PROJECT_NAME}_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/api.cpp
    ${CMAKE_CURRENT_LIST_DIR}/enum_to_string.cpp
    ${CMAKE_CURRENT_LIST_DIR}/handle_manager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/VideoMasterInformationCore.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sdi.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dv.cpp
)

set(${PROJECT_NAME}_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/api.hpp
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/api_success.hpp
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/enum_to_string.hpp
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/handle_manager.hpp
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/resource_manager.hpp
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/version.h
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/VideoInformation/core.hpp
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/VideoInformation/dv.hpp
    ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME}/VideoInformation/sdi.hpp
)


add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/../include)

find_package(VideoMaster REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC VideoMaster::VideoMaster)