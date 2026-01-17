/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 16 Data Files
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/26/2024
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
//Declare Constants
const string TXT_SUFFIX = ".txt";
const int OUTPUT_WIDTH = 30;
const double MAX_PAY_MULTIPLIER = 2.5, INCREASED_PAY_MULTIPLIER = 1.5;
int main(){
    //Declare Variables
    string ReadFile, WriteFile;
    ifstream InputFile;
    ofstream OutputFile;
    int Line = 0;
    cout << "[Odds-N-Ends] Pay Roll System (R)" << endl << endl;
    //Repeat Until Valid Input Is Entered For ReadFile That Exists In The Current Directory Then Opens It (This Allows For Different Input Files To Be Read; Default: input-Christian)
    do{
        cout << "Please Enter File To Read  (Default: input-Christian)..." << endl;
        getline(cin,ReadFile);
        if (ReadFile.size() < TXT_SUFFIX.size() || ReadFile.size() > TXT_SUFFIX.size() && ReadFile.compare(ReadFile.size()-TXT_SUFFIX.size(),TXT_SUFFIX.size(),TXT_SUFFIX) != 0){ //Checks ReadFile Input To Determine If It Requires The .txt Suffix
            ReadFile+=TXT_SUFFIX; //This Adds The .txt Suffix In Case The Input Value Does Not Have It To The ReadFile Value
        };
        InputFile.open(ReadFile);
        cout << (InputFile.fail() ? "Read File Name: "+ReadFile+" Does Not Exist!" : "Read File Name: "+ReadFile+" Successfully Opened!" ) << endl;
    }while(InputFile.fail() && !InputFile.is_open());
    //Repeat Until Valid Input Is Entered For WriteFile That Exists In The Current Directory Or Not Then Opens It (This Allows For Different Output Files To Be Written; Default: output-Christian)
    do{
        cout << "Please Enter File To Write (Default: output-Christian)..." << endl;
        getline(cin,WriteFile);
        if (WriteFile.size() < TXT_SUFFIX.size() || WriteFile.size() > TXT_SUFFIX.size() && WriteFile.compare(WriteFile.size()-TXT_SUFFIX.size(),TXT_SUFFIX.size(),TXT_SUFFIX) != 0){ //Checks WriteFile Input To Determine If It Requires The .txt Suffix
            WriteFile+=TXT_SUFFIX; //This Adds The .txt Suffix In Case The Input Value Does Not Have It To The WriteFile Value
        };
        OutputFile.open(WriteFile);
        cout << (OutputFile.fail() ? "Write File Name: "+WriteFile+" Does Not Exist!" : "Write File Name: "+WriteFile+" Successfully Opened!" ) << endl;
    }while(OutputFile.fail() && !OutputFile.is_open());
    //Loops Until It Reaches The End Of The File To Read The Inputs, Process Them, Displays Them, Then Writes To The Output File
    while (!InputFile.eof()){
        string UserName;
        double HourlyRate, TempHoursWorked, MaxPay = 0, IncreasedPay = 0, RegularPay = 0, TotalPay;
        int HoursWorked;
        getline(InputFile,UserName);
        Line++;
        InputFile >> HourlyRate;
        Line++;
        if (HourlyRate <= 0){
            cout << "[SYSTEM_ERROR] Hourly Rate Must Be Greater Than 0 At Line: "+to_string(Line)+" Hourly Rate: "+to_string(HourlyRate) << endl;
            break; //This Breaks The Loop To Prevent Writing More Information To The Output File So The User Can Fix The Inputs To Be Valid For Hourly Rates
        };
        InputFile >> TempHoursWorked;
        HoursWorked = floor(TempHoursWorked);
        InputFile >> ws;
        if (HoursWorked < 1 || HoursWorked > 24 || TempHoursWorked > 24){
            cout << "[SYSTEM_ERROR] Hours Worked Must Be Greater Than 1 & Less Than Or Equal To 24 At Line: "+to_string(Line)+" Hours Worked: "+to_string(HoursWorked) << endl;
            break; //This Breaks The Loop To Prevent Writing More Information To The Output File So The User Can Fix The Inputs To Be Valid For Hours Worked
        };
        //Calculations
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
        //Displays Information & Writes To Output File
        cout << endl << "--------------------------------------------------------------------------------" << endl;
        OutputFile << endl << "--------------------------------------------------------------------------------" << endl;
        cout << right << setw(OUTPUT_WIDTH) << "Employee Name: " << UserName << endl;
        OutputFile << right << setw(OUTPUT_WIDTH) << "Employee Name: " << UserName << endl;
        cout << right << setw(OUTPUT_WIDTH) << "Hourly Rate: " << HourlyRate << endl;
        OutputFile << right << setw(OUTPUT_WIDTH) << "Hourly Rate: " << HourlyRate << endl;
        cout << right << setw(OUTPUT_WIDTH) << "Input Hours: " << TempHoursWorked << endl;
        OutputFile << right << setw(OUTPUT_WIDTH) << "Input Hours: " << TempHoursWorked << endl;
        cout << right << setw(OUTPUT_WIDTH) << "Actual Hours Payed: " << HoursWorked << " Hrs." << endl;
        OutputFile << right << setw(OUTPUT_WIDTH) << "Actual Hours Payed: " << HoursWorked << " Hrs." << endl;
        if (RegularPay > 0){
            cout << right << setw(OUTPUT_WIDTH) << "Regular Hourly Rate Pay: " << "$" << fixed << setprecision(2) << RegularPay << endl;
            OutputFile << right << setw(OUTPUT_WIDTH) << "Regular Hourly Rate Pay: " << "$" << fixed << setprecision(2) << RegularPay << endl;
        };
        if (IncreasedPay > 0){
            cout << right << setw(OUTPUT_WIDTH) << "Time And A Half Rate Pay: " << "$" << fixed << setprecision(2) << IncreasedPay << endl;
            OutputFile << right << setw(OUTPUT_WIDTH) << "Time And A Half Rate Pay: " << "$" << fixed << setprecision(2) << IncreasedPay << endl;
        };
        if (MaxPay > 0){
            cout << right << setw(OUTPUT_WIDTH) << "2.5 Times Rate Pay: " << "$" << fixed << setprecision(2) << MaxPay << endl;
            OutputFile << right << setw(OUTPUT_WIDTH) << "2.5 Times Rate Pay: " << "$" << fixed << setprecision(2) << MaxPay << endl;
        };
        cout << right << setw(OUTPUT_WIDTH) << "Total Pay: " << "$" << fixed << setprecision(2) << TotalPay << endl;
        OutputFile << right << setw(OUTPUT_WIDTH) << "Total Pay: " << "$" << fixed << setprecision(2) << TotalPay << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        OutputFile << "--------------------------------------------------------------------------------" << endl;
    };
    //Close Input & Output Files
    InputFile.close();
    OutputFile.close();
    cout << endl << "[SYSTEM_MESSAGE] Program Terminated..." << endl;
    return 0;
};
