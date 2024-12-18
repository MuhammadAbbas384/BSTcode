#include"Node.h"
#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main() {
    BinaryTree tree;

    tree.addNode(50, 1);
    tree.addNode(30, 2);
    tree.addNode(70, 3);
    tree.addNode(20, 4);
    tree.addNode(40, 5);
    tree.addNode(60, 6);
    tree.addNode(80, 7);

    tree.displayTree();

    Node* found = tree.findNode(3);
    if (found) 
    {
        cout << "Found: " << found->getValue() << ", ID: " << found->getId() << endl;
    }
    else 
    {
        cout << "Node not found." << endl;
    }

    tree.deleteNode(2);
    tree.displayTree();

    return 0;
}
