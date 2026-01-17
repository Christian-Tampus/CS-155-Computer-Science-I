/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 2 Show Me The Money
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/4/2024
*/
#include <iostream>
using namespace std;
int main(){
    const int OneDollarVal = 1, FiveDollarVal = 5, TenDollarVal = 10, TwentyDollarVal = 20;
    int OneDollar, FiveDollar, TenDollar, TwentyDollar, TotalMoney;
    cout << "Give Me All Your Dollar Bills!" << endl;
    cin >> OneDollar;
    cout << "Give Me All Your Five Dollar Bills!" << endl;
    cin >> FiveDollar;
    cout << "Give Me All Your Ten Dollar Bills!" << endl;
    cin >> TenDollar;
    cout << "Give Me All Your Twenty Dollar Bills!" << endl;
    cin >> TwentyDollar;
    TotalMoney = (OneDollar * OneDollarVal) + (FiveDollar * FiveDollarVal) + (TenDollar * TenDollarVal) + (TwentyDollar * TwentyDollarVal);
    cout << "Show Me The Money! You Give: $" << TotalMoney << "; Thanks For The Cash!" << endl;
    return 0;
};
