/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 7 C Data Validation
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/6/2024
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double POWER = 2, DIVIDER = 100; //<- This Is Unnecessary But For The Sake Of Showing Capitalized Constants
const int INVALID_INPUT_VALUE_0 = 0, INVALID_INPUT_VALUE_1000 = 1000;
const string INVALID_INPUT_TEXT = "Data is not valid";
int main(){
    //Declare Variables
    double CylinderRadius, CylinderHeight, JamPricePerCubicInch, CylinderVolume, TotalCost;
    //Obtain User Inputs For Radius & Height (In Inches) And Jam Price (In Cents) Per Cubic Inch
    //I Could Make The Program Calculate Depending If The Inputs Are Not In Inches But Requires If-Statements
    cout << "Welcome To Bobbie's Farm Stand!" << endl << endl;
    cout << "Please Enter The Radius (In Inches) Of Your Cylinder Container (Example: 32oz Mason Jar @ 1.69 Inches Radius)..." << endl;
    cin >> CylinderRadius;
    if (CylinderRadius < INVALID_INPUT_VALUE_0 || CylinderRadius > INVALID_INPUT_VALUE_1000){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Please Enter The Height (In Inches) Of Your Cylinder Container (Example: 32oz Mason Jar @ 7 Inches Height)..." << endl;
    cin >> CylinderHeight;
    if (CylinderHeight < INVALID_INPUT_VALUE_0 || CylinderHeight > INVALID_INPUT_VALUE_1000){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Please Enter The Price Per Cubic Inch (In Cents) Of The Jam You Wish To Purchase (Example: 10 Cents)..." << endl;
    cin >> JamPricePerCubicInch;
    if (JamPricePerCubicInch < INVALID_INPUT_VALUE_0 || JamPricePerCubicInch > INVALID_INPUT_VALUE_1000){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    //Calculate Volume & Total Cost W/O Using Constants
    CylinderVolume = M_PI * pow(CylinderRadius,2) * CylinderHeight;
    TotalCost = (CylinderVolume * JamPricePerCubicInch)/100;
    //Calculate Volume & Total Cost W/Using Constants Example
    CylinderVolume = M_PI * pow(CylinderRadius,POWER) * CylinderHeight;
    TotalCost = (CylinderVolume * JamPricePerCubicInch)/DIVIDER;
    //Display Outputs (Volume & Cost)
    cout << "________________________________________________________________________" << endl;
    cout << "The Volume Of Your Cylinder Container Is: " << fixed << setprecision(1) << CylinderVolume << " Cubic Inches." << endl;
    cout << "The Total Cost For Your Jam Is: $"<< fixed << setprecision(2) << TotalCost << endl;
    cout << endl;
    cout << "Mr. Bobbie: Thank You Come Again!" << endl;
};
