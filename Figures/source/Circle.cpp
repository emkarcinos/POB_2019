#include "../include/Circle.h"
#include <string>

#define PI 3.141592653589793238463

using namespace std;


Circle::Circle(){r=0;}

Circle::Circle(float _r){r=_r;}

string Circle::type() const {
    return "Circle";
}

float Circle::area() const {
    return PI * r * r;
}