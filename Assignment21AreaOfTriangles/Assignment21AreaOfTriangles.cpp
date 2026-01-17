/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 21 Area Of Triangles
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/7/2024
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
const string SYSTEM_ERROR_INVALID_INPUT = "[SYSTEM ERROR] Invalid Input!", OUTPUT_FILE_NAME = "triangles.txt";
const double SEMI_PERIMETER_DIVIDER = 2;
const int DECIMAL_PRECISION = 4, OUTPUT_WIDTH = 30;
void GetSides(double &SideA, double &SideB, double &SideC);
double AreaOfTriangle(double SideA, double SideB, double SideC);
int main(){
    cout << "Area Of Triangles Calculator (R)" << endl << endl;
    int CurrentTriangle = 1;
    string UserInput;
    ofstream OutputFile;
    OutputFile.open(OUTPUT_FILE_NAME);
    if (!OutputFile.fail() && OutputFile.is_open()){
        do{
            double TriangleSideA = 0, TriangleSideB = 0, TriangleSideC = 0, TriangleArea = 0;
            GetSides(TriangleSideA,TriangleSideB,TriangleSideC);
            TriangleArea = AreaOfTriangle(TriangleSideA,TriangleSideB,TriangleSideC);
            OutputFile << "-----------------------------------------------------------------------------------------------" << endl;
            OutputFile << fixed << setprecision(DECIMAL_PRECISION) << "Triangle: " <<  CurrentTriangle << endl;
            OutputFile << right << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PRECISION) << "Triangle Side A: " << TriangleSideA << endl;
            OutputFile << right << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PRECISION) << "Triangle Side B: " << TriangleSideB << endl;
            OutputFile << right << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PRECISION) << "Triangle Side C: " << TriangleSideC << endl;
            if (TriangleArea <= 0){
                cout << endl << "[SYSTEM ERROR] Invalid Triangle!" << endl;
                OutputFile << right << setw(OUTPUT_WIDTH) << "Triangle Area: " << "Invalid Triangle!" << endl;
            }else{
                cout << endl << fixed << setprecision(DECIMAL_PRECISION) << "The Area Of The Triangle Is: " << TriangleArea << endl;
                OutputFile << right << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PRECISION) << "Triangle Area: " << TriangleArea << endl;
            };
            OutputFile << "-----------------------------------------------------------------------------------------------" << endl;
            CurrentTriangle++;
            do{
                cout << "Please Enter 'y' If You Would Like To Input Another Triangle, Otherwise Enter 'n' (Without Quotes)..." << endl;
                cin >> ws;
                getline(cin,UserInput);
                if (UserInput != "y" && UserInput != "n"){
                    cout << SYSTEM_ERROR_INVALID_INPUT << endl;
                };
            }while(UserInput != "y" && UserInput != "n");
        }while(UserInput != "n");
    }else{
        cout << "[SYSTEM CATASTROPHIC ERROR] Output File Could Not Open Or Another Error Has Occurred!" << endl;
    };
    OutputFile.close();
    cout << endl << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: GetSides
Purpose: Get Sides Of A Triangle From User Inputs
Incoming: Side A (Double), Side B (Double), Side C (Double)
Outgoing: Side A (Double), Side B (Double), Side C (Double)
Return: Void
*/
void GetSides(double &SideA, double &SideB, double &SideC){
    if (SideA == 0 && SideB == 0 && SideC == 0){
        do{
            cout << "Please Enter First Triangle Side (1/3) (Must Be > 0)..." << endl;
            cin >> SideA;
            if (SideA <= 0){
                cout << SYSTEM_ERROR_INVALID_INPUT << endl;
            };
        }while(SideA <= 0);
        do{
            cout << "Please Enter Second Triangle Side (2/3) (Must Be > 0)..." << endl;
            cin >> SideB;
            if (SideB <= 0){
                cout << SYSTEM_ERROR_INVALID_INPUT << endl;
            };
        }while(SideB <= 0);
        do{
            cout << "Please Enter Third Triangle Side (3/3) (Must Be > 0)..." << endl;
            cin >> SideC;
            if (SideC <= 0){
                cout << SYSTEM_ERROR_INVALID_INPUT << endl;
            };
        }while(SideC <= 0);
        GetSides(SideA,SideB,SideC);
    }else if (SideA > SideB){
        double TempSideA = SideA;
        SideA = SideB;
        SideB = TempSideA;
        GetSides(SideA,SideB,SideC);
    }else if (SideB > SideC){
        double TempSideB = SideB;
        SideB = SideC;
        SideC = TempSideB;
        GetSides(SideA,SideB,SideC);
    };
};
/*
Name: AreaOfTriangle
Purpose: Calculate Area Of A Triangle
Incoming: Side A (Double), Side B (Double), Side C (Double)
Outgoing: Computed Triangle Area (Double)
Return: Computed Triangle Area (Double)
*/
double AreaOfTriangle(double SideA, double SideB, double SideC){
    double ComputedTriangleArea = -1;
    if (SideA + SideB > SideC){
        double SemiPerimeter = (SideA + SideB + SideC) / SEMI_PERIMETER_DIVIDER;
        ComputedTriangleArea = sqrt(SemiPerimeter * (SemiPerimeter - SideA) * (SemiPerimeter - SideB) * (SemiPerimeter - SideC));
    };
    return ComputedTriangleArea;
};
