#include <iostream>

using namespace std;

const int Q = 2;
const int R = 3;
const int S = 3;

// -----------------------------------------------------------------------------
// FUNCTIONS DECLARATION
// -----------------------------------------------------------------------------
void matrixMult(const int a[][R], const int b[][S], int product[][S]);
void fillArrayQ(int a[][R]);
void fillArrayR(int a[][S]);
void display(const int a[][R]);

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main()
{
   int matrixA[Q][R] = {0};
   int matrixB[R][S] = {0};
   int matrixC[Q][S] = {0};
   
   // fill in arrays
   cout << "Enter Matrix A(size 2x3): ";
   fillArrayQ(matrixA);
   cout << "Enter Matrix B(size 3x3): ";
   fillArrayR(matrixB);
   
   // multiply matrix
   matrixMult(matrixA, matrixB, matrixC);
   
   // display results
   cout << "Res: " << endl;
   display(matrixC);
   
   return 0;
}

// -----------------------------------------------------------------------------
// FUNCTIONS
// -----------------------------------------------------------------------------
void display(const int a[][S])
{
   for (int i = 0; i < Q; i++)
   {
      for(int j = 0; j < S; j++)
      {
         cout << a[i][j] << " ";
      }
      cout << endl;
   }
}

void fillArrayQ(int a[][R])
{
   for (int i = 0; i < Q; i++)
   {
      for (int j = 0; j < R; j++)
      {
         cin >> a[i][j];
      }
   }
}

void fillArrayR(int a[][S])
{
   for (int i = 0; i < R; i++)
   {
      for (int j = 0; j < S; j++)
      {
         cin >> a[i][j];
      }
   }
}

void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
   for (int i = 0; i < Q; i++)
   {
      for (int j = 0; j < R; j++)
      {
         for (int k = 0; k < S; k++)
         {
            product[i][j] += a[i][k] * b[k][j];
         }
      }
   }
}