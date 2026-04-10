// Name: Ashton Shalley
// Email: ashalley2025@fit.edu
//
// Purpose: Create an application, "SimpleFunction" that uses
// a function that receives two integer arguments
// and returns an integer result. The application
// performs as follows.
// Algorithm:
// 1. Defines and declare a function, SumFunction that
// contains two integer formal parameters and returns
// an integer value
// 2. The main function performs the following
// a. Prompts the user for number1 value
// b. Stores the value in number1
// c. Prompts the user for number2 value
// d. Stores the value in number2
// e. Calls the SumFunction passing number1 & number2
// as actual parameters
// f. Stores the result of the call in total
// g. Display the total

#include <iostream>

// Helper function to sum 2 numbers
int SumFunction(int a, int b) {
    return a + b;
}

int main() {
    int number1, number2, total;

    std::cout << "Enter the first number: ";
    std::cin >> number1;

    std::cout << "Enter the second number: ";
    std::cin >> number2;

    total = SumFunction(number1, number2);

    std::cout << "The total is: " << total << std::endl;

    return 0;
}