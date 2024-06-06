#include "Skiplist.h"

SkipList::Node::Node(int k, const Client& c, int level) : key(k), data(c) {
    forward = new Node * [level + 1];
    for (int i = 0; i <= level; i++) {
        forward[i] = nullptr;
    }
}

SkipList::Node::~Node() {
    delete[] forward;
}

SkipList::SkipList(int maxLevel, float probability) : maxLevel(maxLevel), probability(probability) {
    if (maxLevel <= 0 || probability <= 0 || probability >= 1) {
        throw std::invalid_argument("Недопустимые параметры для SkipList");
    }
    header = new Node(-1, Client(), maxLevel);
    srand(static_cast<unsigned int>(time(0)));
}

SkipList::~SkipList() {
    Node* current = header;
    while (current) {
        Node* next = current->forward[0];
        delete current;
        current = next;
    }
}

int SkipList::randomLevel() const {
    int level = 0;
    while (level < maxLevel && (rand() % 100) < (probability * 100)) {
        level++;
    }
    return level;
}

void SkipList::insert(int key, const Client& client) {
    Node** update = new Node*[maxLevel + 1];
    Node* current = header;

    for (int i = maxLevel; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];
    if (current == nullptr || current->key != key) {
        int level = randomLevel();
        Node* newNode = new Node(key, client, level);

        for (int i = 0; i <= level; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

Client SkipList::search(int key) const {
    Node* current = header;
    for (int i = maxLevel; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];

    if (current && current->key == key) {
        return current->data;
    }
    else {
        throw std::runtime_error("Ключ не найден");
    }
}
