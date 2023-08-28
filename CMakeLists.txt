cmake_minimum_required(VERSION 3.25)
project(SandSim)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(SandSim main.cpp Application.cpp Application.h ParticleSystem.cpp ParticleSystem.h Behaviour.cpp Behaviour.h)
target_link_libraries(SandSim ${SDL2_LIBRARIES})
