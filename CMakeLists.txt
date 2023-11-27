cmake_minimum_required(VERSION 3.26)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_CXX_STANDARD 20)

project(n0va VERSION 0.0.0)

if (WIN32)
    string(REGEX REPLACE "\\\\" "/" VULKAN_PATH $ENV{VULKAN_SDK})
    message("Setting up project for x64-Windows!")
    list(APPEND CMAKE_PREFIX_PATH "$ENV{VCPKG_HOME}/installed/x64-windows/lib"
    "${VULKAN_PATH}/Lib")

    include_directories("$ENV{VCPKG_HOME}/installed/x64-windows/include"
    "${VULKAN_PATH}/Include"
    "External/glfw3/include")

elseif (UNIX AND NOT APPLE)
    message("Setting up project for x64-Linux!")
    list(APPEND CMAKE_PREFIX_PATH "$ENV{VCPKG_HOME}/packages/glfw3_x64-linux/bin"
            "$ENV{VULKAN_SDK}/Lib")

    include_directories("$ENV{VCPKG_HOME}/installed/x64-linux/include")

endif ()

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_directories(${PROJECT_NAME} PRIVATE "External/glfw3/lib-vc2022"
"$ENV{VULKAN_SDK}/Lib"
"$ENV{VCPKG_HOME}/installed/x64-windows/lib")

target_link_libraries(${PROJECT_NAME} glfw3 vulkan-1)