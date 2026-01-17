/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 31 2D Arrays
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/24/2024
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int MENU_OPTIONS = 6, MAX_ROWS = 12, MAX_COLUMNS = 12, OUTPUT_WIDTH = 15;
const string MenuOptionsArray[MENU_OPTIONS] = {"[1] Fill The Matrix","[2] Print The Matrix In Row-Major","[3] Print The Matrix In Column-Major","[4] Print Column Sums","[5] Calculate The Product Of A Given Row","[6] Quit Program"};
const string TXT_SUFFIX = ".txt", OPERATION_ERROR = "[SYSTEM ERROR] You Must Fill The Matrix Before Doing This Operation!";
void DisplayMenu(int Matrix[MAX_ROWS][MAX_COLUMNS],int &RowSize, int &ColumnSize);
void GetUserInput(string COUT, int &UserInput,bool RequiresEndLine, int InputValidation1, int InputValidation2);
void FillMatrix(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize);
void PrintRowMajor(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize);
void PrintColumnMajor(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize);
void Printer(int Matrix[MAX_ROWS][MAX_COLUMNS], int RowSize, int ColumnSize, bool GetSum, string Major = "Row-Major");
void ColumnSums(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize);
int CalculateRowProduct(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize, int RowIndex, bool &HasCalculated);
int main(){
    cout << "2-Dimensional Integer Array Tester (R)" << endl;
    int Matrix[MAX_ROWS][MAX_COLUMNS];
    int RowSize = 0, ColumnSize = 0;
    DisplayMenu(Matrix,RowSize,ColumnSize);
    cout << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: DisplayMenu
Purpose: Displays Menu Of 6 Options
Incoming: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Outgoing: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Return: Void
*/
void DisplayMenu(int Matrix[MAX_ROWS][MAX_COLUMNS],int &RowSize, int &ColumnSize){
    int UserInput;
    cout << endl;
    for (int Index = 0; Index < MENU_OPTIONS; Index++){
        cout << MenuOptionsArray[Index] << endl;
    };
    cout << endl;
    GetUserInput("Please Select An Option From The Menu Above:",UserInput,false,1,6);
    switch(UserInput){
        case 1:
            FillMatrix(Matrix,RowSize,ColumnSize);
            break;
        case 2:
            PrintRowMajor(Matrix,RowSize,ColumnSize);
            break;
        case 3:
            PrintColumnMajor(Matrix,RowSize,ColumnSize);
            break;
        case 4:
            ColumnSums(Matrix,RowSize,ColumnSize);
            break;
        case 5:
            {
                bool HasCalculated = false;
                GetUserInput("Please Enter A Row To Calculate The Product (Must Be In Range 0-"+to_string(RowSize-1)+"):",UserInput,false,0,RowSize-1);
                int RowProduct = CalculateRowProduct(Matrix,RowSize,ColumnSize,UserInput,HasCalculated);
                if (HasCalculated) {
                    Printer(Matrix,RowSize,ColumnSize,false);
                    cout << "Row [" + to_string(UserInput) + "] Product: " + to_string(RowProduct) << endl;
                };
                DisplayMenu(Matrix,RowSize,ColumnSize);
                break;
            }
        case 6:
            cout << "[SYSTEM MESSAGE] Quitting Program..." << endl;
            break;
    };
};
/*
Name: GetUserInput
Purpose: Get User Input From (1-6)
Incoming: COUT (String), User Input (Integer), Requires End Line (Boolean), Input Validation 1 (Integer), InputValidation 2 (Integer)
Outgoing: User Input (Integer)
Return: Void
*/
void GetUserInput(string COUT, int &UserInput,bool RequiresEndLine, int InputValidation1, int InputValidation2){
    if (InputValidation2 > InputValidation1){
        do{
            cout << COUT;
            if (RequiresEndLine == true){
                cout << endl;
            };
            cin >> UserInput;
            if (UserInput < InputValidation1 || UserInput > InputValidation2){
                cout << "[SYSTEM MESSAGE] Invalid Input!" << endl;
            };
        }while(UserInput < InputValidation1 || UserInput > InputValidation2);
    };
};
/*
Name: FillMatrix
Purpose: Reads User Input File & Updates Matrix Values, Row Size & Column Size
Incoming: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Outgoing: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Return: Void
*/
void FillMatrix(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize){
    bool InvalidInputs = false;
    fstream InputFile;
    string UserInputFileName;
    do{
        cout << "Please Enter File To Read:";
        cin >> ws;
        getline(cin,UserInputFileName);
        if (UserInputFileName.size() <= TXT_SUFFIX.size() || UserInputFileName.size() > TXT_SUFFIX.size() && UserInputFileName.compare(UserInputFileName.size()-TXT_SUFFIX.size(),TXT_SUFFIX.size(),TXT_SUFFIX) != 0){
            UserInputFileName+=TXT_SUFFIX;
        };
        cout << UserInputFileName << endl;
        InputFile.open(UserInputFileName);
        cout << (InputFile.fail() ? "File Name: "+UserInputFileName+" Does Not Exist!" : "File Name: "+UserInputFileName+" Successfully Opened!" ) << endl;
    }while(InputFile.fail() && !InputFile.is_open());
    InputFile >> RowSize;
    InputFile >> ColumnSize;
    if (RowSize <= 0 || ColumnSize <= 0){
        cout << "[SYSTEM ERROR] File Has Invalid Row Or Column Sizes!" << endl;
        InvalidInputs = true;
    };
    if (!InvalidInputs){
        for (int Index1 = 0; Index1 < RowSize; Index1++){
            for (int Index2 = 0; Index2 < ColumnSize; Index2++){
                InputFile >> Matrix[Index1][Index2];
            };
        };
        InputFile.close();
        cout << "[SYSTEM MESSAGE] Successfully Filled The Matrix!" << endl;
        DisplayMenu(Matrix,RowSize,ColumnSize);
    };
};
/*
Name: PrintRowMajor
Purpose: Prints Matrix In Row-Major
Incoming: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Outgoing: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Return: Void
*/
void PrintRowMajor(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize){
    if (RowSize != 0 && ColumnSize != 0){
        Printer(Matrix,RowSize,ColumnSize,false);
    }else{
        cout << OPERATION_ERROR << endl;
    };
    DisplayMenu(Matrix,RowSize,ColumnSize);
};
/*
Name: PrintColumnMajor
Purpose: Prints Matrix In Column-Major
Incoming: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Outgoing: Matrix (2D Array), Row Size (Integer), Column Size (Integer)
Return: Void
*/
void PrintColumnMajor(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize){
    if (RowSize != 0 && ColumnSize != 0){
        Printer(Matrix,ColumnSize,RowSize,false,"Column-Major");
    }else{
        cout << OPERATION_ERROR << endl;
    };
    DisplayMenu(Matrix,RowSize,ColumnSize);
};
/*
Name: Printer
Purpose: Printer Go BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
Incoming: Matrix (2D Array), Row Size (Integer), Column Size (Integer), Get Sum (Boolean) ,Major (String)
Outgoing: Matrix (2D Array)
Return: Void
*/
void Printer(int Matrix[MAX_ROWS][MAX_COLUMNS], int RowSize, int ColumnSize, bool GetSum, string Major){
    cout << Major << endl << endl;
    cout << right << setw(OUTPUT_WIDTH) << "[Row x Col]";
    for (int Index = 0; Index < ColumnSize; Index++){
        cout << right << setw(OUTPUT_WIDTH) << "Col [" + to_string(Index) + "]";
    };
    cout << endl;
    for (int Index = 0; Index < ((ColumnSize+1)*OUTPUT_WIDTH); Index++){
        cout << "-";
    };
    cout << endl;
    for (int Index1 = 0; Index1 < RowSize; Index1++){
        cout << right << setw(OUTPUT_WIDTH) << "Row [" + to_string(Index1) + "]";
        for (int Index2 = 0; Index2 < ColumnSize; Index2++){
            if (Major == "Row-Major"){
                cout << right << setw(OUTPUT_WIDTH) << Matrix[Index1][Index2];
            }else{
                cout << right << setw(OUTPUT_WIDTH) << Matrix[Index2][Index1];
            };
        };
        cout << endl;
        for (int Index2 = 0; Index2 < ((ColumnSize+1)*OUTPUT_WIDTH); Index2++){
            cout << "-";
        };
        cout << endl;
    };
    if (GetSum){
        cout << right << setw(OUTPUT_WIDTH) << "[Col Sum]";
        for (int Index1 = 0; Index1 < ColumnSize; Index1++){
            int ColumnSum = 0;
            for (int Index2 = 0; Index2 < RowSize; Index2++){
                ColumnSum += Matrix[Index2][Index1];
            };
            cout << right << setw(OUTPUT_WIDTH) << ColumnSum;
        };
        cout << endl;
    };
};
/*
Name: ColumnSums
Purpose: Gets The Sum Of The Columns
Incoming: Matrix (2D Array), Row Size (Integer), Column Size (Integer), Major (String)
Outgoing: Matrix (2D Array)
Return: Void
*/
void ColumnSums(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize){
    if (RowSize != 0 && ColumnSize != 0){
         Printer(Matrix,RowSize,ColumnSize,true);
    }else{
        cout << OPERATION_ERROR << endl;
    };
    DisplayMenu(Matrix,RowSize,ColumnSize);
};
/*
Name: CalculateRowProduct
Purpose: Calculates A Row's Product
Incoming: Matrix (2D Array), Row Size (Integer), Column Size (Integer), Row Index (Integer), Has Calculated (Boolean)
Outgoing: Matrix (2D Array), Row Product (Integer), Has Calculated (Boolean)
Return: Row Product (Integer)
*/
int CalculateRowProduct(int Matrix[MAX_ROWS][MAX_COLUMNS], int &RowSize, int &ColumnSize, int RowIndex, bool &HasCalculated){
    int RowProduct = 0;
    if (RowSize != 0 && ColumnSize != 0){
        RowProduct = Matrix[RowIndex][0];
        if (ColumnSize > 1){
            for (int Index = 1; Index < ColumnSize; Index++){
                RowProduct *= Matrix[RowIndex][Index];
            };
        };
        HasCalculated = true;
    }else{
        cout << OPERATION_ERROR << endl;
    };
    return RowProduct;
};
