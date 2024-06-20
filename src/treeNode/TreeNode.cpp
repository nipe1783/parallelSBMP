#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/container/vector.hpp>
#include "treeNode/TreeNode.h"

TreeNode::TreeNode(State val) : value(val), parent(nullptr) {}

void TreeNode::addChild(State val) {
    boost::shared_ptr<TreeNode> child = boost::make_shared<TreeNode>(val);
    child->parent = shared_from_this();
    children.push_back(child);
}