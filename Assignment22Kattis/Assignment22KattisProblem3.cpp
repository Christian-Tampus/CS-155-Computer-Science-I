/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 22 Kattis Problem 3
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/3/2024
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<char, bool> VowelsMap = {{'A',true},{'E',true},{'I',true},{'O',true},{'U',true}};
    string UserInput;
    int NumberOfVowels = 0;
    getline(cin,UserInput);
    for (int Index = 0; Index < UserInput.size(); Index++){
        if (VowelsMap[toupper(UserInput[Index])]){
            NumberOfVowels++;
        };
    };
    cout << NumberOfVowels;
    return 0;
};
