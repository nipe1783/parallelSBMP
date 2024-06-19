#include <iostream>
#include "agent/Agent.h"
#include "obstacle/Obstacle.h"
#include "workspace/Workspace.h"
#include "agent/Agent.h"
#include "planners/RRT.h"
#include <cuda_runtime.h>
#include <stdio.h>
#include <cstdio>
#include <Eigen/Core>


int main(void){

    // Obstacle o = Obstacle();
    // o.verticesCCW.push_back(Eigen::Vector2d(0, 0));
    // o.verticesCCW.push_back(Eigen::Vector2d(1, 0));
    // o.verticesCCW.push_back(Eigen::Vector2d(1, 1));
    // o.verticesCCW.push_back(Eigen::Vector2d(0, 1));
    // std::cout<<"TEST"<<std::endl;
    Workspace w = Workspace(10,10);
    Obstacle o1 = Obstacle(5,5,1);
    Obstacle o2 = Obstacle(2,2,1);
    Obstacle o3 = Obstacle(8,8,1);
    w.obstacles_.push_back(o1);
    w.obstacles_.push_back(o2);
    w.obstacles_.push_back(o3);

    Agent a = Agent(1,1,.01);

    RRT r = RRT();
    r.plan(w,a,Eigen::Vector2d(9,9));

    printf("TEST2\n");
    return 0;
}