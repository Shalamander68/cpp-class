// Name: Ashton Shalley
// Email: ashalley2025@my.fit.edu

// Write an application (including algorithm) that uses the predefined functions,
// "sqrt" (square root), "log2" (binary logarithm), "pow" (power), and "abs"
// (absolute value). The declaration of these functions are contained in either
// "cmath", or "cstdlib" header files. Therefore, the required header files must
// be included in the application (i.e., only include required header files).
// The application requires a loop that will run until the user makes a selection
// to "Quit". The application uses a menu (similar to Chapter 3 slide 108) that
// displays a list of choices.
//   1) Process Square Root Function
//   2) Process Binary (i.e., Base 2) Logarithm Function
//   3) Process Power Function
//   4) Process Absolute Value Function
//   5) Quit
// Select a choice:
//
// A switch statement is used to determine the choice. Each choice prompts for the
// information, calls the predefined function and displays the result.
//
// Notes:
//   1. Include pseudocode at top
//   2. Use the C++ style header files (e.g. <cmath> not "math.h")
//   3. Do not use Global Variables
//   4. Only use predefined functions; do not create any functions
//   5. The cplusplus.com site contains Header file information

// Pseudocode:
//   BEGIN
//     DECLARE choice, result, num, base, exponent, etc
//     DO
//       DISPLAY menu options
//       READ choice
//       IF input invalid THEN set choice = 0
//       SWITCH choice
//         CASE 1 (Square Root):
//           PROMPT user for a non-negative number
//           READ num
//           COMPUTE result = sqrt(num)
//           DISPLAY result
//         CASE 2 (Binary Logarithm):
//           PROMPT user for a positive number
//           READ num
//           COMPUTE result = log2(num)
//           DISPLAY result
//         CASE 3 (Power):
//           PROMPT user for base and exponent
//           READ base, exponent
//           COMPUTE result = pow(base, exponent)
//           DISPLAY result
//         CASE 4 (Absolute Value):
//           PROMPT user for a number
//           READ num
//           COMPUTE result = abs(num)
//           DISPLAY result
//         CASE 5 (Quit):
//           DISPLAY exit message
//         DEFAULT:
//           DISPLAY invalid selection message
//     WHILE choice != 5
//   END

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