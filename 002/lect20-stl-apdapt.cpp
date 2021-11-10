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
    // vector<int> res(n);
    vector<int> res;
    sort(v.begin(), v.end());
    res.push_back(v[v.size()-1]);
    res.push_back(v[v.size()-2]);
    // TODO(in-class): Ideas?
    // int max = v[0];
    // vector<int>::iterator max_i;
    // for (auto it = v.begin(); it != v.end(); it++) {
    //     if (*it > max) {
    //         max = *it;
    //         max_i = it;
    //     }
    // }
    // res.push_back(max);
    // v.erase(max_i);

    return res;
}

int main(int argc, char **argv) {
    // Solution to Exercise: Can you update this to return the 2 max values?
    vector<int> v{2, 4, 6, 10, 2, 57};
    vector<int> res = getMaxNElements(v, 2);
    // Adapter #1 - The Stack
    stack<int> s1;

    // What do we know about a stack?

    // Adding with push
    s1.push(10);
    // Removing with a pop
    s1.pop();
    // So, what makes this "adaptive"? 
    // https://www.cplusplus.com/reference/stack/stack/
    
    // No iterators? So, how would you traverse 
    // the stack to print the elements?
    for(int i = 0; i < s1.size(); i++) {
        cout << s1.top() << " ";
        s1.pop();
    }

    // set<int> s2 = s1;

    // What tasks would you use a stack for?
    // Or which would you NOT use a stack?

    // What if we want to change the type of
    // container it is adapting?
    stack<int, vector<int> > s2;

    // Apdapter #2 - The Queue
    // What do we know about a queue?
    queue<int> q1;
    // https://www.cplusplus.com/reference/queue/queue/

    // Adding elements with a push (enqueue)

    // Removing with a pop (dequeue)

    // Adapter #3 - The Priority Queue
    // https://www.cplusplus.com/reference/queue/priority_queue/priority_queue/
    priority_queue<int> pq;
    

    // Bonus - emplace
    
    return 0;
}
