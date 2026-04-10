// Ashton Shalley
// ashalley2025@fit.edu
//
// Write an application (including algorithm/pseudocode) that modifies the
// application created for Assignment 2 by performing the following.
//
// - Create a void function, "displayMenu", for the menu that is used for
//   selecting the options. The function declaration is below.
//   o void displayMenu();
//
// - Create a function "SquareRootFunction". The function body contains all
//   code for getting user input and returning the value of the call of the
//   predefined "sqrt" library function. The function declaration is below.
//   o double SquareRootFunction();
//
// - Create a function "BinaryLogFunction". The function body contains all code
//   for getting user input and returning the value of the call of the
//   predefined "log2" library function. The function declaration is below.
//   o double BinaryLogFunction();
//
// - Create a function "PowerFunction". The function body contains all code for
//   getting user input and returning the value of the call of the predefined
//   "pow" library function. The function declaration is below.
//   o double PowerFunction();
//
// - Create a function "AbsoluteValueFunction". The function body contains all
//   code for getting user input and returning the value of the call of the
//   predefined "abs" library function. The function declaration is below.
//   o double AbsoluteValueFunction();
//
// The "main" function of the application must display the menu and prompt the user
// for the choice to call the appropriate function based on the switch logic, in
// lieu of the original code used in the Assignment 2 application. The "main"
// function should only have one local variable, representing the choice of the
// function that will be called (i.e., no other local variable is declared in
// "main").
//
// Notes:
//   1. The application must demonstrate the 3 requirements for functions
//     • Function Declaration
//     • Function Definition
//     • Function Call
//   2. Within each function definition, must declare all variables required for
//      getting input for calling the predefined function. The predefined
//      function call must be used in a "return" statement (e.g., "return sqrt(x)").
//      This will return the results of the call back to "main" which will
//      then display that result.

// Algorithm / Pseudocode:
//
// BEGIN
//   DECLARE function prototypes: displayMenu, SquareRootFunction,
//                                BinaryLogFunction, PowerFunction,
//                                AbsoluteValueFunction
//
//   FUNCTION main:
//     DECLARE choice (integer)
//     DO
//       CALL displayMenu()
//       READ choice
//       SWITCH choice
//         CASE 1: PRINT "sqrt = " + CALL SquareRootFunction()
//         CASE 2: PRINT "log2 = " + CALL BinaryLogFunction()
//         CASE 3: PRINT "pow  = " + CALL PowerFunction()
//         CASE 4: PRINT "abs  = " + CALL AbsoluteValueFunction()
//         CASE 5: PRINT "Exiting..."
//         DEFAULT: PRINT "Invalid selection"
//     WHILE choice != 5
//
//   FUNCTION displayMenu:
//     PRINT menu options
//
//   FUNCTION SquareRootFunction:
//     DECLARE num
//     READ num
//     RETURN sqrt(num)
//
//   FUNCTION BinaryLogFunction:
//     DECLARE num
//     READ num
//     RETURN log2(num)
//
//   FUNCTION PowerFunction:
//     DECLARE base, exponent
//     READ base, exponent
//     RETURN pow(base, exponent)
//
//   FUNCTION AbsoluteValueFunction:
//     DECLARE num
//     READ num
//     RETURN abs(num)
// END

#include <iostream>
#include <cmath>

// color codes
const std::string GRAY  = "\033[90m";
const std::string RED   = "\033[31m";
const std::string WHITE = "\033[97m";
const std::string RESET = "\033[0m";

// Function Declarations
void   displayMenu();
double SquareRootFunction();
double BinaryLogFunction();
double PowerFunction();
double AbsoluteValueFunction();

// -----------------------------------------------------------------------

int main() {
  int choice;

  do {
    displayMenu();
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      choice = 0;
    }

    switch (choice) {
      case 1: // sqrt
        std::cout << "sqrt = " << WHITE << SquareRootFunction() << RESET << std::endl;
        break;

      case 2: // Binary Logarithm
        std::cout << "log2 = " << WHITE << BinaryLogFunction() << RESET << std::endl;
        break;

      case 3: // Power
        std::cout << "pow  = " << WHITE << PowerFunction() << RESET << std::endl;
        break;

      case 4: // Absolute Value
        std::cout << "abs  = " << WHITE << AbsoluteValueFunction() << RESET << std::endl;
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

// -----------------------------------------------------------------------
// Function Definitions

// displayMenu - prints the menu
void displayMenu() {
  std::cout << std::endl
            << GRAY  << "----------------------------------------------" << RESET << std::endl
            << WHITE << "           Basic Calculator Program           " << RESET << std::endl
            << GRAY  << "----------------------------------------------" << RESET << std::endl << std::endl
            << "\t 1) Calculate Square Root"      << std::endl
            << "\t 2) Calculate Binary Logarithm" << std::endl
            << "\t 3) Calculate Power"            << std::endl
            << "\t 4) Calculate Absolute Value"   << std::endl
            << "\t 5) Exit"                       << std::endl << std::endl
            << "Enter your selection: ";
}

// SquareRootFunction - prompts for a number and returns its square root
double SquareRootFunction() {
  double num;
  std::cout << "Enter a positive number: ";
  std::cin >> num;
  return sqrt(num);
}

// BinaryLogFunction - prompts for a number and returns its base-2 logarithm
double BinaryLogFunction() {
  double num;
  std::cout << "Enter a positive number: ";
  std::cin >> num;
  return log2(num);
}

// PowerFunction - prompts for a base and exponent and returns base^exponent
double PowerFunction() {
  double base;
  double exponent;
  std::cout << "Enter the base: ";
  std::cin >> base;
  std::cout << "Enter the exponent: ";
  std::cin >> exponent;
  return pow(base, exponent);
}

// AbsoluteValueFunction - prompts for a number and returns its absolute value
double AbsoluteValueFunction() {
  double num;
  std::cout << "Enter a number: ";
  std::cin >> num;
  return std::abs(num);
}
