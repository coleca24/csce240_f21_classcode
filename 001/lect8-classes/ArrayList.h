
#include <iostream>

class ArrayList {
 public:
        static int numObjs;
        ArrayList();  // Default
        // explicit ArrayList(int);  // Alt. Constructor
        explicit ArrayList(int size, int val = 0);  // Alt. Constructor
        ArrayList(const ArrayList&);
        ~ArrayList();  // Destructor
        int getSize() const;
        void print() const;
        // [1, 2, 3] -> insert(1, 5) -> [1, 5, 2, 3]
        void insert(int index, int value);
 private:
        int *data;
        int size;
        const float pi, e;
        void setSize(int); // obj.setSize(5)
       //  void setData(int index, int value);
    // void print();
		
};
