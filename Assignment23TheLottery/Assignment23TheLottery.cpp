/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 23 The Lottery
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/8/2024
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;
const int MIN_INPUT = 5, MAX_INPUT = 100, LOTTERY_RANGE = 9999, INCREMENT = 1, OUTPUT_WIDTH = 4;
const string OUTPUT_FILE_NAME = "lottery.txt";
const char OUTPUT_SET_FILL_CHAR = '0';
int main(){
    ofstream OutputFile;
    OutputFile.open(OUTPUT_FILE_NAME);
    cout << "Lottery Number Generator (R)" << endl << endl;
    if (!OutputFile.fail() && OutputFile.is_open()){
        srand(time(0));
        int UserInput;
        do{
            cout << "Please Enter How Many Lottery Numbers To Generate (Must Be An Integer In Range " << MIN_INPUT << "-" << MAX_INPUT << ")..." << endl;
            cin >> UserInput;
            if (UserInput < MIN_INPUT || UserInput > MAX_INPUT){
                cout << "[SYSTEM ERROR] Invalid Input!" << endl;
            };
        }while(UserInput < MIN_INPUT || UserInput > MAX_INPUT);
        for (int Index = 0; Index < UserInput; Index++){
            OutputFile << "[Lottery Ticket " << (Index + 1) << "] " << setfill(OUTPUT_SET_FILL_CHAR) << setw(OUTPUT_WIDTH) << ((rand() % LOTTERY_RANGE) + INCREMENT) << endl;
        };
        cout << endl << "[SYSTEM MESSAGE] " << UserInput << " Lottery Numbers Have Been Generated And Written To File '" << OUTPUT_FILE_NAME << "' Successfully!" << endl;
    }else{
        cout << "[SYSTEM CATASTROPHIC ERROR] Output File Could Not Open Or Another Error Has Occurred!" << endl;
    };
    OutputFile.close();
    cout << endl << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
