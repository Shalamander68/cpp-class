// Name: Ashton Shalley
// Email: ashalley2025@fit.edu
//
// Purpose: Create an application, “NumberCalculations” that calculates
// the sum & average of two positive numbers using the following logic.
//
// Algorithm:
//   Loop
//     Prompt “Please enter the first positive number: ”
//     Get number1
//     Prompt “Please enter the second positive number: ”
//     Get number2
//
//     if ((number1 > 0) && (number2 > 0))
//       tryAgain = false
//     else
//       tryAgain = true
//       Display “Please try again;both numbers must be positive”
//     while tryAgain == true
//
//   Calculates number1 + number2 , stores in sum
//   Calculates sum / 2.0 , stores in avg
//   Displays sum
//   Displays average

#include <iostream>

int main() {
    float number1;
    float number2;

    float sum;
    float avg;

    bool tryAgain;

    do {
        std::cout << "enter first positive number: ";
        std::cin >> number1;
        std::cout << "enter seccond positive number: ";
        std::cin >> number2;

        if ((number1 > 0) && (number2 > 0)) {
            tryAgain = false;
        }
        else {
            tryAgain = true;
            std::cout << "try again, both numbers must be positive" << std::endl;
        }
    } while (tryAgain == true);

    sum = number1 + number2;
    avg = sum / 2.0;

    std::cout << "sum = " << sum << std::endl;
    std::cout << "avg = " << avg << std::endl;
}