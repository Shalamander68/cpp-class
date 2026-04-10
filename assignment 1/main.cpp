// Ashton Shalley
// ashalley2025@fit.edu
// Simple Calculator Application
/* 
FUNCTION getNumbersFromUser

  get input, numbers separated by spaces
    
  extract individual numbers
  store extracted numbers into a list

  output "numbers" list

END FUNCTION

FUNCTION Main

    do while loop

        print the menu:
            1) Sum
            2) Product
            3) Average
            4) Odd or Even
            5) Exit
        
        PROMPT "Enter your selection"
        get user input and write to "choice"

        IF input is not a number THEN
            CLEAR error flags
            PRINT "Invalid input. Please enter a number 1-5."
            CONTINUE to next iteration of loop
        END IF

        SWITCH "choice"
            CASE 1 (Sum)
                run getNumbersFromUser function
                calculate sum of all numbers with for loop
                print output

            CASE 2 (Product):
                run getNumbersFromUser function
                calculate product of all numbers with for loop
                print output

            CASE 3 (Average):
                run getNumbersFromUser function
                calculate average (sum+divide) of all numbers with a for loop
                print output

            CASE 4 (Odd or Even):
                ignore empty values
                for each number
                    print N/A for non integers
                    print even/odd
                
            CASE 5 (Exit):
                PRINT "Exiting"
                end program

            DEFAULT:
                PRINT "Please select a valid option (1-5)."

    UNTIL choice EQUALS 5

END FUNCTION 
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

// Color Codes
const std::string GRAY  = "\033[90m";
const std::string RED   = "\033[31m";
const std::string WHITE = "\033[97m";
const std::string RESET = "\033[0m";
const std::string BLUE  = "\033[34m";

// number input function
std::vector<double> getNumbersFromUser() {
    std::vector<double> numbers;
    std::string line;
    double tempNum;

    std::cin.ignore(10000, '\n'); // Clear the buffer

    std::cout << GRAY << "Enter numbers separated by spaces (e.g. 4 2.5 6): " << RESET;
    std::getline(std::cin, line);

    std::stringstream ss(line);

    while (ss >> tempNum) {
        numbers.push_back(tempNum);
    }

    if (numbers.empty()) {
        std::cout << RED << "No valid numbers detected, try again." << RESET << std::endl;
    }

    return numbers;
}

int main() {
    int choice = 0;

    // Variables for calculations
    std::vector<double> nums;
    double result = 0;

    do {
        std::cout << "\n" << BLUE << "Welcome to Simple Calculator Application" << RESET << std::endl
                  << GRAY << "---------------------------------------------" << RESET << std::endl
                  << "\t 1) Sum" << std::endl
                  << "\t 2) Product" << std::endl
                  << "\t 3) Average" << std::endl
                  << "\t 4) Odd or Even" << std::endl
                  << "\t 5) Exit" << std::endl << std::endl
                  << GRAY << "Enter your selection: " << RESET;

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            choice = 0; 
            std::cout << RED << "Invalid input. Please enter a number 1-5." << RESET << std::endl;
            continue; // Skip the rest of the loop and show menu again
        }
        
        switch (choice) {
            case 1: // SUM
                nums = getNumbersFromUser();
                if (nums.empty()) break;
                
                result = 0;
                for (double n : nums) result += n;
                std::cout << "The Sum is: " << WHITE << result << RESET << std::endl;
                break;

            case 2: // PRODUCT
                nums = getNumbersFromUser();
                if (nums.empty()) break;

                result = 1;
                for (double n : nums) result *= n;
                std::cout << "The Product is: " << WHITE << result << RESET << std::endl;
                break;

            case 3: // AVERAGE
                nums = getNumbersFromUser();
                if (nums.empty()) break;

                result = 0;
                for (double n : nums) result += n;
                std::cout << "The Average is: " << WHITE << (result / nums.size()) << RESET << std::endl;
                break;

            case 4: // ODD OR EVEN
                // only aplies to integers
                nums = getNumbersFromUser();
                if (nums.empty()) break;

                std::cout << "Results: " << std::endl;
                for (double n : nums) {
                    // Check if the number has a decimal part
                    if (std::floor(n) != n) {
                        std::cout << n << " is " << RED << "Decimal (N/A)" << RESET << std::endl;
                    } else {
                        // Cast to long long to use modulo operator %
                        long long intVal = static_cast<long long>(n);
                        if (intVal % 2 == 0) 
                            std::cout << intVal << " is " << WHITE << "Even" << RESET << std::endl;
                        else 
                            std::cout << intVal << " is " << WHITE << "Odd" << RESET << std::endl;
                    }
                }
                break;

            case 5: // exit
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << RED << "Please select a valid option (1-5)." << RESET << std::endl;
        }

    } while (choice != 5); // loop until choice is 5 (exit)

    return 0;
}