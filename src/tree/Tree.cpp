#include "tree/Tree.h"

Tree::Tree(State rootValue) {
    root = boost::make_shared<TreeNode>(rootValue);
}

void Tree::addNode(State value, boost::shared_ptr<TreeNode> parent) {
    if (parent) {
        parent->addChild(value);
    }
}

void Tree::printTree(boost::shared_ptr<TreeNode> node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << "State(x: " << node->value.x_ << ", y: " << node->value.y_
              << ", theta: " << node->value.theta_ << ", v: " << node->value.v_
              << ", length: " << node->value.length_ << ")" << std::endl;

    for (const auto& child : node->children) {
        printTree(child, depth + 1);
    }
}