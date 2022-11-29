#include <iostream>
#include "Patient.h"

using namespace std;


class Node
{
    Patient data;
    Node* next = nullptr;
    
public:

    static Node* createNode(Patient data) {
        Node* node = new Node;
        node->data = data;
        node->next = nullptr;
        return node;
    }

    void printNode(Node* node) {
        cout << node->data << endl;
    }
    void set_next(Node* next) {
        this->next = next;
    }
    void set_data(Patient data) {
        this->data = data;
    }
    Node* get_next() const {
        return next;
    }

    Patient get_data() const {
        return data;
    }
};


class Vector {
    Node* head = new Node;
    Node* tail = new Node;

public:
    Node* get_tail() const {
        return tail;
    }

    Node* get_head() const {
        return head;
    }

    Patient get_node_data(int index) {
        Node* node = head->get_next();
        for (int i = 0; i < index; i++) {
            node = node->get_next();
        }
        return node->get_data();
    }

    void push_front(Patient data) {
        Node* node = Node::createNode(data);

        if (!head->get_next()) {
            head->set_next(node);
            tail->set_next(node);
        }
        else {
            Node* tmp = head->get_next();
            head->set_next(node);
            node->set_next(tmp);
        }
    }

    void push_back(Patient data) {
        Node* node = Node::createNode(data);
        if (!head->get_next()) {
            head->set_next(node);
        }
        else {
            Node* tmp = new Node;
            tmp = head->get_next();
            while (tmp->get_next())
            {
                tmp = tmp->get_next();
            }
            tmp->set_next(node);
        }
        tail->set_next(node);
    }

    void pop_front() const {
        if (head->get_next()) {
            Node* tmp = head->get_next()->get_next();
            head->set_next(tmp);
          
        }
    }

    void pop_back() {
        if (head->get_next()) {
            Node* tmp = head->get_next();
            while (tmp->get_next()->get_next())
            {
                tmp = tmp->get_next();
            }
            tmp->set_next(nullptr);
            tail->set_next(tmp);
        }
    }

    void insert(Patient data, int index) {
        Node* node = new Node;
        node->set_data(data);
        int flag = 1;
        Node* node2 = head;
        for (int i = 0; i < index; i++) {
            if (!node2->get_next()) {
                cout << "invalid input size!" << endl;
                flag = 0;
                break;
            }
            node2 = node2->get_next();
        }
        if (flag) {
            Node* tmp = node2->get_next();
            node2->set_next(node);
            node->set_next(tmp);
        }
    }

    void remove(int index) {
        int flag = 1;
        Node* node = head;
        Node* prev = node;
        for (int i = 0; i <= index; i++) {
            if (!node->get_next()) {
                cout << "invalid input size!" << endl;
                flag = 0;
                break;
            }
            prev = node;
            node = node->get_next();
        }
        if (flag) {
            prev->set_next(node->get_next());
            delete node;
        }
    }

    int search(Patient data) {
        int result = -1, index = 0;
        Node* node = head;
        while (node->get_next())
        {
            if (node->get_next()->get_data() == data) {
                result = index;
                break;
            }
            node = node->get_next();
            index++;
        }
        return result;
    }


    void print() {
        if (head->get_next()) {
            Node* node = head;
            while (node->get_next())
            {
                cout << node->get_next()->get_data() << ' ';
                node = node->get_next();
            }
            cout << endl;
        }
    }

    int length() {
        Node* node = new Node;
        node = head;
        int num = 0;
        while (node->get_next())
        {
            num++;
            node = node->get_next();
        }
        return num;
    }

    void clear() {
        Node* node = head;
        Node* next = node;
        while (node->get_next())
        {
            next = node->get_next();
            delete node;
            node = next;
        }
        head->set_next(nullptr);
        delete next;
    }

};


int main() {
    
    return 0;
}