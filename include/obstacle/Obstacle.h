#pragma once

#include <vector>
#include <Eigen/Core>

class Obstacle {
    public:
        // constructor
        Obstacle() = default;
        Obstacle(std::vector<Eigen::Vector2d>& verticesCCW);
        Obstacle(float x, float y, float length);

        // methods

        // fields
        std::vector<Eigen::Vector2d> verticesCCW_;
        float x_;       // Position x
        float y_;       // Position y
        float length_;  // Length
        float width_;   // Width
        
};