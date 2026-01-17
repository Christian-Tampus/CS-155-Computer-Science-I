/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 12 Dorm Occupancy Rate
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/15/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int Floors, CurrentFloor = 1, TotalRooms = 0, TotalOccupied = 0;
    double Percentage;
    cout << "Dorm Room Occupancy Rate Calculator (R) Version 1.0.0" << endl << endl;
    do{
        cout << "Please Enter How Many Floors The Residence Hall Has (Must Be >= 2 Floors)..." << endl;
        cin >> Floors;
    }while (Floors < 2);
    while (CurrentFloor <= Floors){
        int Rooms, Occupied;
        do{
            cout << "Please Enter The Number Of Rooms On Floor " << CurrentFloor << " (Must Be 4-30 Rooms)..." << endl;
            cin >> Rooms;
        }while (Rooms < 4 || Rooms > 30);
        //I Added Another Do While Loop To Validate Occupied Rooms Inputs
        do{
            cout << "Please Enter The Number Of Occupied Rooms On Floor " << CurrentFloor << " (Must Be 0-" << Rooms << " Rooms)..." << endl;
            cin >> Occupied;
        }while (Occupied < 0 || Occupied > Rooms);
        TotalRooms+=Rooms;
        TotalOccupied+=Occupied;
        CurrentFloor++;
    };
    Percentage = ((double)TotalOccupied/TotalRooms)*100;
    cout << "Total Floors: " << Floors << " Total Rooms: " << TotalRooms << " Total Occupied: " << TotalOccupied << " Percentage Occupied: " << fixed << setprecision(2) << Percentage << "%" << endl;
    return 0;
};
