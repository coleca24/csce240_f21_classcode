
#include <iostream>

class ArrayList {
 public:
        ArrayList();  // default
        // explicit ArrayList(int size);
        explicit ArrayList(int size, int val = 0);
        ArrayList(const ArrayList &);
        void print();
        ~ArrayList();  // destructor
        static int getNumAL();
 private:
        int *data;
        int size;
        static int numAL;
        const float pi;
        const float e;
};
