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

void initVector(vector<int> & data);
void printVector(const vector<int> & data);
int maxVector(const vector<int> & data);

void init2dVector(vector<vector<int>> & data);
void print2dVector(const vector<vector<int>> & data);
vector<int> maxRowsVector(const vector<vector<int>> & data);

int main(int argc, char **argv) {
    // Initialization of vector<type>
    // vector<int> vect(5);
    // initVector(vect);
    // printVector(vect);
    // int max = maxVector(vect);
    // cout << "Max: " << max << "\n";
    
    vector<vector<int>> vect2d;
    vector<int> row;
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    vect2d.push_back(row);
    vect2d.push_back(row);
    print2dVector(vect2d);
    init2dVector(vect2d);
    print2dVector(vect2d);
    vector<int> res = maxRowsVector(vect2d);
    printVector(res);
    // Exercise: Can you update this to return the 2 max values?
        // Deques https://www.cplusplus.com/reference/deque/deque/
    
    // Associative containers - Maps, Sets
    // https://www.cplusplus.com/reference/set/set/

    set <int> s;
  
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
    map<string, int> grades;
    grades.insert(pair<string, int>("Bob", 40));
    grades.insert(pair<string, int>("Jill", 50));
    grades.insert(pair<string, int>("Frank", 20));
    grades.insert(pair<string, int>("Gert", 10));
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
    
    
    return 0;
}

void initVector(vector<int> & data) {
    int val = 0;
    for (int i = 0; i < data.size(); i++) {
        cout << "Enter val for " << i << "\n";
        cin >> val;
        data[i] = val;
    }
}

void printVector(const vector<int> & data) {
    for (int i : data) {
        cout << i << " ";
    }
    cout << "\n";
}

int maxVector(const vector<int> & data) {
    int max = data[0];
    for (auto i = data.begin()+1; i != data.end(); i++) {
        if (*i > max) {
            max = *i;
        }
    }
    return max;
}

void init2dVector(vector<vector<int>> & data) {
    int val;
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            cin >> val;
            data[i][j] = val;
        }
    }
}

void print2dVector(const vector<vector<int>> & data) {
    for (vector<int> row : data) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

vector<int> maxRowsVector(const vector<vector<int>> & data) {
    vector<int> ret;
    int max = 0;
    for (vector<int> row : data) {
        max = maxVector(row);
        ret.push_back(max);
    }
    return ret;
}