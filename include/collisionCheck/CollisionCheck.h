#pragma once
#include "obstacle/Obstacle.h"
#include "agent/Agent.h"

class CollisionCheck {
    public:
        // Constructors
        CollisionCheck() = default;

        // Methods
        static bool check(const Agent& agent, const Obstacle& obstacle);
        
        // Fields
};