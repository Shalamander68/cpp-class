// Name: Ashton shalley
// Email: ashalley2025@fit.edu
//
// Purpose: Create an application, “MyIntro” that 
//          displays the following message after 
//          prompting for the first and last name.  
//		My first name is yourFirstName
//		My last name is yourLastName
//
// Algorithm:
//     Prompt User for First Name
//     Get firstName
//     Prompt User for Last Name
//     Get lastName
//     Display firstName
//     Display lastName

#include <iostream>

int main() {
    std::string firstName;
    std::string lastName;

    std::cout << "Type your first name: ";
    std::cin >> firstName;
    
    std::cout << "Type your last name: ";
    std::cin >> lastName;

    std::cout << "Your name is " << lastName << ", " << firstName << '\n';
}