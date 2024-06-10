#include "TreeUtils.h"
#include <iostream>
#include "Utils.h"

void preorderTraversal(TreeNode* node) 
{
    if (node == nullptr) return;

    std::cout << node->key << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
 