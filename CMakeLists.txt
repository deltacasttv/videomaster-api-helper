cmake_minimum_required(VERSION 3.15)

include(cmake/version.cmake)
git_version(GIT_VERSION)
set_version(${GIT_VERSION})

project(
    "VideoMasterAPIHelper"
    DESCRIPTION "Static library containing helper classes for the VideoMaster API"
    VERSION     ${PROJECT_VERSION}
    LANGUAGES CXX
)

add_subdirectory("src")