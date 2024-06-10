#include "HashTable.h"
#include "Client.h"

HashTable::HashTable(int size) : capacity(size) 
{
    if (size <= 0) 
    {
        throw std::invalid_argument("Размер хеш-таблицы должен быть положительным числом");
    }
    table = new HashNode[capacity];
}

HashTable::~HashTable() 
{
    delete[] table;
}

int HashTable::hash1(int key) const 
{
    return key % capacity;
}

int HashTable::hash2(int key) const 
{
    return 1 + (key % (capacity - 1));
}

void HashTable::insert(int key, const Client& client) 
{
    int index = hash1(key);
    int step = hash2(key);

    while (table[index].occupied) 
    {
        index = (index + step) % capacity;
    }

    table[index].data = client;
    table[index].occupied = true;
}

Client HashTable::search(int key) const 
{

    int index = hash1(key);
    int step = hash2(key);

    while (table[index].occupied && table[index].data.getId() != key) 
    {
        index = (index + step) % capacity;
    }

    if (!table[index].occupied) 
    {
        throw std::runtime_error("Ключ не найден");
    }

    return table[index].data;
}
