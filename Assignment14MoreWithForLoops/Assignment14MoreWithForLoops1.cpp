/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 14 More With For Loops 1
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/20/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
const double ANNUAL_FEE_INCREASE_MULTIPLIER = 0.04;
int main(){
    double YearlyMembership = 345;
    cout << "Fitness Center Projected Yearly Membership Rates" << endl << endl;
    cout << "Year     Rates" << endl;
    for (int Index = 0; Index < 8; Index++){
        cout << left << setw(4) << (Index+1) << "     $" << fixed << setprecision(2) << YearlyMembership << endl;
        YearlyMembership+=(YearlyMembership * ANNUAL_FEE_INCREASE_MULTIPLIER);
    };
    return 0;
};
