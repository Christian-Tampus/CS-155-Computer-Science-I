/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 25 Reading And Writing Files
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/12/2024
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
const string TXT_SUFFIX = ".txt";
int main(){
    cout << "File Reader X-TREME (R)" << endl << endl;
    string UserInputFileName, UserOuputFileName;
    ifstream InputFile;
    ofstream OutputFile;
    int Lines = 0, Index = 0;
    bool SameInputFile = false;
    do{
        cout << "Please Enter File To Read..." << endl;
        cin >> ws;
        getline(cin,UserInputFileName);
        if (UserInputFileName.size() <= TXT_SUFFIX.size() || UserInputFileName.size() > TXT_SUFFIX.size() && UserInputFileName.compare(UserInputFileName.size()-TXT_SUFFIX.size(),TXT_SUFFIX.size(),TXT_SUFFIX) != 0){
            UserInputFileName+=TXT_SUFFIX;
        };
        cout << UserInputFileName << endl;
        InputFile.open(UserInputFileName);
        cout << (InputFile.fail() ? "Read File Name: "+UserInputFileName+" Does Not Exist!" : "Read File Name: "+UserInputFileName+" Successfully Opened!" ) << endl;
    }while(InputFile.fail() && !InputFile.is_open());
    do{
        SameInputFile = false;
        cout << "Please Enter File To Write..." << endl;
        cin >> ws;
        getline(cin,UserOuputFileName);
        if (UserOuputFileName.size() <= TXT_SUFFIX.size() || UserOuputFileName.size() > TXT_SUFFIX.size() && UserOuputFileName.compare(UserOuputFileName.size()-TXT_SUFFIX.size(),TXT_SUFFIX.size(),TXT_SUFFIX) != 0){
            UserOuputFileName+=TXT_SUFFIX;
        };
        if (UserInputFileName == UserOuputFileName){
            SameInputFile = true;
            cout << "[SYSTEM ERROR] Attempting To Write To The Read File, Please Enter Another File Name!" << endl;
        }else{
            OutputFile.open(UserOuputFileName);
            cout << (OutputFile.fail() ? "Write File Name: "+UserOuputFileName+" Does Not Exist!" : "Write File Name: "+UserOuputFileName+" Successfully Opened!" ) << endl;
        };
    }while(OutputFile.fail() && !OutputFile.is_open() || SameInputFile == true);
    while(!InputFile.eof()){
        string Temp;
        getline(InputFile,Temp);
        Lines++;
    };
    InputFile.clear();
    InputFile.seekg(0);
    double InputFileDataArray[2][Lines];
    while(!InputFile.eof()){
        InputFile >> InputFileDataArray[0][Index];
        InputFile >> InputFileDataArray[1][Index];
        double Num1 = InputFileDataArray[0][Index];
        double Num2 = InputFileDataArray[1][Index];
        OutputFile << fixed << setprecision(1) << Num1 << " " << Num2 << " Product: " << (Num1 * Num2) << " Quotient: " << (Num1 / Num2) << " Sum: " << (Num1 + Num2) << " Difference: " << (Num1 - Num2) << endl;
        Index++;
    };
    InputFile.close();
    OutputFile.close();
    cout << endl << "[SYSTEM MESSAGE] Successfully Read From Input File: "+UserInputFileName+" And Wrote To Output File: "+UserOuputFileName+" With Both Numbers, Product, Quotient, Sum & Difference..." << endl;
    cout << endl << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
