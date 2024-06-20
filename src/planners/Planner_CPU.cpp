#include "planners/Planner_CPU.h"
#include <stdio.h>
#include <cstdio>
#include <Eigen/Core>
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include "agent/Agent.h"
#include <random>

Planner_CPU::Planner_CPU(Agent agent, CollisionCheck collisionCheck) {
    agent_ = agent;
    collisionCheck_ = collisionCheck;
}

// Generates random 2D sample in the workspace.
Eigen::Vector2d Planner_CPU::generateRandomSample() {
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_real_distribution<> dis_x(0, workspace_.width_);
    std::uniform_real_distribution<> dis_y(0, workspace_.height_);
    double x = dis_x(gen);
    double y = dis_y(gen);
    return Eigen::Vector2d(x, y);
}