/* 
Name: Ashton Shalley
email: ashalley2025@fit.edu

Purpose: Purpose: Create an application, “Weekly Salary” that reads name, hourly pay and hours worked from a file, stores strings in an array of 100 structures, and displays the array. The logic is as follows.

The structure, “Employee”, contains the following fields.
  • name
  • hourlyPay
  • hoursWorked
  • wages
Algorithm
  numRecords= 0
  Open inputFile
  Read name into tempStr
  while (not EOF)
    numRecords++
    Store tempStr into empArray[numRecords-1].name
    Read hourlyPay into tempStr
    Store converted tempStr into empArray[numRecords-1].hourlyPay
    Read hoursWorked into tempStr
    Store converted tempStr into empArray[numRecords-1].hoursWorked
    empArray[numRecords-1].wages = empArray[numRecords-1].hourlyPay
                                 * empArray[numRecords-
  End Loop

1].hoursWorked
  Read name into tempStr
  End Loop
  Loop i = 0 to numRecords
    Display empArray[i].name
    Display empArray[i].hourlyPay
    Display empArray[i].hoursWorked
    Display empArray[i].wages
  End Loop

Notes:
  Use getLine method,
  interior fields use ':' as delimeter
  last field read must use '\n' as delimeter
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
  string name;
  double hourlyPay;
  double hoursWorked;
  double Wages;
};

constant int SIZE = 100;

int main()
{
  ifstream inFile;
  string tempStr;
  int numRecords;
  Employee empArray[SIZE];
  numRecords = 0;

  inFile.open("TestFile.txt");
  getline(inFile, tempStr, ':')

  while (!inFile.eof()){
    numRecords++;
    empArray[numRecords - 1].name = tempStr;              // Assign name to array element

    getline(inFile, tempStr, ':');                        // read hourlyPay
    empArray[numRecords - 1].hourlyPay = stod(tempStr);   // convert hourlyPay (stored in tempStr) to a double

    getline(inFile, tempStr, '/n');                       // read hoursWorked
    empArray[numRecords - 1].hoursWorked = stod(tempStr); // convert hoursWorked (stored in tempStr) to a double

    empArray[numRecords - 1].wages = empArray[numRecords - 1].hourlyPay
                                   * empArray[numRecords - 1].hoursWorked; // ccalculate wages and store in the array

    getline(inFile, tempStr, ':');
  };

  for (int i = 0; i < numRecords; i++){
    cout << "Name-"         << (i + 1) << ": " << empArray[i].name        << endl;
    cout << "Hourly Pay-"   << (i + 1) << ": " << empArray[i].hourlyPay   << endl;
    cout << "Hours Worked-" << (i + 1) << ": " << empArray[i].hoursWorked << endl;
    cout << "Wages-"        << (i + 1) << ": " << empArray[i].wages       << endl;
  }
}