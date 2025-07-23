#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>

template <typename T>
class CircularLinkedList {
private:
   
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    Node* current;

public:
    
    CircularLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    
    ~CircularLinkedList() {
        if (!head) return;
        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }

    
    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }

        if (!current) {
            current = head;
        }
    }

    
    T getCurrent() const {
        if (!current) {
            throw std::runtime_error("List is empty.");
        }
        return current->data;
    }

    
    void step() {
        if (current) {
            current = current->next;
        }
    }

    
    void reset() {
        current = head;
    }
};

#endif
