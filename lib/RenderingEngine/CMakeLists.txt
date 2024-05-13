cmake_minimum_required(VERSION 3.10)

# Define the library
project(RenderingEngine)

# Create the library target
add_library(RenderingEngine STATIC
    src/Renderer.cpp
    src/Utility.cpp
    src/Logger.cpp
    third_party/vk-bootstrap/src/VkBootstrap.cpp
)

message(STATUS "Building Lib: VMA")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/VulkanMemoryAllocator)
message(STATUS "Building Lib: VkBootstrap")
set_directory_properties(PROPERTIES DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/third_party/vk-bootstrap
                       COMPILE_OPTIONS "-w")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/vk-bootstrap)

# Specify the include directories for the library
target_include_directories(RenderingEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/vk-bootstrap/src
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/VulkanMemoryAllocator/include
)
