// Name: Ashton Shalley
// Email: ashalley2025@my.fit.edu
//
// Purpose: Create an applicationication, “SimpleLoop” that displays a name
// multiple times, using '_' to substitute for space character
//
// Algorithm:
//   Prompt the user for a name (i.e., format is LastName_FirstInitial, e.g. “Bennett_J”)
//   Store value in myName (i.e., uses a string variable)
//   Prompt user for number of iterations
//   Store value in numIterations
//   Loop 1 to numberIterations
//     Display myName
//   End Loop

#include <iostream>

int main() {
  int numIterations;
  std::string myName;

  std::cout << "Enter your Name: ";
  std::cin >> myName;

  std::cout << "Number of Iterations: ";
  std::cin >> numIterations;

  for (int i = 1; i <= numIterations; i++) {
    std::cout << "My name is: " << myName << std::endl;
  }
}
