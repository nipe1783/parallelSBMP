#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/container/vector.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "state/State.cuh"

class TreeNode : public boost::enable_shared_from_this<TreeNode> {
public:
    State value;
    boost::shared_ptr<TreeNode> parent;
    boost::container::vector<boost::shared_ptr<TreeNode>> children;

    TreeNode(State val);
    void addChild(State val);
};