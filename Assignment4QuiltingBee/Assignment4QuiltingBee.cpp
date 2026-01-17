/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 4 Quilting Bee
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/4/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    const double SalesTax = 0.095, StripedFabricYards = 1.25, PaisleyFabricYards = 1.5, BackingYards = 3.5;
    double StripedFabricCost, PaisleyFabricCost, BackingCost;
    double SubTotal, Tax, Total;
    cout << "Enter Striped Fabric Cost Per Yards..." << endl;
    cin >> StripedFabricCost;
    cout << "Enter Paisley Fabric Cost Per Yards..." << endl;
    cin >> PaisleyFabricCost;
    cout << "Enter Backing Cost Per Yards..." << endl;
    cin >> BackingCost;
    SubTotal = (StripedFabricCost * StripedFabricYards) + (PaisleyFabricCost * PaisleyFabricYards) + (BackingCost * BackingYards);
    Tax = SubTotal * SalesTax;
    Total = SubTotal + Tax;
    cout << "Sub Total For Quilt Is: $" << fixed << setprecision(2) << SubTotal << endl;
    cout << "Sales Tax For Quilt Is: $" << fixed << setprecision(2) << Tax << " @ 9.5% Tax Rate" <<endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "After Tax For Quilt Is: $" << fixed << setprecision(2) << Total << endl;
    return 0;
};
