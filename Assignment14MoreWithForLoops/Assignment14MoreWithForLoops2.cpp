/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 14 More With For Loops 2
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/20/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double YearlyMembership, PercentageIncrease;
    int Years;
    cout << "Fitness Center Projected Yearly Membership Rates" << endl << endl;
    do{
        cout << "Please Enter Initial Membership Rate (Example: 14.95, Must Not Be A Negative Number)..." << endl;
        cin >> YearlyMembership;
    }while (YearlyMembership < 0);
    do{
        cout << "Please Enter Percentage Increase (Example: 3.57, Must Not Be A Negative Number)..." << endl;
        cin >> PercentageIncrease;
        PercentageIncrease/=100;
    }while (PercentageIncrease < 0);
    do{
        cout << "Please Enter Years (Example: 13, Must Not Be A Negative Number)..." << endl;
        cin >> Years;
    }while (Years < 0);
    cout << endl << "Year     Rates" << endl;
    for (int Index = 0; Index < Years; Index++){
        cout << left << setw(4) << (Index+1) << "     $" << fixed << setprecision(2) << YearlyMembership << endl;
        YearlyMembership+=(YearlyMembership * PercentageIncrease);
    };
    return 0;
};
