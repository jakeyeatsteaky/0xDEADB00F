cmake_minimum_required(VERSION 3.10)

# Define the library
project(RenderingEngine)

if(MSVC)
    set(SDL2_DIR "C:/SDL2")
    list(APPEND CMAKE_PREFIX_PATH "${SDL2_DIR}")
endif()

find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

# Create the library target
# Specify all source and header files
set(SOURCES
    src/Renderer.cpp
    src/Utility.cpp
    src/Logger.cpp
    third_party/vk-bootstrap/src/VkBootstrap.cpp
)

set(HEADERS
    include/Renderer.hpp
    include/Utility.hpp
    include/Logger.hpp
    third_party/vk-bootstrap/src/VkBootstrap.h
    # Add other header files as needed
)

# Create the library target
add_library(RenderingEngine STATIC ${SOURCES} ${HEADERS})

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
    ${CMAKE_CURRENT_SOURCE_DIR}/../app/include
    ${SDL2_INCLUDE_DIRS}
    ${Vulkan_INCLUDE_DIRS}
)

# Link SDL2 and Vulkan libraries
target_link_libraries(RenderingEngine PUBLIC
    ${SDL2_LIBRARIES}
    ${Vulkan_LIBRARIES}
)
