// Ashton Shalley
// ashalley2025@fit.edu
//
// Write an application (including algorithm/pseudocode) that modifies the
// application created for Assignment 2 by performing the following.
//
// - Create a void function, “displayMenu”, for the menu that is used for
//   selecting the options. The function declaration is below.
//   o void displayMenu();
//
// - Create a function “SquareRootFunction”. The function body contains all
//   code for getting user input and returning the value of the call of the
//   predefined “sqrt” library function. The function declaration is below.
//   o double SquareRootFunction();
//
// - Create a function “BinaryLogFunction”. The function body contains all code
//   for getting user input and returning the value of the call of the
//   predefined “log2” library function. The function declaration is below.
//   o double BinaryLogFunction();
//
// - Create a function “PowerFunction”. The function body contains all code for
//   getting user input and returning the value of the call of the predefined
//   “pow” library function. The function declaration is below.
//   o double PowerFunction();
//
// - Create a function “AbsoluteValueFunction”. The function body contains all
//   code for getting user input and returning the value of the call of the
//   predefined “abs” library function. The function declaration is below.
//   o double AbsoluteValueFunction();
//
// The “main” function of the application must display the menu and prompt the user
// for the choice to call the appropriate function based on the switch logic, in
// lieu of the original code used in the Assignment 2 application. The “main”
// function should only have one local variable, representing the choice of the
// function that will be called (i.e., no other local variable is declared in
// “main”).
//
// Notes:
//   1. The application must demonstrate the 3 requirements for functions
//     • Function Declaration
//     • Function Definition
//     • Function Call
//   2. Within each function definition, must declare all variables required for
//      getting input for calling the predefined function. The predefined
//      function call must be used in a “return” statement (e.g., “return sqrt(x)”). 
//      This will return the results of the call back to “main” which will
//      then display that result.

#include <iostream>
#include <cmath>

int main () {
  // color codes
  const std::string GRAY  = "\033[90m";
  const std::string RED   = "\033[31m";
  const std::string WHITE = "\033[97m";
  const std::string RESET = "\033[0m";

  int    choice;
  double result   = 0;
  double num      = 0;
  double base     = 0;
  double exponent = 0;

  do {
    std::cout << std::endl
              << GRAY  << "----------------------------------------------" << RESET << std::endl
              << WHITE << "           Basic Calculator Program           " << RESET << std::endl
              << GRAY  << "----------------------------------------------" << RESET << std::endl << std::endl
              << "\t 1) Calculate Square Root"           << std::endl
              << "\t 2) Calculate Binary Logarithm"      << std::endl
              << "\t 3) Calculate Power"                 << std::endl
              << "\t 4) Calculate Absolute Value"        << std::endl
              << "\t 5) Exit"                            << std::endl << std::endl
              << "Enter your selection: ";

    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();             // clear the error flag
      std::cin.ignore(10000, '\n'); // discard the buffer
      choice = 0;                   // set choice to an invalid value to trigger the error message
    }

    switch (choice) {
      case 1: // sqrt
        std::cout << "Enter a positive number: ";
        std::cin >> num;

        result = sqrt(num);

        std::cout << "sqrt(" << WHITE << num << RESET << ") = "
                  << WHITE << result << RESET << std::endl;
        break;

      case 2: // Binary Logarithm
        std::cout << "Enter a positive number: ";
        std::cin >> num;

        result = log2(num);

        std::cout << "log2(" << WHITE << num << RESET << ") = "
                  << WHITE << result << RESET << std::endl;
        break;

      case 3: // exponents
        std::cout << "Enter the base: ";
        std::cin >> base;
        std::cout << "Enter the exponent: ";
        std::cin >> exponent;

        result = pow(base, exponent);

        std::cout << "pow(" << WHITE << base << RESET << ", "
                  << WHITE << exponent << RESET << ") = "
                  << WHITE << result << RESET << std::endl;
        break;

      case 4: // abs
        std::cout << "Enter a number: ";
        std::cin >> num;

        result = std::abs(num);

        std::cout << "abs(" << WHITE << num << RESET << ") = "
                  << WHITE << result << RESET << std::endl;
        break;

      case 5: // Quit
        std::cout << "Exiting . . ." << std::endl;
        break;

      default:
        std::cout << RED << "Invalid selection, try again." << RESET << std::endl;
    }
  }
  while (choice != 5);
  return 0;
}
