//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/main.cpp 
/// @brief Assignment #2 for CS 12 <Spring & 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <April 14th, 2015>
///
/// @par Enrollment Notes 
///     Lecture Section: 1
/// @par
///     Lab Section: 22
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int R = 6;
const int C = 8;
// -----------------------------------------------------------------------------
// FUNCTION DECLARATIONS
// -----------------------------------------------------------------------------
void fillEdges(double a[][C], double t, double l, double r, double b);
void equalibrium(double[][C], double &diff);
bool equilibriumTest(double tolerance, double diff);

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main ()
{
    string inputName, outputName;
    double grid[R][C] = {0};
    
    // get file names from user
    // check to see if file opens
    // input file
    cout << "Enter input file name: ";
    cin >> inputName;
    
    ifstream fin;
    fin.open(inputName.c_str());
    
    if (!fin.is_open())
    {
        cout << "Error opening: " << inputName << endl;
        return 0;
    }
    
    // output file
    cout << "Enter output file name: ";
    cin >> outputName;
    
    ofstream fout;
    fout.open(outputName.c_str());
    
    // read initial temp of top/bottom/left/right from file
    // input file goes: top, right, bottom, left; and tolerance on the 2nd line
    // read tolerance level from file
    double topVal, botVal, leftVal, rightVal, tolerance = 0.0;
    
    fin >> topVal >> rightVal >> botVal >> leftVal >> tolerance;

    // put initial temp into a 2D vector w/ 0's in the middle
    fillEdges(grid, topVal, leftVal, rightVal, botVal);

    // update temp until equalibrium is met
    // finds the biggest difference throughout the grid
    // keeps repeating until the max difference is less than the tolerance
    double difference = 0.0;
    bool at_equilbrium = false;
    
    while(!at_equilbrium)
    {
        equalibrium(grid, difference);
        at_equilbrium = equilibriumTest(tolerance, difference);
        
    }

    //output results into a file
    for (int i = 1; i < R - 1; i++)
    {
        for (int j = 1; j < C - 1; j++)
        {
            fout << grid[i][j] << " ";
        }
        fout << endl;
    }
    
    
    fin.close();
    fout.close();
    return 0;    
}

// -----------------------------------------------------------------------------
// FUNCTIONS
// -----------------------------------------------------------------------------
void equalibrium(double a[][C], double &diff)
{
    double temp;
    diff = 0.0;
    for (int i = 1; i < R - 1; i++)
    {
        for (int j = 1; j < C - 1; j++)
        {
            temp = a[i][j];
            // fills interior
            a[i][j] = (a[i][j-1] + a[i - 1][j] + a[i][j + 1] + a[i + 1][j]) / 4;
            
            if (a[i][j] - temp > diff)
            {
                diff = a[i][j] - temp;
            }
        }
    }
}

void fillEdges(double a[][C], double t, double l, double r, double b)
{
    for (int i = 0; i < C; i++)
    {
        a[0][i] = t;
    }
    for (int i = 1; i < R; i++)
    {
        a[i][0] = l;
    }
    for (int i = 1; i < R - 1; i++)
    {
        a[i][C - 1] = r;
    }
    for (int i = 0; i < C; i++)
    {
        a[R - 1][i] = b;
    }
}

bool equilibriumTest(double tolerance, double diff)
{
    if (diff <= tolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}