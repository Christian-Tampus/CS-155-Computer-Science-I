/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 22 Kattis Problem 2
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/3/2024
*/
#include <iostream>
using namespace std;
int main(){
    int CurrentIndex = 0;
    string UserInput, Output;
    cin >> UserInput;
    for (int Index = 0; Index < UserInput.size(); Index++){
        if (UserInput[Index] == '-'){
            Output += UserInput[CurrentIndex];
            CurrentIndex = Index+1;
        }else if (Index == UserInput.size()-1){
            Output += UserInput[CurrentIndex];
        };
    };
    cout << Output << endl;
    return 0;
};
