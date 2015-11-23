//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/main.cpp 
/// @brief Assignment/Lab #1 for CS 12 <Spring & 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <April 6th, 2015>
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

const int ARR_CAP1 = 1000;
const int ARR_CAP2 = 100000;

using namespace std;

double randFloat(double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

void fillArray(double a[], int size, double upper, double lower)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = randFloat(lower, upper);
    }
}

double practicalMean(const double a[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    
    return sum / size;
}

double practicalVariance(const double a[], int size, double mean)
{
    double sumTop = 0.0;
    for (int i = 0; i < size; i++)
    {
        sumTop += pow((mean - a[i]), 2);
    }
    return sumTop / size;
}

double theorticalMean(double lowerLimit, double upperLimit)
{
    return (lowerLimit + upperLimit) / 2;
}

double theorticalVariance(double lowerLimit, double upperLimit)
{
    return (pow((upperLimit - lowerLimit), 2) / 12);
}

int main()
{
    srand(333); // change into time(0)
    double upperLimit = 0.0;
    double lowerLimit = 0.0;
    double t[ARR_CAP1] = {0};
    double ht[ARR_CAP2] = {0};
    double pracMean1 = 0.0;
    double pracMean2 = 0.0;
    double pracVar1 = 0.0;
    double pracVar2 = 0.0;
    double theoMean = 0.0;
    double theoVar = 0.0;

    
    cout << "Pllease enter the lower/upper limit: ";
    cin >> lowerLimit;
    cin >> upperLimit;
    
    fillArray(t, ARR_CAP1, upperLimit, lowerLimit);
    fillArray(ht, ARR_CAP2, upperLimit, lowerLimit);
    
    // finding the mean of the sets of stuff
    pracMean1 = practicalMean(t, ARR_CAP1);
    pracMean2 = practicalMean(ht, ARR_CAP2);
    pracVar1 = practicalVariance(t, ARR_CAP1, pracMean1);
    pracVar2 = practicalVariance(ht, ARR_CAP2, pracMean2);
        
    theoMean = theorticalMean(lowerLimit, upperLimit);
    theoVar = theorticalVariance(lowerLimit, upperLimit);
    
    cout << theoMean << " " << pracMean1 << " " << theoVar << " " << pracVar1 <<
        endl;
    cout << theoMean << " " << pracMean2 << " " << theoVar << " " << pracVar2 <<
        endl;

    return 0;
}