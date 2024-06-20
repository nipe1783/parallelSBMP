#pragma once

#include "agent/Agent.h"
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include "collisionCheck/CollisionCheck.h"
#include <Eigen/Core>

class Planner_CPU {
    public:
        // constructor
        Planner_CPU() = default;
        Planner_CPU(Agent agent, CollisionCheck collisionCheck);

        // methods
        virtual void plan(const Workspace& workspace, const Agent& agent, const Eigen::Vector2d& goal) = 0;
        Eigen::Vector2d generateRandomSample();

        // fields
        Agent agent_;
        Workspace workspace_;
        CollisionCheck collisionCheck_;
        Eigen::Vector2d goal_;
        std::vector<Eigen::Vector2d> samples_;

};