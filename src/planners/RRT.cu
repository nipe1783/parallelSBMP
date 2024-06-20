#include "planners/RRT.h"
#include <cuda_runtime.h>
#include <stdio.h>
#include <cstdio>
#include <Eigen/Core>
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include "agent/Agent.h"

void RRT::plan(const Workspace& workspace, const Agent& agent, const Eigen::Vector2d& goal){
    int numSamples = 100;
    State state(0.0f, 0.0f);
    for (int i = 0; i < 100; i++){
        std::vector<State> samples = generateRandomSamples(state, numSamples);
        printf("Number of samples: %d\n", samples.size());
    }
    
}