/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 6 Paint The Fence
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/5/2024
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//Declare Constants
const int FENCE_HEIGHT = 6, PAINT_COVERAGE = 350;
const double SALES_TAX = 0.095;
int main(){
    //Declare Variables
    string PaintColor;
    int TotalPaintCansRequired;
    double FenceLength, CostPerGallon, FenceSurfaceArea, SubTotal, Tax, Total;
    //Obtain User Inputs
    cout << "Welcome To House Depot! How Can We Helping It?" << endl << endl;
    cout << "Hey Sir, I Have A Fence That Is 6 Feet Tall How Much Gallon Paint Cans Do I Need?" << endl << endl;
    cout << "Okie Uhh... Please Tell Me The Color Of The Paint You Are Currently Holding? (Example: Blue)" << endl;
    cin >> PaintColor;
    cout << "Okie Uhh... Now How Longing Is The Fence Ma'am? (Example: 789.654)" << endl;
    cin >> FenceLength;
    cout << "Sorry, The Machine Is Down, Uhh... Could You Tell Me The Price On The Can's Sticker Ma'am? (Example: 19.95)" << endl;
    cin >> CostPerGallon;
    //Calculate Square Feet, Total Paint Cans Required, Sub Total, Tax & Total
    FenceSurfaceArea = FenceLength * FENCE_HEIGHT;
    TotalPaintCansRequired = ceil(FenceSurfaceArea/PAINT_COVERAGE);
    SubTotal = CostPerGallon * TotalPaintCansRequired;
    Tax = SubTotal * SALES_TAX;
    Total = SubTotal + Tax;
    //Display (Output) Square Feet To Cover, Number Of Cans To Purchase, Sub Total, Tax & Total Amount Owed
    cout << "__________________________________________________________________________________________________________________" << endl;
    cout << "Ah! Finally, The Machine Is A Workingmating. Uhh... The Surface Area You Need To Paint Is: " << fixed << setprecision(1) << FenceSurfaceArea << " sq. ft." << endl;
    cout << "So I Uhh... Recommendating You Buy At Least Uhh... " << TotalPaintCansRequired << " Cans Of The " << PaintColor << " Paint" << endl;
    cout << "So Ma'am, Your Sub Total Is: $" << fixed << setprecision(2) << SubTotal << endl;
    cout << "The Tax Is: $" << fixed << setprecision(2) << Tax << endl;
    cout << "And You Owe This Many Dollars, Right Here On The Billing: $" << fixed << setprecision(2) << Total << endl;
    cout << "Okie Thank You Come Again Ma'am! Please Give Me A 5 Star Servicing Rate Using The Linking On Your Receipt, Thank You!" << endl;
    return 0;
};
