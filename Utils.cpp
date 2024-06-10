#include "Utils.h"
#include <iostream>
#include <stdexcept>

TreeNode::TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}

void distributionSort(int* data, int size) 
{
    if (size == 0) return;

    int minValue = data[0];
    int maxValue = data[0];
    for (int i = 1; i < size; i++) 
    {
        if (data[i] < minValue) minValue = data[i];
        if (data[i] > maxValue) maxValue = data[i];
    }
    int range = maxValue - minValue + 1;

    int* count = new int[range];
    for (int i = 0; i < range; i++) 
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) 
    {
        count[data[i] - minValue]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) 
    {
        while (count[i]--) 
        {
            data[index++] = i + minValue;
        }
    }

    delete[] count;
}

int bruteForceSearch(const std::string& text, const std::string& pattern) 
{
    int textLength = static_cast<int>(text.size());
    int patternLength = static_cast<int>(pattern.size());

    for (int i = 0; i <= textLength - patternLength; i++) 
    {
        int j = 0;
        while (j < patternLength && text[i + j] == pattern[j]) 
        {
            j++;
        }
        if (j == patternLength) 
        {
            return i;
        }
    }
    return -1;
}
