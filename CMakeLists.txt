# Not really needed, but intesting to learn. kinda
# Doesn't work with the way i have raylib installed


cmake_minimum_required(VERSION 3.22)

project(AxeGame)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-lraylib -lGL -lm -lpthread -ldl -lrt -lX11")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (include_dir "${PROJECT_SOURCE_DIR}/include/")

file (GLOB source_files "${source_dir}/*.cc")
file (GLOB include_files "${include_dir}/*.h")


add_executable(Axe_Game ${source_files} ${include_files})