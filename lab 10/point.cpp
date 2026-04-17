#include "point.h"
#include <cmath>

Point::Point(double _x, double _y){
  x = _x;
  y = _y;
}

double Point::getX(){
  return x;
}

void Point::setX(double, _x){
  x = _x
}

double Point::getY(){
  return y;
}

void Point::setY(double, _y){
  y = _y
}

double Point::distance(){
  return sqrt(x*x + y*y);
}
