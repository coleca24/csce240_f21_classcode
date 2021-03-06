
#include <iostream>

class ArrayList {
 public:
       friend std::ostream& operator<<(std::ostream &, ArrayList);
       // friend istream& operator>>(istream &, ArrayList);
        ArrayList();  // default
        explicit ArrayList(int size, int val = 0);
        ArrayList(const ArrayList &);
        ~ArrayList();  // destructor

        void print() const;
        int getSize() const;
        int getData(int) const;
        // [1,2,3,4,5] -> insert(1,5) -> [1,5,2,3,4,5]
        bool insert(int, int);
        // [1,2,3,4,5] -> remove(1) -> [1,3,4,5]
        bool remove(int);

        // Operators
        int operator[](int) const;
        int& operator[](int);
        bool operator==(const ArrayList &) const;
        void operator()(int, int);
       //  void operator()(int, int, int);
       ArrayList & operator=(const ArrayList &);

       // Todo(lecture 12)
        // operator++ (pre and post) - Think about what it should return
       ArrayList & operator++();  // pre
       ArrayList operator++(int);  // post
        // operator+(ArrayList) - pairwise
        // operator+(int) - append
        // friends

 private:
        int *data;
        int size;
        void setSize(int);
};
