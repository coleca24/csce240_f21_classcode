// Copyright 2021 Casey A Cole
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <set>
#include <map>

using std::vector;
using std::list;
using std::set;
using std::map;
using std::pair;
using std::string;
using std::cout;
using std::cin;

void initVector(vector<int> data);
void printVector(const vector<int> & data);
int maxVector(const vector<int> & data);

void init2dVector(vector<vector<int>> data);
void print2dVector(const vector<vector<int>> & data);
vector<int> maxRowsVector(const vector<vector<int>> & data);

int main(int argc, char **argv) {
    // Initialization of vector<type>
    vector<int> vect;
    initVector(vect);
    printVector(vect);
    int max = maxVector(vect);
    
    vector<vector<int>> vect2d;
    init2dVector(vect2d);
    print2dVector(vect2d);
    
    vector<int> res = maxRowsVector(vect2d);
    printVector(res);
    // Exercise: Can you update this to return the 2 max values?
    {
        // Deques https://www.cplusplus.com/reference/deque/deque/
    
    // Associative containers - Maps, Sets
    // https://www.cplusplus.com/reference/set/set/

    // set <int> s;
  
    // // Inserting elements
    // s.insert(60);
    // s.insert(1);
    // s.insert(11);
    // s.insert(3);
    // s.insert(5);
    // s.insert(4);

    // // Notice the order set<int,greater<int>> s;
    // for (auto it = s.begin() ; it != s.end() ; it++) {
    //     cout << *it <<" ";
    // }
    // cout << "\n";

    // // Print the size
    // cout<< "size:" << s.size() << "\n";

    // // What if I try to insert another 5?
    // s.insert(5); 
    // cout<< "size:" << s.size() << "\n";

    // https://www.cplusplus.com/reference/map/map
    // map<string, int> grades;
    // grades.insert(pair<string, int>("Bob", 40));
    // grades.insert(pair<string, int>("Jill", 50));
    // grades.insert(pair<string, int>("Frank", 20));
    // grades.insert(pair<string, int>("Gert", 10));
    // // We can also use make_pair
    // grades.insert(std::make_pair("Pops", 100));

    // // auto == map<string, int>::iterator
    // for (auto it = grades.begin(); it != grades.end(); ++it) {
    //     cout << it->first << '\t' << it->second << '\n';
    // }
    // cout << "\n";

    // // Updating a value for a key:
    // auto it = grades.find("Pops");
    // if (it != grades.end()) {
    //     it->second = 50;
    // }
    // for (auto it = grades.begin(); it != grades.end(); ++it) {
    //     cout << it->first << '\t' << it->second << '\n';
    // }
    // cout << "\n";
    // Next up: Adaptive containers!
    }
    
    
    return 0;
}

void initVector(vector<int> data) {

}

void printVector(const vector<int> & data) {

}

int maxVector(const vector<int> & data) {
    return -1;
}

void init2dVector(vector<vector<int>> data) {

}

void print2dVector(const vector<vector<int>> & data) {

}

vector<int> maxRowsVector(const vector<vector<int>> & data) {
    vector<int> ret; 

    return ret;
}