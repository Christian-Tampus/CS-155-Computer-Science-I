/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 13 Using For Loops C
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/19/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
const int WIDTH = 4, SALARY_INCREASE_MULTIPLIER = 3;
int main(){
    int CurrentYear = 2024, FinalYear = CurrentYear + 35, CurrentDay = 0, DaysWorked;
    long double Salary = 5;
    cout << "Program C: Please Enter Number Of Days Worked (Example: 365)..." << endl;
    cin >> DaysWorked;
    cout << endl << "Your Salary Per Day If Your Starting Salary Is $5 On Day 1 And Tripled Everyday Until " << DaysWorked << " Days." << endl << endl;
    cout << "Days     Salary" << endl;
    for (int Index = CurrentDay; Index < DaysWorked; Index++){
        cout << left << setw(WIDTH) << (CurrentDay+1) << "     $" << fixed << setprecision(2) << Salary << endl;
        Salary*=SALARY_INCREASE_MULTIPLIER;
        CurrentDay++;
    };
    return 0;
};
