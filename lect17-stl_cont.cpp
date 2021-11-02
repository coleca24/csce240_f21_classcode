// Copyright 2021 Casey A Cole
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using std::cout;

void initVector(vector<int> data);
void printVector(const vector<int> & data);

void init2dVector(vector<vector<int>> data);
void print2dVector(const vector<vector<int>> & data);
vector<int> maxRowsVector(const vector<vector<int>> & data);

int main(int argc, char **argv) {
    // Initialization of vector<type>
    vector<int> vect;
    initVector(vect);
    printVector(vect);
    
    vector<vector<int>> vect2d; 
    init2dVector(vect2d); 
    print2dVector(vect2d); 
    
    vector<int> res = maxRowsVector(vect2d); 
    printVector(res);
    
    // Deques https://www.cplusplus.com/reference/deque/deque/
    
    // Associative containers - Maps, Sets
    
    // Unordered associative containers - Hash sets and maps
    
    // Unordered associative containers - stack, queue priority_queue
    
    
    return 0;
}
