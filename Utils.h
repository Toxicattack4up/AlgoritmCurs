#pragma once
#include <string>

struct TreeNode 
{
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k);
};

void distributionSort(int* data, int size);
int bruteForceSearch(const std::string& text, const std::string& pattern);