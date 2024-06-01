cmake_minimum_required(VERSION 3.10)
project(dead_beef VERSION 1.0)


# Compiler options
if(MSVC)
    add_compile_options(/W4 /WX /Zi)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic -g)
endif()

# Debug macro
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Dependencies
find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

# Additional libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/glm)
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/tinyobjloader)
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fastgltf)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.h")

# Main executable
add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
    ${Vulkan_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${Vulkan_LIBRARIES}
    glm::glm
    RenderingEngine
    # Ensure the Vulkan Memory Allocator target name is correct
)

if(MSVC)
    target_compile_options(fastgltf PRIVATE /w)
else()
    target_compile_options(fastgltf PRIVATE -w)
endif()