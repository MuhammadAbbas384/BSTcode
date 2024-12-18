#pragma once
#include"Node.h"
using namespace std;

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree();
    void addNode(int, int);
    bool isTreeEmpty();
    void traverseInOrder(Node*);
    void deleteNode(int);
    Node* findNode(int);
    void displayTree();
};