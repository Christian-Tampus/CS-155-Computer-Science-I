/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 25 Array Manipulations
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/11/2024
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unordered_map>
using namespace std;
//Declare Constants & Function Prototypes
const string MenuOptionsArray[6] = {"[1] Fill Array In Order","[2] Fill Array In Reverse Order","[3] Fill Array In Random Order","[4] Display Array","[5] Quit","[6] Generate New Array"};
const string FillRandomOrderOptionsArray[2] = {"[1] Fill Random Values Into Array (Values: 20-30)","[2] Fill Random Order Of Current Array Values"};
void FillInOrder(int InputArray[], int ArraySize);
void FillReverseOrder(int InputArray[], int ArraySize);
void FillRandomOrder(int InputArray[], int ArraySize);
void DisplayArray(int InputArray[], int ArraySize);
void GenerateArrayValues(int InputArray[], int ArraySize);
int GetUserInput(int &InputSize);
void DisplayMenu(int InputArray[], int ArraySize);
void CustomSort(int InputArray[], int ArraySize, int &Index, bool IsReversed);
void RandomFill(int InputArray[], int ArraySize);
int main(){
    cout << "Array Manipulations Program (R)" << endl << endl;
    int InitialUserInputArraySize;
    int InitialArray[GetUserInput(InitialUserInputArraySize)];
    GenerateArrayValues(InitialArray,InitialUserInputArraySize);
    DisplayMenu(InitialArray,InitialUserInputArraySize);
    return 0;
};
/*
Name: FillInOrder
Purpose: Puts Values Into Array 1000, 1100, 1200, ...
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: Input Array (Array)
Return: Void
*/
void FillInOrder(int InputArray[], int ArraySize){
    int Index = 0;
    CustomSort(InputArray,ArraySize,Index,false);
    DisplayMenu(InputArray,ArraySize);
};
/*
Name: FillReverseOrder
Purpose: Puts Values Into Array 300, 295, 290, ...
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: Input Array (Array)
Return: Void
*/
void FillReverseOrder(int InputArray[], int ArraySize){
    int Index = 0;
    CustomSort(InputArray,ArraySize,Index,true);
    DisplayMenu(InputArray,ArraySize);
};
/*
Name: FillRandomOrder
Purpose: Puts Random Values Into Array Between 20 and 30 (Inclusive) Or Randomly Place Values Into Random Index;
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: Input Array (Array)
Return: Void
*/
void FillRandomOrder(int InputArray[], int ArraySize){
    int UserFillRandomOrderInputOption;
    do{
        cout << "Fill Array In Random Order Options..." << endl;
        for (int Index = 0; Index < sizeof(FillRandomOrderOptionsArray)/sizeof(string); Index++){
            cout << FillRandomOrderOptionsArray[Index] << endl;
        };
        cin >> UserFillRandomOrderInputOption;
        if (UserFillRandomOrderInputOption < 1 || UserFillRandomOrderInputOption > 2){
            cout << "[SYSTEM ERROR] Invalid Input!" << endl;
        };
    }while(UserFillRandomOrderInputOption < 1 || UserFillRandomOrderInputOption > 2);
    cout << endl;
    switch(UserFillRandomOrderInputOption){
        case 1:
            for (int Index = 0; Index < ArraySize; Index++){
                InputArray[Index] = 20+(rand() % 11);
            };
            cout << "[SYSTEM MESSAGE] Array Fill Random Values Into Array (Values: 20-30) Operation Completed..." << endl << endl;
            break;
        case 2:
            RandomFill(InputArray,ArraySize);
            cout << "[SYSTEM MESSAGE] Array Fill Random Order Of Current Array Values Operation Completed..." << endl << endl;
            break;
    };
    DisplayMenu(InputArray,ArraySize);
};
/*
Name: DisplayArray
Purpose: Prints Values To Screen, 5 Per Line, In A Nice Tabular Format
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: None
Return: Void
*/
void DisplayArray(int InputArray[], int ArraySize){
    int MaxNumber = InputArray[0];
    for (int Index = 0; Index < ArraySize; Index++){
        MaxNumber = (InputArray[Index] > MaxNumber ? InputArray[Index] : MaxNumber);
    };
    int MaxWidth = to_string(MaxNumber).length();
    for (int Index = 0; Index < ArraySize; Index ++){
        cout << right << setfill('_') << setw(MaxWidth+5) << to_string(InputArray[Index]) + "     " << ((Index+1) % 5 == 0 ? "\n" : "");
    };
    cout << endl;
    DisplayMenu(InputArray,ArraySize);
};
/*
Name: GenerateArrayValues
Purpose: Generates Random Values For An Array
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: Input Array (Array)
Return: Void
*/
void GenerateArrayValues(int InputArray[], int ArraySize){
    srand(time(0));
    for (int Index = 0; Index < ArraySize; Index++){
        InputArray[Index] = rand() % RAND_MAX;
    };
};
/*
Name: GetUserInput
Purpose: Gets User Input For Array Size
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: Input Array (Array)
Return: Void
*/
int GetUserInput(int &InputSize){
    do{
        cout << "Please Enter How Many Numbers Would You Like (Must Be 1-100)..." << endl;
        cin >> InputSize;
        if (InputSize < 1 || InputSize > 100){
            cout << "[SYSTEM ERROR] Invalid Input!" << endl;
        };
    }while(InputSize < 1 || InputSize > 100);
    cout << endl;
    return InputSize;
};
/*
Name: DisplayMenu
Purpose: Does Stuff :D
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: Stuff Goes Out :D
Return: Void
*/
void DisplayMenu(int InputArray[], int ArraySize){
    int UserMenuInputOption;
    do{
        cout << "Please Select Which Option To Run..." << endl;
        for (int Index = 0; Index < sizeof(MenuOptionsArray)/sizeof(string); Index++){
            cout << MenuOptionsArray[Index] << endl;
        };
        cin >> UserMenuInputOption;
        if (UserMenuInputOption < 1 || UserMenuInputOption > 6){
            cout << "[SYSTEM ERROR] Invalid Input!" << endl;
        };
    }while(UserMenuInputOption < 1 || UserMenuInputOption > 6);
    cout << endl;
    switch(UserMenuInputOption){
        case 1:
            FillInOrder(InputArray,ArraySize);
            break;
        case 2:
            FillReverseOrder(InputArray,ArraySize);
            break;
        case 3:
            FillRandomOrder(InputArray,ArraySize);
            break;
        case 4:
            DisplayArray(InputArray,ArraySize);
            break;
        case 5:
            cout << "[SYSTEM MESSAGE] Program Terminated..." << endl;
            break;
        case 6:
            int NewInput;
            int NewArray[GetUserInput(NewInput)];
            GenerateArrayValues(NewArray,NewInput);
            DisplayMenu(NewArray,NewInput);
            break;
    };
};
/*
Name: CustomSort
Purpose: Sorts In Order Or Reverse Order
Incoming: Input Array (Array), Array Size (Integer), Index (Integer), Is Reversed (Boolean)
Outgoing: Input Array (Array), Array Size (Integer), Index (Integer)
Return: Void
*/
void CustomSort(int InputArray[], int ArraySize, int &Index, bool IsReversed){
    if (IsReversed == false){
        if (Index == ArraySize-1 && InputArray[Index] > InputArray[Index-1]){
            cout << "[SYSTEM MESSAGE] Array Fill In Order Operation Completed..." << endl << endl;
        }else{
            if (Index > 0 && InputArray[Index] < InputArray[Index-1]){
                int Temp = InputArray[Index];
                InputArray[Index] = InputArray[Index-1];
                InputArray[Index-1] = Temp;
                Index--;
                CustomSort(InputArray,ArraySize,Index,IsReversed);
            }else{
                Index++;
                CustomSort(InputArray,ArraySize,Index,IsReversed);
            };
        };
    }else{
        if (Index == 0 && InputArray[Index] > InputArray[Index+1]){
            cout << "[SYSTEM MESSAGE] Array Fill In Reverse Operation Completed..." << endl << endl;
        }else{
            if (Index < ArraySize-1 && InputArray[Index] < InputArray[Index+1]){
                int Temp = InputArray[Index];
                InputArray[Index] = InputArray[Index+1];
                InputArray[Index+1] = Temp;
                Index++;
                CustomSort(InputArray,ArraySize,Index,IsReversed);
            }else{
                Index--;
                CustomSort(InputArray,ArraySize,Index,IsReversed);
            };
        };
    };
};
/*
Name: RandomFill
Purpose: Fill Random Order Of Current Array Values
Incoming: Input Array (Array), Array Size (Integer)
Outgoing: Input Array (Array), Array Size (Integer)
Return: Void
*/
void RandomFill(int InputArray[], int ArraySize){
    unordered_map<int, int> UnusedIndexMap;
    for (int Index = 0; Index < ArraySize; Index++){
        UnusedIndexMap[Index] = Index;
    };
    for (int Index = 0; Index < ArraySize; Index++){
        int RandomIndex;
        do{
            RandomIndex = UnusedIndexMap[rand() % UnusedIndexMap.size()];
        }while(RandomIndex == Index);
        int Temp = InputArray[Index];
        InputArray[Index] = InputArray[RandomIndex];
        InputArray[RandomIndex] = Temp;
        UnusedIndexMap.erase(RandomIndex);
    };
};
