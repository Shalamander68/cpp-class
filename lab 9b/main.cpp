// Name: Ashton Shalley
// Email: ashalley2025@fit.edu
// Purpose: Create an application that performs matrix multiplication
//
//Algorithm:
// Set const AROWS
// Set const ACOLS
// Set const BROWS
// Set const BCOLS
// Prompt Enter Matrix A
// Loop i = 1 to aRows
//   Loop j = 1 to aCols
//     get A[i][j]
//   End Loop
// End Loop
// Prompt Enter Matrix B
// Loop i = 1 to bRows
//   Loop j = 1 to bCols
//     get B[i][j]
//   End Loop
// End Loop
// Initalize arroy C to zeros
// Call matrixMultiply(A, B, C)
// Display Results

/* Source: TutorialsPoint w/ modification
           https://www.tutorialspoint.com/matrix-multiplication-algorithm
void matrixMultiply(A, B, C): A & B const arrays, C is not (i.e., call
by reference)

Assume dimension of A is (m x n), dimension of B is (p x q)
Begin
  if (if n != p) return from function
  for i in range 0 to m - 1, do
    for j in range 0 to q – 1, do
      for k in range 0 to p-1, do
        C[i, j] = C[i, j] + (A[i, k] * B[k, j])
      done
    done
  done
End
*/

#include <iostream>

const int AROWS = 3;
const int ACOLS = 3;
const int BROWS = 3;
const int BCOLS = 2;

void matrixMultiply(const int A[][ACOLS], const int B[][BCOLS], int C[][BCOLS]);

int main(){
  int A[AROWS][ACOLS];
  int B[BROWS][BCOLS];
  int C[AROWS][BCOLS] = { 0 };

  std::cout << "Enter Matrix A:" << std::endl;
    
  // Populate Matrox A
  for (int i = 0; i < AROWS; i++){
    for (int j = 0; j < ACOLS; j++){
      std::cin >> A[i][j];
    }
  }

  std::cout << "Enter Matrix B:" << std::endl;

  // Populate Matrox B
  for (int i = 0; i < BROWS; i++){
    for (int j = 0; j < BCOLS; j++){
      std::cin >> B[i][j];
    }
  }

  // Initalize Matrox C to zeros - Unessicary
  for (int i = 0; i < AROWS; i++){
    for (int j = 0; j < BCOLS; j++){
      C[i][j] = 0;
    }
  }

  matrixMultiply(A, B, C); // Function Call

  std::cout << "Matrix C:" << std::endl;
  
  for (int i = 0; i < AROWS; i++){
    for (int j = 0; j < BCOLS; j++){
      std::cout << C[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void matrixMultiply(const int A[][ACOLS], const int B[][BCOLS], int C[][BCOLS]){
  if (ACOLS != BROWS){
    std::cout << "Can't preform matrix multiplication beacuse ACOLS is not equal to BROWS" << std::endl;
    exit(0);
  }
  for (int i = 0; i < AROWS; i++){
    for (int j = 0; j < BCOLS; j++){
      for (int k = 0; k < BROWS; k++){
        C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
      }
    }
  }
}
