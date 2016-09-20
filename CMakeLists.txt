cmake_minimum_required(VERSION 3.6)
project(TheParticleFireSimulation)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${TheParticleFireSimulation_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${CaveStory_SOURCE_DIR}/source/headers)

set(SOURCE_FILES main.cpp Screen.h Particle.h Swarm.h)
add_executable(TheParticleFireSimulation ${SOURCE_FILES})

target_link_libraries(TheParticleFireSimulation ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY})