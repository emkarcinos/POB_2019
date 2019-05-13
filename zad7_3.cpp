#include <iostream>

using namespace std;

template <typename type>
class Array {
    private:
        type* ptrs;
        Array(){}
        ~Array(){}
    public:
        Array& operator new [](){
            Array();
            return *this;
        }
        void operator delete [](){
            ~Array();
        }

}