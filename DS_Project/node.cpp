#include <iostream>
#include "node.h"

using namespace std;

Node::Node() {
    this->next = nullptr;
}

Node::Node(Patient data)
{
    this->data = data;
    this->next = nullptr;
}

//Node* Node::createNode(Patient data)
//{
//    Node* node = new Node;
//    node->data = data;
//    node->next = nullptr;
//    return node;
//}

//void Node::printNode(Node* node)
//{
//    cout << node->data << endl;
//}

void Node::printNode()
{
    cout << this->data.getCareCard() << " - Patient: " << this->data.getName() << ", " << this->data.getAddress() << ", " <<
        this->data.getPhone() << ", " << this->data.getEmail() << "\n";
}

void Node::set_next(Node* next)
{
    this->next = next;
}

void Node::set_data(Patient data)
{
    this->data = data;
}

Node* Node::get_next() const
{
    return next;
}

Patient Node::get_data() const
{
    return data;
}
