
#include <iostream>

class ArrayList {
 public:
        static int numObjs;
        ArrayList();  // Default
        // explicit ArrayList(int);  // Alt. Constructor
        explicit ArrayList(int size, int val = 0);  // Alt. Constructor
        ~ArrayList();  // Destructor

        void print();
 private:
        int *data;
        int size;
    // void print();
		
};
