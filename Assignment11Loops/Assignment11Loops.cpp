/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 11 Loops
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/15/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
const int WIDTH = 4, SALARY_INCREASE_MULTIPLIER = 3;
const double OCEAN_LEVEL_INCREASE = 2.3, CALORIES_BURNED_PER_MINUTE = 3.925;
int main(){
    //Declare Variables
    int CurrentYear = 2024, FinalYear = CurrentYear + 35, CurrentTime = 1, FinalTime = 80, CurrentDay = 0, DaysWorked;
    double OceanLevel = 0, CaloriesBurned = 0;
    long double Salary = 5;
    //Program A Start
    cout << "Program A: Ocean Level Increase At A Rate Of 2.3 Millimeters Per Year." << endl << endl;
    cout << "Year     Risen" << endl;
    while (CurrentYear < FinalYear){
        OceanLevel+=OCEAN_LEVEL_INCREASE;
        cout << left << setw(WIDTH) << CurrentYear << "     " << fixed << setprecision(3) << OceanLevel << " mm" << endl;
        CurrentYear++;
    };
    cout << endl << "The Ocean's Level Will Have Risen " << OceanLevel << " mm After 35 Years." << endl << endl;
    //Program B Start
    cout << "Program B: 3.925 Calories Burned Per Minute On A Particular Treadmill." << endl << endl;
    cout << "Time     Burned" << endl;
    while (CurrentTime <= FinalTime){
        CaloriesBurned+=CALORIES_BURNED_PER_MINUTE;
        if (CurrentTime % 10 == 0){
            cout << left << setw(WIDTH) << CurrentTime << "     " << fixed << setprecision(2) << CaloriesBurned << " cal" << endl;
        };
        CurrentTime++;
    };
    cout << endl << "You Will Have Burned " << fixed << setprecision(2) << CaloriesBurned << " cal After " << (CurrentTime-1) << " Minutes On A Particular Treadmill." << endl << endl;
    //Program C Start
    cout << "Program C: Please Enter Number Of Days Worked (Example: 365)..." << endl;
    cin >> DaysWorked;
    cout << endl << "Your Salary Per Day If Your Starting Salary Is $5 On Day 1 And Tripled Everyday Until " << DaysWorked << " Days." << endl << endl;
    cout << "Days     Salary" << endl;
    while (CurrentDay < DaysWorked){
        cout << left << setw(WIDTH) << (CurrentDay+1) << "     $" << fixed << setprecision(2) << Salary << endl;
        Salary*=SALARY_INCREASE_MULTIPLIER;
        CurrentDay++;
    };
    return 0;
};
