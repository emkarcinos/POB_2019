#pragma once

#include <string>

class Figure {
    public:
        virtual std::string type() const = 0;
        virtual float area() const = 0;
};