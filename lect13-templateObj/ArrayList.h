
#include <iostream>
using std::ostream;

class ArrayList {
       friend ostream& operator<<(ostream&, ArrayList);
 public:
        ArrayList();  // default
        explicit ArrayList(int size, int val = 0);
        ArrayList(const ArrayList &);
        ~ArrayList();  // destructor

        void print() const;
        int getSize() const;
        int getData(int) const;
        int  operator[](int) const;
        int& operator[](int);
        bool operator==(const ArrayList &) const;
        void operator()(int, int);
        const ArrayList & operator=(const ArrayList &);
        ArrayList operator+(int) const;


 private:
        int *data;
        int size;
        void setSize(int);
};
