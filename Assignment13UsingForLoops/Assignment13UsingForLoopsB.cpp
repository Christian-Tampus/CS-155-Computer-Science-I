/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 13 Using For Loops B
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/19/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
const int WIDTH = 4;
const double CALORIES_BURNED_PER_MINUTE = 3.925;
int main(){
    int CurrentTime = 1, FinalTime = 80;
    double CaloriesBurned = 0;
    cout << "Program B: 3.925 Calories Burned Per Minute On A Particular Treadmill." << endl << endl;
    cout << "Time     Burned" << endl;
    for (int Index = CurrentTime; Index <= FinalTime; Index++){
        CaloriesBurned+=CALORIES_BURNED_PER_MINUTE;
        if (CurrentTime % 10 == 0){
            cout << left << setw(WIDTH) << CurrentTime << "     " << fixed << setprecision(2) << CaloriesBurned << " cal" << endl;
        };
        CurrentTime++;
    };
    cout << endl << "You Will Have Burned " << fixed << setprecision(2) << CaloriesBurned << " cal After " << (CurrentTime-1) << " Minutes On A Particular Treadmill." << endl << endl;
    return 0;
};
