/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 28 Parallel Arrays
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/17/2024
*/
#include <iostream>
#include <string>
#include <numeric>
#include <cmath>
#include <unordered_map>
using namespace std;
const int MIN_SCORES = 3, MAX_SCORES = 1000, MIN_STUDENT_ID = 1000, MAX_STUDENT_ID = 9999, MIN_EXAM_SCORE = 0, MAX_EXAM_SCORE = 100;
void GetUserInput(string COUT, int &UserInput, int InputValidation1, int InputValidation2, bool HasEndLine, unordered_map<int, int> &InputUnorderedMap, bool RequiresUnorderedMap = false);
void ReadScores(int InputArray1[], int InputArray2[], int &InputArraySize);
void ShowTopScores(const int InputArray1[], const int InputArray2[], int InputArraySize);
int main(){
    cout << "Student Exam Top Scores Calculator (TM)" << endl << endl;
    int StudentIdArray[MAX_SCORES], ExamScoresArray[MAX_SCORES], UserInputArraySize;
    ReadScores(StudentIdArray,ExamScoresArray,UserInputArraySize);
    ShowTopScores(StudentIdArray,ExamScoresArray,UserInputArraySize);
    cout << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: GetUserInput
Purpose: Get User Input
Incoming: COUT (String), User Input (Integer), Input Validation 1 (Integer), Input Validation 2 (Integer), Has End Line (Boolean), Input Unordered Map (Unordered Map), Requires Unordered Map (Boolean)
Outgoing: User Input (Integer), Input Unordered Map (Unordered Map)
Return: Void
*/
void GetUserInput(string COUT, int &UserInput, int InputValidation1, int InputValidation2, bool HasEndLine, unordered_map<int, int> &InputUnorderedMap, bool RequiresUnorderedMap){
    bool ValidStudentId = false;
    do{
        ValidStudentId = false;
        cout << COUT;
        if (HasEndLine){
            cout << endl;
        };
        cin >> UserInput;
        if (UserInput < InputValidation1 || UserInput > InputValidation2){
            cout << "[SYSTEM ERROR] Invalid Input!" << endl;
        }else if (RequiresUnorderedMap == true){
            if (!InputUnorderedMap[UserInput]){
                InputUnorderedMap[UserInput] = UserInput;
                ValidStudentId = true;
            }else{
                cout << "[SYSTEM ERROR] Student Id: " << UserInput << " Already Exists!" << endl;
            };
        };
    }while(UserInput < InputValidation1 && !RequiresUnorderedMap || UserInput > InputValidation2 && !RequiresUnorderedMap || RequiresUnorderedMap && !ValidStudentId);
};
/*
Name: ReadScores
Purpose: Read Scores
Incoming: Input Array 1 (Array) Input Array 2 (Array), Input Array Size (Integer)
Outgoing: Input Array 1 (Array) Input Array 2 (Array)
Return: Void
*/
void ReadScores(int InputArray1[], int InputArray2[], int &InputArraySize){
    unordered_map<int, int> InvalidStudentIdsMap;
    GetUserInput("Please Enter How Many Student Information To Enter (Must Be In Range: " + to_string(MIN_SCORES) + "-" + to_string(MAX_SCORES) + "):",InputArraySize,MIN_SCORES,MAX_SCORES,false,InvalidStudentIdsMap);
    for (int Index = 0; Index < InputArraySize; Index++){
        int UserInputStudentId, UserInputExamScore;
        GetUserInput("Please Enter Student #" + to_string(Index+1) + " (Must Be In Range: " + to_string(MIN_STUDENT_ID) + "-" + to_string(MAX_STUDENT_ID) + ") Student ID:",UserInputStudentId,MIN_STUDENT_ID,MAX_STUDENT_ID,false,InvalidStudentIdsMap,true);
        GetUserInput("Please Enter Student #" + to_string(Index+1) + " (Must Be In Range: " + to_string(MIN_EXAM_SCORE) + "-" + to_string(MAX_EXAM_SCORE) + ") Exam Score:",UserInputExamScore,MIN_EXAM_SCORE,MAX_EXAM_SCORE,false,InvalidStudentIdsMap);
        InputArray1[Index] = UserInputStudentId;
        InputArray2[Index] = UserInputExamScore;
    };
};
/*
Name: ShowTopScores
Purpose: Show Top Scores
Incoming: Input Array 1 (Array) Input Array 2 (Array), Input Array Size (Integer)
Outgoing: None
Return: Void
*/
void ShowTopScores(const int InputArray1[], const int InputArray2[], int InputArraySize){
    double Mean = (double) accumulate(InputArray2,InputArray2+InputArraySize,0)/InputArraySize;
    cout << "Mean: " << Mean << endl;
    int InputArray1LocalCopy[InputArraySize], InputArray2LocalCopy[InputArraySize], NumOverMean = 0;
    for (int Index = 0; Index < InputArraySize; Index++){
        InputArray1LocalCopy[Index] = InputArray1[Index];
        InputArray2LocalCopy[Index] = InputArray2[Index];
    };
    for (int Index1 = 0; Index1 < InputArraySize; Index1++){
        for (int Index2 = InputArraySize-1; Index2 > Index1; Index2--){
            if (InputArray2LocalCopy[Index2] < InputArray2LocalCopy[Index2-1]){
                int Temp1 = InputArray1LocalCopy[Index2];
                int Temp2 = InputArray2LocalCopy[Index2];
                InputArray1LocalCopy[Index2] = InputArray1LocalCopy[Index2-1];
                InputArray2LocalCopy[Index2] = InputArray2LocalCopy[Index2-1];
                InputArray1LocalCopy[Index2-1] = Temp1;
                InputArray2LocalCopy[Index2-1] = Temp2;
            };
        };
    };
    for (int Index = 0; Index < InputArraySize; Index++){
        if (InputArray2LocalCopy[Index] > Mean){
            cout << "Student ID: " << InputArray1LocalCopy[Index] <<  " With Exam Score: " << InputArray2LocalCopy[Index] << endl;
            NumOverMean++;
        };
    };
    cout << "Number Of Scores Over The Mean: " << NumOverMean << endl;
};
