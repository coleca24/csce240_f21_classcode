
#include <iostream>

class ArrayList {
 public:
        ArrayList();  // default
        // explicit ArrayList(int size);
        explicit ArrayList(int size, int val = 0);
        ArrayList(const ArrayList &);

        void print() const;
        ~ArrayList();  // destructor
        static int getNumAL();
        int getSize() const;
        // [1,2,3,4,5] -> insert(1,5) -> [1,5,2,3,4,5]
        bool insert(int, int);
        // [1,2,3,4,5] -> remove(1) -> [1,3,4,5]
        bool remove(int);
        int operator[](int);
 private:
        int *data;
        int size;
        static int numAL;
        const float pi;
        const float e;
        void setSize(int);
};
