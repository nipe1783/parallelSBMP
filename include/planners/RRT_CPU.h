#pragma once
#include "planners/Planner_CPU.h"

class RRT_CPU : public Planner_CPU
{
    public:
        // constructor
        RRT_CPU() = default;

        // methods
        void plan(const Workspace& workspace, const Agent& agent, const Eigen::Vector2d& goal) override;
};