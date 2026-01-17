/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 9 College Credits
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/13/2024
*/
#include <iostream>
using namespace std;
int main(){
    int CollegeCredits;
    cout << "Please Enter How Many College Credits You Have Earned (0-125+)." << endl;
    cin >> CollegeCredits;
    if (CollegeCredits <= 30){
        cout << "You Belong In The Freshman Class!" << endl;
    }else if (CollegeCredits <= 60){
        cout << "You Belong In The Sophomore Class!" << endl;
    }else if (CollegeCredits <= 90){
        cout << "You Belong In The Junior Class!" << endl;
    }else if (CollegeCredits <= 124){
        cout << "You Belong In The Senior Class!" << endl;
    }else{
        cout << "You Belong In The Graduate Student Class!" << endl;
    };
    return 0;
};
