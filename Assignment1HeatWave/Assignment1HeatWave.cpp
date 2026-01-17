/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 1 Heat Wave.
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/3/2024
*/
#include <iostream>
using namespace std;
bool FindItem(int InputArray[][20], int Row, int Col, int Item);
int main(){
    int SampleArray[2][20] = {{1,2},{3,4}};
    int ItemToFind = 4;
    if (FindItem(SampleArray,3,3,ItemToFind)){
        cout << "ITEM FOUND!" << endl;
    }else{
        cout << "ITEM NOT FOUND!" << endl;
    };
    return 0;
};
bool FindItem(int InputArray[][20], int Row, int Col, int Item){
    for (int Index1 = 0; Index1 < Row; Index1++){
        for(int Index2 = 0; Index2 < Col; Index2++){
            if (InputArray[Index1][Index2] == Item){
                return true;
            };
        };
    };
    return false;
};
