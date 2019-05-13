#pragma once

#include "Figure.h"
#include <string>

class Circle : public Figure {
    public:
        float r;
        Circle();
        Circle(float _r);
        virtual std::string type() const;
        virtual float area() const;
};
