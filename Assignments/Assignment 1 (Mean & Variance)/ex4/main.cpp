//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/main.cpp 
/// @brief Assignment/Lab #1 for CS 12 <Spring & 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <April 9th, 2015>
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
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double randFloat(double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double randMV(double mean, double variance)
{
    double a = 0.0;
    double b = 0.0;
    
    a = (sqrt(variance * 12) - (mean * 2)) / -2;
    b = (sqrt(variance * 12) + (mean * 2)) / 2;
    
    cout << a << " ";
    cout << b;
    
    return randFloat(a, b);
}

int main()
{
    srand(333);
    double mean = 0.0;
    double variance = 0.0;
    
    cout << "Please enter the mean: " << endl;
    cin >> mean;
    cout << "Please enter the variance: " << endl;
    cin >> variance;
    
    randMV(mean, variance);
    
    return 0;
}