// Copyright 2021 Casey A Cole
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>

using std::set;
using std::multiset;
using std::map;
using std::multimap;
using std::pair;
using std::make_pair;
using std::string;
using std::cout;
using std::cin;

int main(int argc, char **argv) {
    // Associative containers - Maps, Sets
    // https://www.cplusplus.com/reference/set/set/

    set<int> s;
    // set<int, std::greater<int>> s;
    // Inserting elements
    s.insert(60);
    s.insert(1);
    s.insert(11);
    s.insert(3);
    s.insert(5);
    s.insert(4);

    // Notice the order set<int,greater<int>> s;
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it <<" ";
    }
    cout << "\n";

    // Print the size
    cout<< "size:" << s.size() << "\n";

    // What if I try to insert another 5?
    s.insert(5);
    cout<< "size:" << s.size() << "\n";

    // find
    // auto == std::set<int>::iterator
    auto it = s.find(1);

    // if found
    if (it != s.end()) {
        cout << *it << "\n";
    } else {
        cout << "Element was not found\n";
    }

    // Let's remove it
    s.erase(it);
    for (auto i : s) {
        cout << i << " ";
    }
    cout << "\n";

    // We can also remove by sending raw value in:
    s.erase(4);
    for (auto i : s) {
        cout << i << " ";
    }
    cout << "\n";

    // Multisets
    multiset<int> ms;
    ms.insert(2);
    ms.insert(4);
    ms.insert(2);
    ms.insert(2);
    for (int i : ms) {
        cout << i << " ";
    }
    cout << "\n";

    // find? Now there may be elements that are the
    // same and find just returns one element!

    // auto == pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
    auto ret = ms.equal_range(2);
    for (auto it = ret.first; it != ret.second; it++) {
        cout << *it << " ";
    }
    cout << "\n";

    // Now what if we want to erase all of these?
    ms.erase(ret.first, ret.second);
    for (int i : ms) {
        cout << i << " ";
    }
    cout << "\n";

    // Use a set when you want things ordered and non duplicate (no history).
    // Use a multiset when you want ordered and duplicates.
    // Also an unordered set and unordered multiset.

    // https://www.cplusplus.com/reference/map/map
    map<string, int> grades;
    grades.insert(pair<string, int>("Bob", 40));
    grades.insert(pair<string, int>("Jill", 50));
    grades.insert(pair<string, int>("Frank", 20));
    grades.insert(pair<string, int>("Gert", 10));
    // // We can also use make_pair
    grades.insert(make_pair("Pops", 100));

    // auto == map<string, int>::iterator
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        cout << it->first << '\t' << it->second << '\n';
    }
    cout << "\n";

    // // Updating a value for a key:
    auto it2 = grades.find("Pops");

    if (it2 != grades.end()) {
        it2->second = 50;
    }
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        cout << it->first << '\t' << it->second << '\n';
    }
    cout << "\n";
    // OR
    grades["Bob"] = 100;
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        cout << it->first << '\t' << it->second << '\n';
    }
    cout << "\n";
    cout << grades["Bob"] << "\n";

    // Multimap
    multimap<int, char> mm;
    mm.insert(make_pair(1, 'A'));
    mm.insert(make_pair(1, 'B'));
    int numOne = mm.count(1);
    cout << "Num Ones: " << numOne << "\n";
    // Next up: Adaptive containers!
    
    return 0;
}
