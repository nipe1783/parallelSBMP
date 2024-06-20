#include "collisionCheck/CollisionCheck.h"
#include "obstacle/Obstacle.h"
#include "agent/Agent.h"

bool CollisionCheck::check(const Agent& agent, const Obstacle& obstacle) {
    return !(agent.x_ + agent.width_ / 2 < obstacle.x_ - obstacle.width_ / 2 ||  // Agent right edge is left of obstacle left edge
             agent.x_ - agent.width_ / 2 > obstacle.x_ + obstacle.width_ / 2 ||  // Agent left edge is right of obstacle right edge
             agent.y_ + agent.length_ / 2 < obstacle.y_ - obstacle.length_ / 2 || // Agent top edge is below obstacle bottom edge
             agent.y_ - agent.length_ / 2 > obstacle.y_ + obstacle.length_ / 2);  // Agent bottom edge is above obstacle top edge
}