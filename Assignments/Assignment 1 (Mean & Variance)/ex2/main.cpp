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

using namespace std;

const int ARR_CAP = 500;

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

double calcBounds(double theoMean, double theoVar)
{
    return (sqrt(theoVar * 12) - (theoMean * 2)) / -2;
}

double calcBounds2(double theoMean, double theoVar)
{
    return (sqrt(theoVar * 12) + (theoMean * 2)) / 2;
}

int main()
{
    srand(333);
    double arr1[ARR_CAP] = {0};
    double arr2[ARR_CAP] = {0};
    double pracMean1 = 0.0;
    double pracMean2 = 0.0;
    double pracVar1 = 0.0;
    double pracVar2 = 0.0;
    double theoMean = 4.0;
    double theoVar1 = 0.5;
    double theoVar2 = 2.0;

    double lower = calcBounds(theoMean, theoVar1);
    double upper = calcBounds2(theoMean, theoVar1);
    double upper2 = calcBounds2(theoMean, theoVar2);
    double lower2 = calcBounds(theoMean, theoVar2);
    
    fillArray(arr1, ARR_CAP, upper, lower);
    fillArray(arr2, ARR_CAP, upper2, lower2);
    
    // finding the mean of the sets of stuff
    pracMean1 = practicalMean(arr1, ARR_CAP);
    pracMean2 = practicalMean(arr2, ARR_CAP);
    pracVar1 = practicalVariance(arr1, ARR_CAP, pracMean1);
    pracVar2 = practicalVariance(arr2, ARR_CAP, pracMean2);
        
    // theoMean = theorticalMean(lower, upper);
    // theoVar1 = theorticalVariance(lower, upper);
    // theoVar2 = theorticalVariance(lower2, upper2);
    
    cout << theoMean << " " << pracMean1 << " " << theoVar1 << " " << pracVar1 <<
        endl;
    cout << theoMean << " " << pracMean2 << " " << theoVar2 << " " << pracVar2 <<
        endl;

    return 0;
}