// TriangleApp.cpp
// Assignment 5 - Spring 2026
// Uses the Triangle class to create, move, and display two triangle objects.

#include <iostream>
#include <iomanip>
#include "Triangle.h"
using namespace std;

// ============================================================
// Function Declarations (prototypes)
// ============================================================
void DisplayTriangle(const Triangle &t);
void MoveTriangle(Triangle &t, double deltaX, double deltaY);

// ============================================================
// main()
// ============================================================
int main() {
    // Create two Triangle objects
    Triangle t1("Triangle #1", 2.0, 4.0, 7.3, 5.0);
    Triangle t2("Triangle #2", 5.0, 7.0, 3.5, 12.3);

    const double deltaX = 1.5;
    const double deltaY = 2.2;
    const int    ITERATIONS = 5;

    // Display initial state of both triangles
    cout << "========== INITIAL TRIANGLE DATA ==========\n";
    DisplayTriangle(t1);
    DisplayTriangle(t2);

    // Move both triangles for 5 iterations, displaying after each move
    for (int i = 1; i <= ITERATIONS; i++) {
        cout << "\n========== AFTER MOVE " << i << " "
             << "(deltaX = " << deltaX << ", deltaY = " << deltaY << ") ==========\n";

        MoveTriangle(t1, deltaX, deltaY);
        MoveTriangle(t2, deltaX, deltaY);

        DisplayTriangle(t1);
        DisplayTriangle(t2);
    }

    return 0;
}

// ============================================================
// Function Definitions (after main)
// ============================================================

// DisplayTriangle
// Prints all properties of a Triangle object to the console.
// Parameters: t - a const reference to a Triangle object
// Returns:    void
void DisplayTriangle(const Triangle &t) {
    cout << "\n--- " << t.getName() << " ---\n";
    cout << string(50, '-') << "\n";
    cout << fixed << setprecision(2);
    cout << left << setw(20) << "Location (xLoc):"  << t.getXLoc()      << "\n";
    cout << left << setw(20) << "Location (yLoc):"  << t.getYLoc()      << "\n";
    cout << left << setw(20) << "Base:"             << t.getBase()      << "\n";
    cout << left << setw(20) << "Height:"           << t.getHeight()    << "\n";
    cout << left << setw(20) << "Hypotenuse:"       << t.hypotenuse()   << "\n";
    cout << left << setw(20) << "Perimeter:"        << t.perimeter()    << "\n";
    cout << left << setw(20) << "Area:"             << t.area()         << "\n";
}

// MoveTriangle
// Moves a Triangle's location by adding deltaX to xLoc and deltaY to yLoc.
// Parameters: t      - a reference to the Triangle to move
//             deltaX - amount to add to xLoc
//             deltaY - amount to add to yLoc
// Returns:    void
void MoveTriangle(Triangle &t, double deltaX, double deltaY) {
    t.setXLoc(t.getXLoc() + deltaX);
    t.setYLoc(t.getYLoc() + deltaY);
}
