#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
using namespace std;

class Triangle {
private:
    string name;
    double xLoc;
    double yLoc;
    double base;
    double height;

public:
    // Constructor
    Triangle(string name, double xLoc, double yLoc, double base, double height);

    // Getters
    string getName()   const;
    double getXLoc()   const;
    double getYLoc()   const;
    double getBase()   const;
    double getHeight() const;

    // Setters
    void setName(string name);
    void setXLoc(double xLoc);
    void setYLoc(double yLoc);
    void setBase(double base);
    void setHeight(double height);

    // Calculated methods
    double hypotenuse() const;
    double perimeter()  const;
    double area()       const;
};

#endif
