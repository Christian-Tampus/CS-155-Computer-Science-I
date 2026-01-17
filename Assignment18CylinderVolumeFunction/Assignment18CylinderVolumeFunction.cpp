/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 18 Cylinder Volume Function
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/28/2024
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//Declare Global Constant Variables & Function Prototype
double CalculateCylinderVolume(double Radius, double Height);
int main(){
    //Declare Local Variables
    string CylinderColor, UserInput;
    cout << "Cylinder Volume Calculator (R)" << endl << endl;
    //Core Loop
    do{
        //Declare Local Variables
        double InputRadius = 0, InputHeight = 0;
        cout << "Please Enter The Cylinder Color (Example: Blue)..." << endl;
        cin >> CylinderColor;
        while (InputRadius <= 0){ //Continues To Request Cylinder Radius Input If It Is <= 0
            cout << "Please Enter The Cylinder Radius (Example: 12.34, Must Be > 0)..." << endl;
            cin >> InputRadius;
            if (InputRadius <= 0){
                cout << "[SYSTEM ERROR] Cylinder Radius Input Is <= 0, Please Try Again!" << endl;
            };
        };
        while (InputHeight <= 0){ //Continues To Request Cylinder Height Input If It Is <= 0
            cout << "Please Enter The Cylinder Height (Example: 56.78, Must Be > 0)..." << endl;
            cin >> InputHeight;
            if (InputHeight <= 0){
                cout << "[SYSTEM ERROR] Cylinder Height Input Is <= 0, Please Try Again!" << endl;
            };
        };
        cout << "Cylinder Color: " + CylinderColor << " Cylinder Radius: " << InputRadius << " Cylinder Height: " << InputHeight << " Cylinder Volume: " << fixed << setprecision(1) << CalculateCylinderVolume(InputRadius,InputHeight) << endl;
        do{
            cout << "Input 'yes' If You Would Like To Calculate Another Cylinder, Otherwise Input 'no' (Without Quotes)..." << endl;
            cin >> UserInput;
            if (UserInput != "yes" && UserInput != "no"){ //Checks If User Input Is Not 'yes' Or 'no' To Display Invalid Input
                cout << "[SYSTEM ERROR] Invalid Input, Try Again!" << endl;
            };
        }while(UserInput != "yes" && UserInput != "no"); //Ends Loop If User Enters A Valid Input Of 'yes' Or 'no'
    }while(UserInput != "no"); //Ends Loop If User Input Equals 'no'
    cout << endl << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: CalculateCylinderVolume
Purpose: Calculate Cylinder Volume
Incoming: Cylinder Radius (Double), Cylinder Height (Double)
Outgoing: Cylinder Volume (Double)
Return: Cylinder Volume (Double)
*/
double CalculateCylinderVolume(double Radius, double Height){
    return (M_PI * pow(Radius,2) * Height);
};
