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
        ArrayList(const ArrayList &);  // Copy Constructor
        ~ArrayList();  // Destructor
        void print() const;
        static void printNumObjects();
        // Getters
        int getSize() const;
        int getData(int) const;
        // Set element
        void setData(int, int);
        // [1, 2, 3] -> insert(1, 4) -> [1, 4, 2, 3]
        void insert(int index, int value);
    private:
        static int numObj;
        int *arr;
        int size;
        const int num;
        const float pi;
        void setSize(int);
};
