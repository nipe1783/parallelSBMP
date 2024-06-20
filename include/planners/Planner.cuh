#pragma once

#include "agent/Agent.h"
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include <Eigen/Core>
#include "state/State.cuh"

class Planner {
    public:
        // constructor
        Planner() = default;

        // methods
        virtual void plan(const Workspace& workspace, const Agent& agent, const Eigen::Vector2d& goal) = 0;
        std::vector<State> generateRandomSamples(const State &state, int numSamples);
        static __device__ State generateRandomSampleDevice();

        // fields
        Agent agent_;
        Workspace workspace_;
        Eigen::Vector2d goal_;
        std::vector<State> samples_;

};