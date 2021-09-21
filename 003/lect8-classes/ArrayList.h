#include <iostream>
class ArrayList {
    public:
        
        ArrayList();  // Default
        explicit ArrayList(int size);  // Parameterized
        // ArrayList(char c);
        ArrayList(int[], int);
        // ArrayList(int size, int val = 0);
        // void ArrayList2();
        // ArrayList(int def);
        ~ArrayList();  // Destructor
        void print();
        static void printNumObjects();
        
    private:
        static int numObj;
        int *arr;
        int size;
        const int num;
};
