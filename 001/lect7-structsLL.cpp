// Copyright 2021 Casey A Cole
#include <iostream>

struct node {
    int data;
    node *next;
    node *prev;
};

int main(int argc, char **argv) {
    node head;
    node tail;

    head.data = 10;
    tail.data = 100;
    // Let's connect the two
    head.next = &tail;
    tail.next = &head;
    // Now let's walk through manually
    
    // int *i = new int;
    // *i = 10;
    // Add a node
    node middle;
    middle.data = 11;
    middle.next = &tail;
    head.next = &middle;
    std::cout << head.data << "\n";
    std::cout << head.next->data << "\n";
    std::cout << head.next->next->data << "\n";
    node *curr = &head;
    for (int i = 0; i < 3; i++) {
        std::cout << curr->data << "\n";
        curr = curr->next;
    }

    // Question: How would I make this a doubly linked list?

    return 0;
}
