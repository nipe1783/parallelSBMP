#pragma once

#include "treeNode/TreeNode.h"
#include <iostream>

class Tree {
public:
    boost::shared_ptr<TreeNode> root;

    Tree(State rootValue);
    void addNode(State value, boost::shared_ptr<TreeNode> parent);
    void printTree(boost::shared_ptr<TreeNode> node, int depth = 0);
};
