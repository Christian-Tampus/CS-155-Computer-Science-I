/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 29 Searching
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/20/2024
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
const string TXT_SUFFIX = ".txt";
void GetUserInput(string COUT, string &UserInput, string InputValidation1 = "None", string InputValidation2 = "None");
void LinearSearch2(const string InputArray[], int InputArraySize, string Comparison, int InstancesArray[]);
int main(){
    cout << "LinearSearch2 (R)" << endl;
    cout << "A More Powerful Linear Search To Find All Instances Of Exact Or Similar Matching Of Desired Search Input :)" << endl;
    cout << "LinearSearch2 Is Not Case Sensitive So Type Away! :)" << endl << endl;
    int Lines = 0, ArraySize;
    string UserInputFileName, Temp, UserInputSearchBy, UserInputSearchValue,IdOrName;
    ifstream InputFile;
    do{
        cout << "Please Enter Hardware File To Read..." << endl;
        cin >> ws;
        getline(cin,UserInputFileName);
        if (UserInputFileName.size() <= TXT_SUFFIX.size() || UserInputFileName.size() > TXT_SUFFIX.size() && UserInputFileName.compare(UserInputFileName.size()-TXT_SUFFIX.size(),TXT_SUFFIX.size(),TXT_SUFFIX) != 0){
            UserInputFileName+=TXT_SUFFIX;
        };
        cout << UserInputFileName << endl;
        InputFile.open(UserInputFileName);
        cout << (InputFile.fail() ? "Inventory File Name: "+UserInputFileName+" Does Not Exist!" : "Inventory File Name: "+UserInputFileName+" Successfully Opened!" ) << endl;
    }while(InputFile.fail() && !InputFile.is_open());
    while(getline(InputFile,Temp)){
        Lines++;
    };
    ArraySize = Lines/2;
    InputFile.clear();
    InputFile.seekg(0,std::ios::beg);
    string ProductIdArray[ArraySize];
    string ProductNameArray[ArraySize];
    int InstancesArray[ArraySize];
    for (int Index = 0; Index < ArraySize; Index++){
        getline(InputFile,ProductIdArray[Index]);
        getline(InputFile,ProductNameArray[Index]);
    };
    do{
        GetUserInput("Please Enter 'id' To Search By Product Id Or 'name' To Search By Product Name (Without Quotes): ",UserInputSearchBy,"id","name");
        IdOrName = (UserInputSearchBy == "id" ? "Id" : "Name");
        GetUserInput("Please Enter Product " + IdOrName + " To Search For: ",UserInputSearchValue);
        LinearSearch2((UserInputSearchBy == "id" ? ProductIdArray : ProductNameArray),ArraySize,UserInputSearchValue,InstancesArray);
        if (InstancesArray[0] != -1){
            cout << "Search By Product " + IdOrName + ": " + UserInputSearchValue + " Instance(s) Found In The Data File!" << endl;
            for (int Index = 0; Index < ArraySize; Index++){
                if (InstancesArray[Index] != -1){
                    cout << "----------------------------------------------------------------------------------------------------" << endl;
                    cout << "Product Id: " + ProductIdArray[InstancesArray[Index]] << endl;
                    cout << "Product Name: " + ProductNameArray[InstancesArray[Index]] << endl;
                    cout << "----------------------------------------------------------------------------------------------------" << endl;
                }else{
                    break;
                };
            };
        }else{
            cout << "Search By Product " + IdOrName + ": " + UserInputSearchValue + " Does Not Exist In The Data File!" << endl;
        };
        GetUserInput("To Search Again Type 'y' To Quit Program Type 'n' (Without Quotes): ",Temp,"y","n");
    }while(Temp != "n");
    InputFile.close();
    cout << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: GetUserInput
Purpose: Get User Input
Incoming: COUT (String), User Input (String), Input Validation 1 (String), Input Validation 2 (String)
Outgoing: User Input (String)
Return: Void
*/
void GetUserInput(string COUT, string &UserInput, string InputValidation1, string InputValidation2){
    if (InputValidation1 != InputValidation2){
        do{
            cout << COUT;
            getline(cin,UserInput);
            if (UserInput != InputValidation1 && UserInput != InputValidation2){
                cout << "[SYSTEM ERROR] Invalid Input!" << endl;
            };
        }while(UserInput != InputValidation1 && UserInput != InputValidation2);
    }else{
        cout << COUT;
        getline(cin,UserInput);
    };
};
/*
Name: LinearSearch2
Purpose: A More Powerful Linear Search To Find All Instances Of Exact Or Similar Matching Of Desired Search Input
Incoming: Input Array (String Array), Input Array Size (Integer), Comparison (String), Instances Array (Integer Array)
Outgoing: Instances Array (Integer Array)
Return: Void
*/
void LinearSearch2(const string InputArray[], int InputArraySize, string Comparison, int InstancesArray[]){
    string TempComparison = Comparison;
    transform(TempComparison.begin(),TempComparison.end(),TempComparison.begin(),::toupper);
    int InstancesArrayCurrentIndex = 0;
    for (int Index = 0; Index < InputArraySize; Index++){
        InstancesArray[Index] = -1;
    };
    for (int Index = 0; Index < InputArraySize; Index++){
        string TempArrayItem = InputArray[Index];
        transform(TempArrayItem.begin(),TempArrayItem.end(),TempArrayItem.begin(),::toupper);
        if (TempArrayItem == TempComparison || TempArrayItem.substr(0,TempComparison.length()) == TempComparison || TempArrayItem.find(TempComparison) != std::string::npos){
            InstancesArray[InstancesArrayCurrentIndex] = Index;
            InstancesArrayCurrentIndex++;
        };
    };
};
