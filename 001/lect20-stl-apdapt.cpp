// Copyright 2021 Casey A Cole
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <deque>
#include <queue>
#include <list>

using std::vector;
using std::stack;
using std::deque;
using std::queue;
using std::list;
using std::priority_queue;
using std::string;
using std::cout;
using std::cin;

vector<int> getMaxNElements(vector<int> v, int n) {
    vector<int> res;
    // TODO(in-class): Ideas?
    sort(v.begin(), v.end());
    //  0  1  2  3  4   5
    // [2, 2, 4, 6, 10, 57]
    for(int i = v.size() - 1; i > v.size() - n; i++) {
        res.push_back(v[i]);
    }
    return res;
}

int main(int argc, char **argv) {
    // Solution to Exercise: Can you update this to return the 2 max values?
    vector<int> v{2, 4, 6, 10, 2, 57};
    // vector<int> res = getMaxNElements(v, 2);
    // Adapter #1 - The Stack
    stack<int> s1;
    
    // What do we know about a stack?
    // Last-In First-Out (LIFO)
    // Adding with push
    s1.push(10);
    s1.push(1);
    s1.push(20);
    // <- 20 1 10 |
    // Removing with a pop
    // s1.pop();
    int size = s1.size();
    for (int i = 0; i < size; i++) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << "\n";

    // while(s1.size() != 0) 
    // while(s1.empty() != true)

    // So, what makes this "adaptive"?
    // https://www.cplusplus.com/reference/stack/stack/
    
    // No iterators? So, how would you traverse the stack to print the elements?

    // What tasks would you use a stack for? Or which would you NOT use a stack?

    // What if we want to change the type of container it is adapting?
    stack<int, vector<int> > s2;

    // Apdapter #2 - The Queue

    // What do we know about a queue?
    queue<int> q1;
    // FIFO (First in, First out)
    // https://www.cplusplus.com/reference/queue/queue/

    // Adding elements with a push (enqueue)

    // Removing with a pop (dequeue)

    // Adapter #3 - The Priority Queue
    // https://www.cplusplus.com/reference/queue/priority_queue/
    priority_queue<int> pq;
    priority_queue<int, list<int>, std::greater<int> > pq_max;

    // Bonus - emplace
    
    return 0;
}
