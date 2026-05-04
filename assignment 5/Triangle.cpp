#include "Triangle.h"
#include <cmath>
using namespace std;

// Constructor
Triangle::Triangle(string name, double xLoc, double yLoc, double base, double height) {
    this->name   = name;
    this->xLoc   = xLoc;
    this->yLoc   = yLoc;
    this->base   = base;
    this->height = height;
}

// --- Getters ---
string Triangle::getName()   const { return name;   }
double Triangle::getXLoc()   const { return xLoc;   }
double Triangle::getYLoc()   const { return yLoc;   }
double Triangle::getBase()   const { return base;   }
double Triangle::getHeight() const { return height; }

// --- Setters ---
void Triangle::setName(string name)     { this->name   = name;   }
void Triangle::setXLoc(double xLoc)     { this->xLoc   = xLoc;   }
void Triangle::setYLoc(double yLoc)     { this->yLoc   = yLoc;   }
void Triangle::setBase(double base)     { this->base   = base;   }
void Triangle::setHeight(double height) { this->height = height; }

// --- Calculated Methods ---

// Hypotenuse: sqrt(base^2 + height^2)
double Triangle::hypotenuse() const {
    return sqrt((base * base) + (height * height));
}

// Perimeter: base + height + hypotenuse
double Triangle::perimeter() const {
    return base + height + hypotenuse();
}

// Area: 0.5 * base * height
double Triangle::area() const {
    return 0.5 * base * height;
}
