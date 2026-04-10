/* 
Name: Ashton Shalley
Email: ashalley2025@my.fit.edu

Purpose: Purpose: Create an application, “CDAccountModArray” that
stores 5 CDAccountMod structures into an array, and sorts the array based
on the balance field. The application will display the structure
information.

The CDAccountMod structure is composed of the following
fields/components
• First Name (string)
• Last Name (string)
• Balance (double)
• interestRate (double)
• Term (int)

Algorithm:
Loop i = 1 to 5
Prompt for first name
Get first name
Prompt for last name
Get last name
Prompt for balance
Get balance
Prompt for interest rate
Get interestRate
Prompt for term
Get term
End Loop
Call sort routine
Display Heading "First Name", "Last Name", "Balance", "Interest
Rate", "Term"
Loop i = 1 to 5
Display first name last Name balance interst
rate term
End Loop
Field Widths (i.e., setw ) also Right Justify (i.e., set ios::right
flag)
==========================
First Name: 10
Last Name: 15 (6 spaces between FN & LN)
Balance: 10 (3 spaces between LN & Balance)
Interest Rate: 15 (2 spaces between Balance & IR)
Term: 5 ( 1 space between IR & Term)
*/

#include <iostream>
#include <string>
#include <iomanip>

// Structure to hold CD account information
struct CDAccountMod {
  std::string firstName;
  std::string lastName;
  double balance;
  double interestRate;
  int term;
};

void bubbleSort(CDAccountMod arr[], int length);
const int SIZE = 5;

int main(){
  CDAccountMod myArray[SIZE];

  // Prompt user to populate each account in the array
  for (int i = 0; i < SIZE; i++){
    std::cout << "Enter first name: ";
    std::cin >> myArray[i].firstName;

    std::cout << "Enter last name: ";
    std::cin >> myArray[i].lastName;

    std::cout << "Enter balance: ";
    std::cin >> myArray[i].balance;

    std::cout << "Enter interest Rate: ";
    std::cin >> myArray[i].interestRate;

    std::cout << "Enter term: ";
    std::cin >> myArray[i].term;
  }

  // Sort the array by balance in ascending order
  bubbleSort(myArray, SIZE);

  // Display column headers
  std::cout << std::setw(10) << "First Name"
            << std::setw(15) << "Last Name"
            << std::setw(10) << "Balance"
            << std::setw(15) << "Interest Rate"
            << std::setw(5)  << "Term" << std::endl;

  // Display each account's information
  for (int i = 0; i < SIZE; i++){
    std::cout << std::setw(10) << myArray[i].firstName
              << std::setw(15) << myArray[i].lastName
              << std::setw(10) << myArray[i].balance
              << std::setw(15) << myArray[i].interestRate
              << std::setw(5)  << myArray[i].term << std::endl;
  }
}

// Sorts the array in ascending order by balance using bubble sort
void bubbleSort(CDAccountMod arr[], int length){
  CDAccountMod temp;
  for (int i = length - 1; i > 0; i--){
    for (int j = 0; j < i; j++){
      // Swap adjacent elements if left balance is greater than right
      if ( arr[j].balance > arr[j+1].balance ){
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}