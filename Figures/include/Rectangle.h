#pragma once

#include "Figure.h"
#include <string>

class Rectangle : public Figure {
    public:
        float w,h;
        Rectangle();
        Rectangle(float _w, float _h);
        virtual std::string type() const;
        virtual float area() const;
};