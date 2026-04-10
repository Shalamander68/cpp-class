#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream imputFile;
    ifstream outputFile;

    double sum;
    double number;

    sum = 0;

    inputFile.open("Numbers.txt");
    outputfile.open("Table.txt");

    outputFile.setf(ios::fixed);
    outputFile.setf(ios::showpoint);
    outputFile.setf(ios::right);
    outputFile.percision(2);

    outputFile << setw(6) << "Number" << set(17) << "Square Root" << endl;
    outputFile << setw(6) << "======" << set(17) << "===========" << endl;

    while(inputFile >> number){
        sum += number;
        outputFile << setw(6) << number << setw(17) << sqrt(number) << endl;
    }
    outputFile << "Sum = " << sum << endl;

    return 0;
}