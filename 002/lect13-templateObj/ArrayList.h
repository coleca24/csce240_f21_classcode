
#include <iostream>
using std::ostream;

template <class T>
class ArrayList {
       template <class U>
       friend ostream& operator<<(ostream&, ArrayList<U>);
 public:
        ArrayList();  // default
        explicit ArrayList(int size, T val = 0);
        ArrayList(const ArrayList &);
        ~ArrayList();  // destructor

        void print() const;
        int getSize() const;
        T getData(int) const;
        T operator[](int) const;
        T& operator[](int);
        bool operator==(const ArrayList<T> &) const;
        void operator()(int, T);
        const ArrayList<T> & operator=(const ArrayList<T> &);
        ArrayList<T> operator+(T) const;


 private:
        T *data;
        int size;
        void setSize(int);
};
