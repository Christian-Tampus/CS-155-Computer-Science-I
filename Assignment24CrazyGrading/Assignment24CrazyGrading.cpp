/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 24 Crazy Grading
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/10/2024
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
//Declare Constants
const int MIN_STUDENT_COUNT = 3, MAX_STUDENT_COUNT = 10, MIN_STUDENT_GRADE = 0, MAX_STUDENT_GRADE = 1000, MIN_ROUNDED_GRADE = 380, CALCULATION_VALUE = 100, ROUND_UP_VALUE = 20, OUTPUT_WIDTH = 20;
const string PADDING = " ", COLUMN = "|", ROW = "--------------------------------------------------------------";
int main(){
    cout << "Crazy Mark's Grading Policy Calculator (R)" << endl << endl;
    int StudentCount;
    //Get Student Count From User Input With Do-While Input Validation
    do{
        cout << "Please Enter How Many Students Are In Mark's Computer Science Class (Must Be " << MIN_STUDENT_COUNT << "-" << MAX_STUDENT_COUNT << ")..." << endl;
        cin >> StudentCount;
        if (StudentCount < MIN_STUDENT_COUNT || StudentCount > MAX_STUDENT_COUNT){
            cout << "The University Only Allows " << MIN_STUDENT_COUNT << " To " << MAX_STUDENT_COUNT << " Students At A Time For Crazy Mark's CS Class, Don't Ask Questions, Just Please Try Again!" << endl;
        };
    }while(StudentCount < MIN_STUDENT_COUNT || StudentCount > MAX_STUDENT_COUNT);
    //Declare The Original & Rounded Arrays
    int OriginalStudentGradesArray[StudentCount] = {};
    int RoundedStudentGradesArray[StudentCount] = {};
    for (int Index = 0; Index < StudentCount; Index++){
        //Get Student Grades With Do-While Input Validation
        do{
            cout << "Please Enter Student [" << (Index + 1) << "] Grade (Must Be " << MIN_STUDENT_GRADE << "-" << MAX_STUDENT_GRADE << ")..." << endl;
            cin >> OriginalStudentGradesArray[Index];
            RoundedStudentGradesArray[Index] = OriginalStudentGradesArray[Index];
            if (OriginalStudentGradesArray[Index] < MIN_STUDENT_GRADE || OriginalStudentGradesArray[Index] > MAX_STUDENT_GRADE){
                cout << "Crazy Mark Does Not Like This Input, TRY AGAIN! >:(" << endl;
            }else if(OriginalStudentGradesArray[Index] >= MIN_ROUNDED_GRADE && CALCULATION_VALUE - (OriginalStudentGradesArray[Index] % CALCULATION_VALUE) <= ROUND_UP_VALUE){
                //Round Up Original And Store Into Rounded Student Grades Array
                RoundedStudentGradesArray[Index] += CALCULATION_VALUE - (OriginalStudentGradesArray[Index] % CALCULATION_VALUE);
            };
        }while(OriginalStudentGradesArray[Index] < MIN_STUDENT_GRADE || OriginalStudentGradesArray[Index] > MAX_STUDENT_GRADE);
    };
    //Display Headers & Columns
    cout << left << setw(OUTPUT_WIDTH) << "     Student ID     " << COLUMN << left << setw(OUTPUT_WIDTH) << "   Original Grade   " << COLUMN << left << setw(OUTPUT_WIDTH) << "   Rounded Grade    " << COLUMN << endl;
    cout << ROW << COLUMN << endl;
    for (int Index = 0; Index < StudentCount; Index++){
        //Declare Local String Variables For Rows
        string Original = to_string(OriginalStudentGradesArray[Index]);
        string Rounded = to_string(RoundedStudentGradesArray[Index]);
        string OriginalPadding;
        string RoundedPadding;
        string OriginalEndPadding;
        string RoundedEndPadding;
        //Create Padding For Original & Rounded Values
        for (int Index2 = 0; Index2 < floor(((OUTPUT_WIDTH+(Original.length() % 2 != 0 ? -1 : 0))-(Original.length()+2))/2); Index2++){
            OriginalPadding += PADDING;
        };
        for (int Index2 = 0; Index2 < floor(((OUTPUT_WIDTH+(Rounded.length() % 2 != 0 ? -1 : 0))-(Rounded.length()+2))/2); Index2++){
            RoundedPadding += PADDING;
        };
        for (int Index2 = 0; Index2 < OUTPUT_WIDTH - ((Original.length()+2)+(OriginalPadding.length()*2)); Index2++){
            OriginalEndPadding += PADDING;
        };
        for (int Index2 = 0; Index2 < OUTPUT_WIDTH - ((Rounded.length()+2)+(OriginalPadding.length()*2)); Index2++){
            RoundedEndPadding += PADDING;
        };
        //Display Each Rows
        cout << left << setw(OUTPUT_WIDTH) << "  >Student ID ["+to_string(Index)+"]   " << COLUMN << left << setw(OUTPUT_WIDTH+(Original.length() % 2 != 0 ? -1 : 0)) << OriginalPadding+"["+Original+"]"+OriginalPadding+OriginalEndPadding << COLUMN << left << setw(OUTPUT_WIDTH+(Rounded.length() % 2 != 0 ? -1 : 0)) << RoundedPadding+"["+Rounded+"]"+RoundedPadding+RoundedEndPadding << COLUMN << endl;
        cout << ROW << COLUMN << endl;
    };
    cout << endl << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
