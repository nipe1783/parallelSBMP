cmake_minimum_required(VERSION 3.5)
project(parallelSBMP LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CUDA_STANDARD 11)

find_package(CUDA REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Python3 COMPONENTS Development NumPy REQUIRED)

include_directories(
    include 
    ${EIGEN3_INCLUDE_DIRS} 
    ${BOOST_INCLUDE_DIRS}  
    ${CMAKE_SOURCE_DIR}/src 
    ${CUDA_INCLUDE_DIRS}
    ${Python3_INCLUDE_DIRS}
    ${Python3_NumPy_INCLUDE_DIRS}
)

# Add the source files for your project
set(SOURCE_FILES
    src/workspace/Workspace.cpp
    src/obstacle/Obstacle.cpp
    src/agent/Agent.cpp
    src/planners/RRT.cu
    src/planners/Planner.cu
    src/planners/Planner_CPU.cpp
    src/collisionCheck/CollisionCheck.cpp
    src/tree/Tree.cpp
    src/treeNode/TreeNode.cpp
    src/state/State.cu
    # Add other source files as needed
)

# Add a library target for your non-CUDA code
add_library(parallelSBMP_lib ${SOURCE_FILES})

# Add your CUDA executable
add_executable(GPU_demo1 demos/demo1.cu)

# Link the library and other dependencies with the CUDA executable
target_link_libraries(GPU_demo1
    parallelSBMP_lib
    ${CUDA_LIBRARIES}
    ${Boost_LIBRARIES}
    ${EIGEN3_LIBRARIES}
    yaml-cpp
    Python3::Python
    Python3::NumPy
)

# Ensure CUDA separable compilation
set_target_properties(GPU_demo1 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

# CPU executable
add_executable(CPU_demo1 demos/CPU_demo1.cpp)

# Link the library and other dependencies with the CUDA executable
target_link_libraries(CPU_demo1
    parallelSBMP_lib
    ${Boost_LIBRARIES}
    ${EIGEN3_LIBRARIES}
    yaml-cpp
    Python3::Python
    Python3::NumPy
)
