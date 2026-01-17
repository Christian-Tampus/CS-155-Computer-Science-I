/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 27 Array Manipulations
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/15/2024
*/
#include <iostream>
#include <string>
#include <fstream>
#include <climits>
using namespace std;
const string TXT_SUFFIX = ".txt", ADD_OPERATION = "ADD", REMOVE_OPERATION = "REMOVE", INVALID_INPUT = "[SYSTEM MESSAGE] Invalid Input!";
const string MenuOptionsArray[4] = {"[1] Display The Inventory Of All Stores","[2] Add Some Golf Club Sets To A Store","[3] Remove Some Golf Club Sets From A Store","[4] Quit The Program"};
void GetUserInput(int &UserInput, string COUT, int InputValidation1, int InputValidation2 = INT_MIN);
void DisplayMenu(int InputArray[], int InputArraySize);
void UpdateInventory(int InputArray[], int InputArraySize, string Operation);
int main(){
    cout << "Golf Club Inventory Tracker (R) Developed By: Elite Studios Development Group (TM)" << endl << endl;
    int InputStoreCount;
    string UserInputFileName;
    fstream InputFile;
    do{
        cout << "Please Enter Inventory File To Read..." << endl;
        cin >> ws;
        getline(cin,UserInputFileName);
        if (UserInputFileName.size() <= TXT_SUFFIX.size() || UserInputFileName.size() > TXT_SUFFIX.size() && UserInputFileName.compare(UserInputFileName.size()-TXT_SUFFIX.size(),TXT_SUFFIX.size(),TXT_SUFFIX) != 0){
            UserInputFileName+=TXT_SUFFIX;
        };
        cout << UserInputFileName << endl;
        InputFile.open(UserInputFileName,ios::in|ios::out);
        cout << (InputFile.fail() ? "Inventory File Name: "+UserInputFileName+" Does Not Exist!" : "Inventory File Name: "+UserInputFileName+" Successfully Opened!" ) << endl;
    }while(InputFile.fail() && !InputFile.is_open());
    InputFile >> InputStoreCount;
    int InitialDataArray[InputStoreCount+1];
    InitialDataArray[0] = InputStoreCount;
    for (int Index = 1; Index <= InputStoreCount; Index++) {
        InputFile >> InitialDataArray[Index];
    };
    DisplayMenu(InitialDataArray,InputStoreCount+1);
    //This Took A While To Fix The Bugs Due To File Pointer Positioning & Memory/Writing Issues >:(
    InputFile.close();
    InputFile.open(UserInputFileName,ios::out|ios::trunc);
    for (int Index = 0; Index < InputStoreCount+1; Index++){
        InputFile << InitialDataArray[Index] << endl ;
    };
    InputFile.close();
    cout << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: GetUserInput
Purpose: Gets User Input
Incoming: User Input (Integer), COUT (String), Input Validation 1 (Integer), Input Validation 2 (Integer)
Outgoing: User Input (Integer)
Return: Void
*/
void GetUserInput(int &UserInput, string COUT, int InputValidation1, int InputValidation2){
    if (InputValidation2 == INT_MIN){
        do{
            cout << COUT;
            cin >> UserInput;
            if (UserInput <= InputValidation1){
                cout << INVALID_INPUT << endl;
            };
        }while(UserInput <= InputValidation1);
    }else{
        do{
            cout << COUT;
            cin >> UserInput;
            if (UserInput < InputValidation1 || UserInput > InputValidation2){
                cout << INVALID_INPUT << endl;
            };
        }while(UserInput < InputValidation1 || UserInput > InputValidation2);
    };
};
/*
Name: DisplayMenu
Purpose: Display Menu
Incoming: Input Array (Array), Input Array Size (Integer)
Outgoing: Input Array (Array)
Return: Void
*/
void DisplayMenu(int InputArray[], int InputArraySize){
    for (int Index = 0; Index < sizeof(MenuOptionsArray)/sizeof(string); Index++){
        cout << MenuOptionsArray[Index] << endl;
    };
    int UserInput;
    GetUserInput(UserInput,"Enter Option [1-4]: ",1,4);
    switch(UserInput){
        case 1:
            cout << endl;
            for (int Index = 1; Index < InputArraySize; Index++){
                cout << "Store #[" + to_string(Index) + "] Inventory: " << InputArray[Index] << endl;
            };
            cout << endl;
            DisplayMenu(InputArray,InputArraySize);
            break;
        case 2:
            UpdateInventory(InputArray,InputArraySize,ADD_OPERATION);
            DisplayMenu(InputArray,InputArraySize);
            break;
        case 3:
            UpdateInventory(InputArray,InputArraySize,REMOVE_OPERATION);
            DisplayMenu(InputArray,InputArraySize);
            break;
        case 4:
            cout << endl << "[SYSTEM MESSAGE] Quiting Program..." << endl << endl;
            break;
    };
};
/*
Name: UpdateInventory
Purpose: Update Inventory
Incoming: Input Array (Array), Input Array Size (Integer), Operation (String)
Outgoing: Input Array (Array)
Return: Void
*/
void UpdateInventory(int InputArray[], int InputArraySize, string Operation){
    cout << endl;
    int StoreIdUserInput;
    GetUserInput(StoreIdUserInput,"Enter Store #[ID] (Valid Input Range: 1-" + to_string(InputArray[0]) + "): ",1,InputArray[0]);
    if (Operation == ADD_OPERATION){
        int AddValue;
        GetUserInput(AddValue,"Enter The Number Of Golf Club Sets To Add To Store #[" + to_string(StoreIdUserInput) + "] (Valid Input Range: >= 0): ",-1);
        InputArray[StoreIdUserInput]+=AddValue;
        cout << endl << "[SYSTEM MESSAGE] " + to_string(AddValue) + " Golf Club Set(s) Have Been Added To Store #[" + to_string(StoreIdUserInput) + "]" << endl << endl;
    }else{
        int RemoveValue;
        GetUserInput(RemoveValue,"Enter The Number Of Golf Club Sets To Remove From Store #[" + to_string(StoreIdUserInput) + "] (Valid Input Range: 0-" + to_string(InputArray[StoreIdUserInput]) + "): ",0,InputArray[StoreIdUserInput]);
        InputArray[StoreIdUserInput]-=RemoveValue;
        cout << endl << "[SYSTEM MESSAGE] " + to_string(RemoveValue) + " Golf Club Set(s) Have Been Removed From Store #[" + to_string(StoreIdUserInput) + "]" << endl << endl;
    };
};
