#include <iostream>
#include <iomanip>

using namespace std;

const int M = 2;
const int N = 3;

// -----------------------------------------------------------------------------
// FUNCTIONS DECLARATION
// -----------------------------------------------------------------------------
void matrixAdd(const int a[][N], const int b[][N], int sum[][N]);
void fillArray(int a[][N]);
void display(const int a[][N]);

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main()
{
   int matrixA[M][N] = {0};
   int matrixB[M][N] = {0};
   int matrixC[M][N] = {0};
   
   cout << "Enter Matrix A: ";
   fillArray(matrixA);
   cout << "Enter Matrix B: ";
   fillArray(matrixB);
   
   matrixAdd(matrixA, matrixB, matrixC);
   
   cout << "Res:" << endl;
   display(matrixC);
   
   return 0;
}

// -----------------------------------------------------------------------------
// FUNCTIONS
// -----------------------------------------------------------------------------
void matrixAdd(const int a[][N], const int b[][N], int sum[][N])
{
   for (int i = 0; i < M; i++)
   {
      for (int j = 0; j < N; j++)
      {
         sum[i][j] = a[i][j] + b[i][j];
      }
   }
}

void fillArray(int a[][N])
{
   for (int i = 0; i < M; i++)
   {
      for (int j = 0; j < N; j++)
      {
         cin >> a[i][j];
      }
   }
}

void display(const int a[][N])
{
   for (int i = 0; i < M; i++)
   {
      for(int j = 0; j < N; j++)
      {
         cout << a[i][j] << " ";
      }
      cout << endl;
   }
}
