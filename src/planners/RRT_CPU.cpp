#include "planners/RRT_CPU.h"
#include <stdio.h>
#include <cstdio>
#include <Eigen/Core>
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include "agent/Agent.h"
#include <iostream>

void RRT_CPU::plan(const Workspace& workspace, const Agent& agent, const Eigen::Vector2d& goal) {
    std::cout<<"RRT_CPU::plan()"<<std::endl;
    workspace_ = workspace;
    agent_ = agent;
    goal_ = goal;
}
