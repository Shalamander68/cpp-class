#pragma once
class Point
{
  private:
    double x;
    double y;

  public:
    Point(double _x, double _y);

    double getX();
    void setX(double, _x);

    double getY();
    void setY(double, _y);

    double distance();
};