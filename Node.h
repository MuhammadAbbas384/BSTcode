#pragma once
#include<iostream>
using namespace std;

class Node {
private:
    int value;
    int id;
    Node* right;
    Node* left;

public:
    Node();
    Node(int, int);
    void setValue(int);
    void setId(int);
    void setRight(Node*);
    void setLeft(Node*);
    int getValue();
    int getId();
    Node* getRight();
    Node* getLeft();
};
