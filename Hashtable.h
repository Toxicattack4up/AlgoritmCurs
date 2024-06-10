#pragma once
#include "Client.h"
#include <stdexcept>

class HashTable 
{
private:
    struct HashNode 
    {
        Client data;
        bool occupied;
        HashNode() : occupied(false) {}
    };

    HashNode* table;
    int capacity;

    int hash1(int key) const;
    int hash2(int key) const;

public:
    HashTable(int size);
    ~HashTable();
    void insert(int key, const Client& client);
    Client search(int key) const;
};