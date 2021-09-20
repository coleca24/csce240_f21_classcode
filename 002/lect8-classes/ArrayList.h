
#include <iostream>

class ArrayList {
    public:
        ArrayList();  // default
        ArrayList(int size);
        ~ArrayList();  // destructor
    private:
        int *data;
        int size;
};
