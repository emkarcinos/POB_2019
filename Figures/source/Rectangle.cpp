#include "../include/Rectangle.h"
#include <string>
using namespace std;


Rectangle::Rectangle() : w(0), h(0) {}

Rectangle::Rectangle(float _w, float _h) : w(_w), h(_h) {}

string Rectangle::type() const {
    return "Rectangle";
}

float Rectangle::area() const {
    return w * h;
}