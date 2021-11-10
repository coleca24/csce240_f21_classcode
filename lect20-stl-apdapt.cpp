// Copyright 2021 Casey A Cole
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <deque>
#include <queue>

using std::vector;
using std::stack;
using std::deque;
using std::queue;
using std::priority_queue;
using std::string;
using std::cout;
using std::cin;

int main(int argc, char **argv) {

    // Adapter #1 - The Stack
    stack<int> s1;

    // What do we know about a stack?

    // Adding with push

    // Removing with a pop

    // So, what makes this "adaptive"? 
    // https://www.cplusplus.com/reference/stack/stack/
    
    // No iterators? So, how would you traverse the stack to print the elements?

    // What tasks would you use a stack for? Or which would you NOT use a stack?

    // What if we want to change the type of container it is adapting?
    stack<int, vector<int> > s2;

    // Apdapter #2 - The Queue

    // What do we know about a queue?
    queue<int> q1;

    // https://www.cplusplus.com/reference/queue/queue/

    // Adding elements with a push (enqueue)

    // Removing with a pop (dequeue)

    // Adapter #3 - The Priority Queue
    // https://www.cplusplus.com/reference/queue/priority_queue/priority_queue/

    // Bonus - emplace
    
    return 0;
}
