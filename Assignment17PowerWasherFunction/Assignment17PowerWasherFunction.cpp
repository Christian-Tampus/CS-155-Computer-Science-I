/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 17 Power Washer Function
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/27/2024
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//Declare Global Constant Variables & Function Prototype
const double RATE_45 = 0.45, RATE_31 = 0.31, TWO_HOURS = 120, BASE_FEE = 10;
double PowerWasherRentCost(double Minutes);
int main(){
    //Declare Local Variables
    string UserReply;
    double InputMinutes; //Double In Case User Inputs Non Whole Number
    cout << "Steve's Tool Shoppe (R) Power Washer Rent Calculator (TM)" << endl << endl;
    //Core Loop
    do{
        cout << "Please Enter The Rent Time In Minutes (Example: 120)" << endl;
        cin >> InputMinutes;
        if (InputMinutes >= 0){
            cout << "Total Rent Cost: $" << fixed << setprecision(2) << PowerWasherRentCost(InputMinutes) << endl; //Calculates Only When InputMinutes Is >= 0
        }else{
            cout << "[SYSTEM ERROR] Rent Time Entered Is Less Than 0!" << endl; //Outputs System Error Message If InputMinutes < 0
        };
        do{
            cout << "Type 'yes' If You Would Like To Process Another Customer, Otherwise Type 'no' (Without Quotes)..." << endl;
            cin >> UserReply;
            if (UserReply != "yes" && UserReply != "no"){
                cout << "[SYSTEM ERROR] Invalid Input, Please Try Again!" << endl; //Outputs Invalid Input Message If User Enters Enters An Invalid Input
            };
        }while(UserReply != "yes" && UserReply != "no"); //Continue Looping Until User Inputs Valid Inputs Of "yes" Or "no"
    }while(UserReply != "no"); //Continue Looping Until User Inputs "no" To Terminate The Program
    cout << endl << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: PowerWasherRentCost;
Purpose: Calculate Power Washer Rent Cost
Incoming: Power Washer Rent Time In Minutes (Double)
Outgoing: Power Washer Rent Cost (Double)
Return: Power Washer Rent Cost (Double)
*/
double PowerWasherRentCost(double Minutes){
    double RentCost = BASE_FEE;
    if (Minutes <= TWO_HOURS){
        RentCost += (Minutes * RATE_45);
    }else{
        RentCost += (TWO_HOURS * RATE_45) + ((Minutes - TWO_HOURS) * RATE_31);
    }
    return RentCost;
};
