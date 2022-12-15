#pragma once
#include "Patient.h"

class Node
{
    Patient data;
    Node* next = nullptr;

public:
    Node();
    Node(Patient data);

    void printNode();

    void set_next(Node* next);

    void set_data(Patient data);

    Node* get_next() const;

    Patient get_data() const;
};
