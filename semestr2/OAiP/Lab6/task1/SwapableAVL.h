#include "AVLTree.h"
#pragma once
class SwapableAVL: public AVLTree
{
public:
    void swapValuesOfMinMaxKeys()
    {
        if(!root) return;
        std::shared_ptr<Node> minNode = root;
        while(minNode->left) minNode = minNode->left;
        std::shared_ptr<Node> maxNode = root;
        while(maxNode->right) maxNode = maxNode->right;
        if(minNode && maxNode) std::swap(minNode->value, maxNode->value);
    }
};
