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

vector<int> getMaxNElements(vector<int> v, int n) {
    vector<int> res;
    int max = 0;
    sort(v.begin(), v.end());
    for (auto it = v.end(); it != v.end()-n; it--) {
        res.push_back(*it);
    }
    // TODO(in-class): Ideas?
    // while (n > 0) {
    //     for (int i: res){
    //         if (i > max) {
    //             max = i;
    //             res.push_back(max);
    //             // erase element
    //         }

    //     }
    //     n--;
    // }
    
    return res;
}

int main(int argc, char **argv) {
    // Solution to Exercise: Can you update this to return the 2 max values?
    vector<int> v{2, 4, 6, 10, 2, 57};
    vector<int> res = getMaxNElements(v, 2);

    // Adapter #1 - The Stack
    stack<int> s1;

    // What do we know about a stack?
    // Last-in, First-Out (LIFO)
    // int i = 0; 

    // Adding with push
    s1.push(10);
    s1.push(1);

    // Removing with a pop

    // So, what makes this "adaptive"? 
    // https://www.cplusplus.com/reference/stack/stack/
    
    // No iterators? So, how would you traverse the stack to print the elements?
    int size = s1.size();
    for (int i = 0; i < size; i++) {
        cout << s1.top() << " ";
        s1.pop();
    }
    while (s1.size() != 0) {
        cout << s1.top() << " ";
        s1.pop();
    }
    // What tasks would you use a stack for? Or which would you NOT use a stack?

    // What if we want to change the type of container it is adapting?
    stack<int, vector<int> > s2;

    // Apdapter #2 - The Queue

    // What do we know about a queue?
    // FIFO
    queue<int> q1;

    // https://www.cplusplus.com/reference/queue/queue/

    // Adding elements with a push (enqueue)

    // Removing with a pop (dequeue)

    // Adapter #3 - The Priority Queue
    // https://www.cplusplus.com/reference/queue/priority_queue/priority_queue/
    priority_queue<int, vector<int>, std::greater<int>> p_queue;
    p_queue.push(10);
    p_queue.push(100);

    // Bonus - emplace
    
    return 0;
}
