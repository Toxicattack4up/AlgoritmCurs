#pragma once
#include "Client.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class SkipList 
{
    struct Node 
    {
        int key;
        Client data;
        Node** forward;
        Node(int k, const Client& c, int level);
        ~Node();
    };

    int maxLevel;
    float probability;
    Node* header;

    int randomLevel() const;

public:
    SkipList(int maxLevel, float probability);
    ~SkipList();
    void insert(int key, const Client& client);
    Client search(int key) const;
};
