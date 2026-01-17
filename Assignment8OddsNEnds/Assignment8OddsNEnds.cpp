/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 8 Odds N Ends
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/7/2024
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
//Declare & Init Constants
const int OUTPUT_WIDTH = 30;
const double MAX_PAY_MULTIPLIER = 2.5, INCREASED_PAY_MULTIPLIER = 1.5;
int main(){
    //Declare & Init Variables
    string UserName;
    double HourlyRate, TempHoursWorked, MaxPay = 0, IncreasedPay = 0, RegularPay = 0, TotalPay;
    int HoursWorked;
    //Get User Inputs
    cout << "[Odds-N-Ends] Pay Roll System (R)" << endl << endl << "Please Input User Name..." << endl;
    getline(cin,UserName);
    cout << "Please Input Your Hourly Rate (Wage)..." << endl;
    cin >> HourlyRate;
    if (HourlyRate <= 0){
        cout << "[SYSTEM_ERROR] Hourly Rate Must Be Greater Than 0!" << endl << "[SYSTEM_MESSAGE] Program Terminated..." << endl;
        return 0;
    }
    cout << "Please Input Your Hours Worked..." << endl;
    cin >> TempHoursWorked;
    HoursWorked = floor(TempHoursWorked);
    if (HoursWorked < 1 || HoursWorked > 24 || TempHoursWorked > 24){
        cout << "[SYSTEM_ERROR] Hours Worked Must Be Greater Than 1 & Less Than Or Equal To 24!" << endl << "[SYSTEM_MESSAGE] Program Terminated..." << endl;
        return 0;
    };
    //Calculate MaxPay, IncreasedPay, RegularPay, TotalPay
    if (HoursWorked > 5){
        MaxPay = (HoursWorked - 5) * (HourlyRate * MAX_PAY_MULTIPLIER);
        IncreasedPay = 3 * (HourlyRate * INCREASED_PAY_MULTIPLIER);
        RegularPay = 2 * HourlyRate;
    }else if (HoursWorked > 2){
        IncreasedPay = (HoursWorked - 2) * (HourlyRate * INCREASED_PAY_MULTIPLIER);
        RegularPay = 2 * HourlyRate;
    }else if (HoursWorked <= 2){
        RegularPay = HoursWorked * HourlyRate;
    };
    TotalPay = MaxPay + IncreasedPay + RegularPay;
    //Display Outputs UserName, RegularPay, IncreasedPay, MaxPay, TotalPay & Terminate Program
    cout << endl << "--------------------------------------------------------------------------------" << endl;
    cout << right << setw(OUTPUT_WIDTH) << "Employee Name: " << UserName << endl;
    cout << right << setw(OUTPUT_WIDTH) << "Actual Hours Payed: " << HoursWorked << " Hrs." << endl;
    if (RegularPay > 0){
        cout << right << setw(OUTPUT_WIDTH) << "Regular Hourly Rate Pay: " << "$" << fixed << setprecision(2) << RegularPay << endl;
    };
    if (IncreasedPay > 0){
        cout << right << setw(OUTPUT_WIDTH) << "Time And A Half Rate Pay: " << "$" << fixed << setprecision(2) << IncreasedPay << endl;
    };
    if (MaxPay > 0){
        cout << right << setw(OUTPUT_WIDTH) << "2.5 Times Rate Pay: " << "$" << fixed << setprecision(2) << MaxPay << endl;
    };
    cout << right << setw(OUTPUT_WIDTH) << "Total Pay: " << "$" << fixed << setprecision(2) << TotalPay << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << endl << "[SYSTEM_MESSAGE] Program Terminated..." << endl;
    return 0;
};
//IMPORTANT TO NOTE: ARRAYS START AT 1! :)
