/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 19 House Upgrade Functions
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/30/2024
Sources:
1. Carpet Cost Per Square Foot: https://www.fixr.com/costs/carpet-installation#:~:text=National%20Average%20Range%3A,ft.)
2. Paint Cost Per Square Foot: https://www.improovy.com/blog/interior-painting-cost#:~:text=cost%20for%20each.-,Walls,want%20the%20job%20done%20right.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//Declare Global Constants & Function Prototypes
const double INCHES_TO_FEET_DIVIDER = 12, WALL_AREA_MULTIPLIER = 2, CARPET_COST_MULTIPLIER = 4.99, PAINT_COST_MULTIPLIER = 1.95;
const string INVALID_INPUT_MESSAGE = "[SYSTEM ERROR] Invalid Input, Try Again!";
double CalculateCarpetRequired(double RoomLength, double RoomWidth);
double CalculatePaintRequired(double RoomLength, double RoomWidth, double RoomHeight);
int main(){
    //Declare Local Variables
    string UserInput;
    double TotalCarpetCost = 0, TotalPaintCost = 0, GrandTotalCost = 0;
    cout << "House Upgrades Calculator (R)..." << endl << endl;
    //Core Loop
    do{
        //Declare Local Variables
        string InputRoomName;
        double InputRoomLength, InputRoomWidth, InputRoomHeight, Carpet, Paint;
        cout << "Please Enter Room Name (Example: Living Room)..." << endl;
        cin >> ws;
        getline(cin,InputRoomName);
        do{
            cout << "Please Enter Room Length (Must Be > 0 & In Inches)..." << endl;
            cin >> InputRoomLength;
            if (InputRoomLength <= 0){ //Check If InputRoomLength Is <= 0 Then Outputs Error Message
                cout << INVALID_INPUT_MESSAGE << endl;
            };
        }while(InputRoomLength <= 0); //Continues To Loop Until User Enters InputRoomLength > 0
        do{
            cout << "Please Enter Room Width (Must Be > 0 & In Inches)..." << endl;
            cin >> InputRoomWidth;
            if (InputRoomWidth <= 0){ //Check If InputRoomWidth Is <= 0 Then Outputs Error Message
                cout << INVALID_INPUT_MESSAGE << endl;
            };
        }while(InputRoomWidth <= 0); //Continues To Loop Until User Enters InputRoomWidth > 0
        do{
            cout << "Please Enter Room Height (Must Be > 0 & In Inches)..." << endl;
            cin >> InputRoomHeight;
            if (InputRoomHeight <= 0){ //Check If InputRoomHeight Is <= 0 Then Outputs Error Message
                cout << INVALID_INPUT_MESSAGE << endl;
            };
        }while(InputRoomHeight <= 0); //Continues To Loop Until User Enters InputRoomHeight > 0
        //Call Functions To Calculate Carpet & Paint Requirements
        Carpet = CalculateCarpetRequired(InputRoomLength,InputRoomWidth);
        Paint = CalculatePaintRequired(InputRoomLength,InputRoomWidth,InputRoomHeight);
        //Calculate TotalCarpetCost, TotalPaintCost & GrandTotalCost
        TotalCarpetCost += (Carpet * CARPET_COST_MULTIPLIER);
        TotalPaintCost += (Paint * PAINT_COST_MULTIPLIER);
        GrandTotalCost += ((Carpet * CARPET_COST_MULTIPLIER) + (Paint * PAINT_COST_MULTIPLIER));
        //Output InputRoomName, InputRoomLength, InputRoomWidth, InputRoomHeight, Carpet & Paint
        cout << "--------------------------------------------------" << endl;
        cout << "> Room Name: " << InputRoomName << endl;
        cout << "> Room Length: " << InputRoomLength << " Inches" << endl;
        cout << "> Room Width: " << InputRoomWidth << " Inches" << endl;
        cout << "> Room Height: " << InputRoomHeight << " Inches" << endl;
        cout << "> Carpet Area Required: " << fixed << setprecision(1) << Carpet << " Square Feet" << endl;
        cout << "> Paint Area Required: " << fixed << setprecision(1) << Paint << " Square Feet" << endl;
        cout << "--------------------------------------------------" << endl;
        do{
            cout << "Type 'Y' If There Are More Rooms To Be Entered, Otherwise Type 'N' (Without Quotes)..." << endl;
            cin >> ws;
            getline(cin,UserInput);
            if (UserInput != "Y" && UserInput != "N"){ //Check If User Input Is Invalid Then Outputs Invalid Input Message
                cout << INVALID_INPUT_MESSAGE << endl;
            };
        }while(UserInput != "Y" && UserInput != "N"); //Continues To Loop Until User Enters A Valid Input
    }while(UserInput != "N"); //Continues To Loop Until User Enters 'N' Then Ends The Loop
    //Outputs TotalCarpetCost, TotalPaintCost & GrandTotalCost Then Terminates Program
    cout << "--------------------------------------------------" << endl;
    cout << "> Total Carpet Cost: $" << fixed << setprecision(2) << TotalCarpetCost << endl;
    cout << "> Total Paint Cost: $" << fixed << setprecision(2) << TotalPaintCost << endl;
    cout << "> Grand Total Cost: $" << fixed << setprecision(2) << GrandTotalCost << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: CalculateCarpetRequired
Purpose: Calculate Carpet Area Required For A Room
Incoming: Room Length (Double), Room Width (Double)
Outgoing: Carpet Area (Double)
Return: Carpet Area (Double)
*/
double CalculateCarpetRequired(double RoomLength, double RoomWidth){
    double RoomLengthFeet = RoomLength / INCHES_TO_FEET_DIVIDER;
    double RoomWidthFeet = RoomWidth / INCHES_TO_FEET_DIVIDER;
    double CarpetArea = RoomLengthFeet * RoomWidthFeet;
    return CarpetArea;
};
/*
Name: CalculatePaintRequired
Purpose: Calculate Paint Area Required For A Room
Incoming: Room Length (Double), Room Width (Double), Room Height (Double)
Outgoing: Paint Area (Double)
Return: Paint Area (Double)
*/
double CalculatePaintRequired(double RoomLength, double RoomWidth, double RoomHeight){
    double RoomLengthFeet = RoomLength / INCHES_TO_FEET_DIVIDER;
    double RoomWidthFeet = RoomWidth / INCHES_TO_FEET_DIVIDER;
    double RoomHeightFeet = RoomHeight / INCHES_TO_FEET_DIVIDER;
    double WallArea = ((RoomLengthFeet + RoomWidthFeet) * WALL_AREA_MULTIPLIER) * RoomHeightFeet;
    double CeilingArea = RoomLengthFeet * RoomWidthFeet;
    double PaintArea = WallArea + CeilingArea;
    return PaintArea;
};
