# For Unix builds

cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(AxeGame)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
find_package(raylib 4.0.0 QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    # set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
    endif()
    

# Our Project

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # to make sure it compiles with the right cpp version 

set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (include_dir "${PROJECT_SOURCE_DIR}/include/")

file (GLOB src_files "${source_dir}/*.cc")
file (GLOB include_files "${include_dir}/*.h")
add_executable(${PROJECT_NAME} ${src_files} ${include_files})

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

# # Web Configurations
# if (${PLATFORM} STREQUAL "Web")
#     # Tell Emscripten to build an example.html file.
#     set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
# endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()