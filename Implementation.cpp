#include"BinaryTree.h"
using namespace std;

Node::Node() 
{
    value = 0;
    id = 0;
    right = NULL;
    left = NULL;
}

Node::Node(int value, int id) 
{
    this->value = value;
    this->id = id;
    right = NULL;
    left = NULL;
}

void Node::setValue(int value) 
{
    this->value = value;
}

void Node::setId(int id) 
{
    this->id = id;
}

void Node::setRight(Node* right) 
{
    this->right = right;
}

void Node::setLeft(Node* left) 
{
    this->left = left;
}

int Node::getValue() 
{
    return value;
}

int Node::getId() 
{
    return id;
}

Node* Node::getRight() 
{
    return right;
}

Node* Node::getLeft() 
{
    return left;
}

BinaryTree::BinaryTree() 
{
    root = NULL;
}

bool BinaryTree::isTreeEmpty() 
{
    return root == NULL;
}

void BinaryTree::addNode(int value, int id)
{
    Node* newNode = new Node(value, id);
    if (isTreeEmpty()) 
    {
        root = newNode;
    }
    else 
    {
        Node* temp = root;
        Node* parent = NULL;

        while (temp != NULL) 
        {
            parent = temp;
            if (id == temp->getId()) 
            {
                return;
            }
            else if (id < temp->getId()) 
            {
                temp = temp->getLeft();
            }
            else 
            {
                temp = temp->getRight();
            }
        }

        if (id < parent->getId()) 
        {
            parent->setLeft(newNode);
        }
        else 
        {
            parent->setRight(newNode);
        }
    }
}

Node* BinaryTree::findNode(int id) 
{
    Node* temp = root;
    while (temp != NULL) 
    {
        if (id == temp->getId()) 
        {
            return temp;
        }
        else if (id < temp->getId()) 
        {
            temp = temp->getLeft();
        }
        else 
        {
            temp = temp->getRight();
        }
    }
    return NULL;
}

void BinaryTree::traverseInOrder(Node* node) 
{
    if (node == NULL) return;
    traverseInOrder(node->getLeft());
    cout << node->getId() << endl;
    traverseInOrder(node->getRight());
}

void BinaryTree::deleteNode(int id) 
{
    Node* temp = root;
    Node* parent = NULL;

    while (temp != NULL && temp->getId() != id) 
    {
        parent = temp;
        if (id < temp->getId()) 
        {
            temp = temp->getLeft();
        }
        else 
        {
            temp = temp->getRight();
        }
    }

    if (temp == NULL) return;

    if (temp->getLeft() == NULL && temp->getRight() == NULL) 
    {
        if (parent == NULL) 
        {
            root = NULL;
        }
        else if (parent->getLeft() == temp) 
        {
            parent->setLeft(NULL);
        }
        else 
        {
            parent->setRight(NULL);
        }
        delete temp;
    }
    else if (temp->getLeft() == NULL) 
    {
        Node* child = temp->getRight();
        if (parent == NULL) 
        {
            root = child;
        }
        else if (parent->getLeft() == temp) 
        {
            parent->setLeft(child);
        }
        else 
        {
            parent->setRight(child);
        }
        delete temp;
    }
    else if (temp->getRight() == NULL) 
    {
        Node* child = temp->getLeft();
        if (parent == NULL) 
        {
            root = child;
        }
        else if (parent->getLeft() == temp) 
        {
            parent->setLeft(child);
        }
        else 
        {
            parent->setRight(child);
        }
        delete temp;
    }
    else 
    {
        Node* successorParent = temp;
        Node* successor = temp->getRight();
        while (successor->getLeft() != NULL) 
        {
            successorParent = successor;
            successor = successor->getLeft();
        }

        temp->setId(successor->getId());
        temp->setValue(successor->getValue());

        if (successorParent == temp) 
        {
            temp->setRight(successor->getRight());
        }
        else 
        {
            successorParent->setLeft(successor->getRight());
        }
        delete successor;
    }
}

void BinaryTree::displayTree() 
{
    traverseInOrder(root);
}