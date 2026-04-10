// Name: Ashton Shalley
// Email: ashalley2025@my.fit.edu
//
// Purpose: Create an application, “SimpleIO” that performs the following.
//   1. Prompts the user for two integer values (i.e., number1 & number2)
//   2. Displays product of the two numbers as follows
//      Product of number 1 & number 2 is number1*number2
//
// Algorithm:
//   Prompt User for Number 1
//   Get number1
//   Prompt User for Number 2
//   Get number2
//   product = number1 * number2
//   Display product

#include <iostream>

int main()
{
  float number1;
  float number2;

  std::cout << "Enter number 1: ";
  std::cin >> number1;
  std::cout << "Enter number 2: ";
  std::cin >> number2;

  std::cout << "The product of " << number1  << " & " << number2 << " is " << number1 * number2 << std::endl;
}
