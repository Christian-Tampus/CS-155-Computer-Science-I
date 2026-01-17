/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 10 Paying Your Taxes
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/13/2024
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const double TAX_RATE_6 = 0.06, TAX_RATE_12 = 0.12;
int main(){
    string FullName;
    double TaxableIncome, IncomeLevel, BaseOwed, TaxOwed;
    char FilingStatus;
    cout << "Federal Tax Calculator (R) Version [1.0.0]" << endl << endl;
    cout << "Please Enter Your Full Name..." << endl;
    getline(cin,FullName);
    cout << "Please Enter Your Total Taxable Income..." << endl;
    cin >> TaxableIncome;
    cout << "Please Enter Your Filing Status, Enter 's' For Single Or 'm' For Married (Without Quotations)..." << endl;
    cin >> FilingStatus;
    //I Refactored The If/Else Statements To Be More Simplified
    if (FilingStatus == 's'){
        IncomeLevel = 10000;
        BaseOwed = 600;
    }else{
        IncomeLevel = 20000;
        BaseOwed = 1200;
    };
    if (TaxableIncome <= IncomeLevel){
        TaxOwed = TaxableIncome * TAX_RATE_6;
    }else{
        TaxOwed = BaseOwed + ((TaxableIncome - IncomeLevel) * TAX_RATE_12);
    };
    cout << FullName << " Owe: $" << fixed << setprecision(2) << TaxOwed << " To Uncle Sam!" << endl;
    return 0;
};
