/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 13 Using For Loops A
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/19/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
const int WIDTH = 4;
const double OCEAN_LEVEL_INCREASE = 2.3;
int main(){
    int CurrentYear = 2024, FinalYear = CurrentYear + 35;
    double OceanLevel = 0;
    cout << "Program A: Ocean Level Increase At A Rate Of 2.3 Millimeters Per Year." << endl << endl;
    cout << "Year     Risen" << endl;
    for (int Index = CurrentYear; Index < FinalYear; Index++){
        OceanLevel+=OCEAN_LEVEL_INCREASE;
        cout << left << setw(WIDTH) << CurrentYear << "     " << fixed << setprecision(3) << OceanLevel << " mm" << endl;
        CurrentYear++;
    };
    cout << endl << "The Ocean's Level Will Have Risen " << OceanLevel << " mm After 35 Years." << endl << endl;
    return 0;
};
