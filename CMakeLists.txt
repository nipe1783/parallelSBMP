cmake_minimum_required(VERSION 3.18)
project(CudaCMakeExample LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CUDA_STANDARD 11)

find_package(CUDA REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)
find_package(yaml-cpp REQUIRED)

include_directories(${CUDA_INCLUDE_DIRS})

add_executable(vectorAdd vectorAdd.cu)
set_target_properties(vectorAdd PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
