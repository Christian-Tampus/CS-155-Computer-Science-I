/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 7 A Data Validation
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/6/2024
*/
#include <iostream>
using namespace std;
const int INVALID_INPUT_VALUE = -20;
const string INVALID_INPUT_TEXT = "Data is not valid";
int main(){
    double Temp1, Temp2, Temp3, Temp4, AvgTemp;
    cout << "Enter Temperature (1/4) In Fahrenheit..." << endl;
    cin >> Temp1;
    if (Temp1 < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Enter Temperature (2/4) In Fahrenheit..." << endl;
    cin >> Temp2;
    if (Temp2 < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Enter Temperature (3/4) In Fahrenheit..." << endl;
    cin >> Temp3;
    if (Temp3 < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Enter Temperature (4/4) In Fahrenheit..." << endl;
    cin >> Temp4;
    if (Temp4 < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    AvgTemp = (Temp1 + Temp2 + Temp3 + Temp4)/4;
    cout << "The Average Temperature Is " << AvgTemp << " Fahrenheit." << endl;
    return 0;
};
