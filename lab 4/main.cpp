// Name: Ashton Shalley
// Email: ashalley2025@fit.edu
// 
// Purpose: Create an application, “MessageChoice” that displays one of three
//          messages, including declaration of multiple message constants.  
// 
// Algorithm:
// Display the following
//   Welcome to Message Choice Application
//
//      1) Display Message 1
//      2) Display Message 2
//      3) Display Message 3
//      4) Exit
//
//   Enter the choice and press return
//   Get choice
// if "1" selected
//   Display Message1
// else if "2" selected 
//   Display Message2
// else if "3" selected
//   Display Message3
// else if "4" selected
//   Display "Thank you for performing the Message Choice Application!"

#include <iostream>
#include <string>

// color codes
const std::string GRAY  = "\033[90m";
const std::string RED   = "\033[31m";
const std::string WHITE = "\033[97m";
const std::string RESET = "\033[0m";

int main () {
  int choice;

  do {

    std::cout << GRAY << "---------------------------------------------" << RESET << std::endl
              << GRAY << " -< " << RESET << WHITE << "Welcome to Message Choice Application" << RESET << GRAY << " >- "<< RESET << std::endl
              << GRAY << "---------------------------------------------" << RESET << std::endl << std::endl
              << "\t 1) Display Message 1" << std::endl
              << "\t 2) Display Message 2" << std::endl
              << "\t 3) Display Message 3" << std::endl
              << "\t 4) Exit" << std::endl << std::endl
              << "Enter your selection and press return" << std::endl << std::endl;

    std::cin >> choice;

    if(std::cin.fail()) {
      std::cin.clear(); // clear the error flag
      std::cin.ignore(10000, '\n'); // discard the buffer
      choice = 0; // set choice to an invalid value to trigger the error message
    }

    switch (choice) {
      case 1:
        std::cout << "Message 1" << std::endl;
        break;
      case 2:
        std::cout << "Message 2" << std::endl;
        break;
      case 3:
        std::cout << "Message 3" << std::endl;
        break;
      case 4:
        std::cout << "Exiting Message Choice Application" << std::endl;
        break;
      default:
        std::cout << RED << "Invalid Selection, try again." << RESET << std::endl;
    } 
  }
  while (choice < 1 || choice > 4);
  
  return 0;
}
