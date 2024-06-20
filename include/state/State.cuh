#pragma once
#include <vector>
#include <Eigen/Core>

// kinematic bicycle model:
class State {
    public:
        // Constructors
        __host__ __device__ State() : x_(0.0f), y_(0.0f), theta_(0.0f), v_(0.0f), a_(0.0f), u_(0.0f), dt_(0.0f) {};
        __host__ __device__ State(float x, float y, float theta = 0.0f, float v = 0.0f, float a_ = 0.0f, float u = 0.0f, float dt = 0.0f)
            : x_(x), y_(y), theta_(theta), v_(v), a_(a_), u_(u), dt_(dt) {}

        // Fields
        float x_;       // Position x
        float y_;       // Position y
        float theta_;   // Orientation
        float v_;       // Velocity
        float a_;       // acceleration
        float u_;       // Steering angle
        float dt_;      // Time step
};