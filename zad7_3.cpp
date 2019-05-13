#include <iostream>

using namespace std;

template <typename type>
class Array {
    private:
        type* basePtr;
        Array(unsigned int n){
            basePtr=(type*)malloc(sizeof(type)*n); //allocate the memory
        }
        ~Array(){
            free(basePtr);
        }
    public:
        Array& operator new [](unsigned int n){
            Array(n);
            return *this;
        }
        void* operator delete [](unsigned int n){
            ~Array();
        }
        type operator[](){
            return 
        }
};
