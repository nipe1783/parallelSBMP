#pragma once

#include "agent/Agent.h"
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include <Eigen/Core>

class PlannerCPU {
    public:
        // constructor
        PlannerCPU() = default;

        // methods
        virtual void plan(const Workspace& workspace, const Agent& agent, const Eigen::Vector2d& goal) = 0;
        Eigen::Vector2d generateRandomSample();

        // fields
        Agent agent_;
        Workspace workspace_;
        Eigen::Vector2d goal_;
        std::vector<Eigen::Vector2d> samples_;

};