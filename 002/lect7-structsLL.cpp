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
    head.next = &tail;
    tail.next = &head;
    // Now let's walk through manually
    

    node middle;
    middle.data = 11;
    middle.next = &tail;  // 1
    head.next = &middle;  // 2
    std::cout << head.data << "\n";
    std::cout << head.next->data << "\n";
    std::cout << head.next->next->data << "\n";
    node *temp;
    temp = &head;
    for (int i = 0; i < 3; i++) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    // int *pt;
    // int i = 0;
    // pt = &i;
    // *pt;
    // Question: How would I make this a doubly linked list?

    return 0;
}
