
#include <iostream>

using std::ostream;
using std::istream;

// template <class T>
class ArrayList {
       friend ostream& operator<<(ostream &, ArrayList);
       friend istream& operator>>(istream &, ArrayList);

 public:
        ArrayList();  // default
        explicit ArrayList(int size, int val = 0);
        ArrayList(const ArrayList &);
        ~ArrayList();  // destructor

        void print() const;
        int getSize() const;
        int getData(int) const;
        bool insert(int, int);
        bool remove(int);

        // Operators
        int operator[](int) const;
        int& operator[](int);
        bool operator==(const ArrayList &) const;
        void operator()(int, int);
        const ArrayList & operator=(const ArrayList &);
        ArrayList operator+(int) const;
        // Todo(lecture 12)
        // operator++ (pre and post) - Think about what it should return
        ArrayList operator++();  // pre
        ArrayList operator++(int);  // post
        // operator+(ArrayList) - pairwise
        // operator+(int) - append
        // friends

 private:
       //  T *data;
       int *data;
        int size;
        void setSize(int);
};
