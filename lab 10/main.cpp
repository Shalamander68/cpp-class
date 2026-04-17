/* Email: sbjohnso@fit.edu
Purpose: Create an application, “PointApp”(i.e., “.cpp” file)
that uses a class “Point”(with both Class Definition [i.e., “.h” file]
& Member Function Definition [i.e., “.cpp”] ).
Algorithm:
  “PointApp” performs the following.
    1. Creates a “Point” object
    2. Changes both the X and Y components’
    3. Retrieves and displays both the X and Y components
    4. Displays the point’s distance from the origin
  Upload all files in “zip” format to the Canvas “Lab 10
  Submission” area.
*/

#include <iostream>
#include "point.h"

int main(){
  Point myPoint(3.1, 5.2);
  
  myPoint.setX(7.9);
  myPoint.setY(4.1);

  std::cout << "X Cordinate = " << myPoint.getX() << std::endl;
  std::cout << "Y Cordinate = " << myPoint.getX() << std::endl;
  std::cout << "Distance from orign (i.e. 0,0) = " << myPoint.distance() << std::endl;
}