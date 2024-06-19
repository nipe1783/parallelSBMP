#include "planners/PlannerCPU.h"
#include <stdio.h>
#include <cstdio>
#include <Eigen/Core>
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include "agent/Agent.h"
#include <random>

// Generates random 2D sample in the workspace.
Eigen::Vector2d PlannerCPU::generateRandomSample() {
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_real_distribution<> dis_x(0, workspace_.width_);
    std::uniform_real_distribution<> dis_y(0, workspace_.height_);
    double x = dis_x(gen);
    double y = dis_y(gen);
    return Eigen::Vector2d(x, y);
}