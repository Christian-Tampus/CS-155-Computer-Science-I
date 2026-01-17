/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 20 Figure Skating
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/5/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
// Declare Constants & Function Prototypes
const string SYSTEM_ERROR_INVALID_INPUT_MESSAGE = "[SYSTEM ERROR] Invalid Input!";
void GetSecondLowestAndHighestJudgeScores(double JudgeScore1, double JudgeScore2, double JudgeScore3, double JudgeScore4, double &SecondLowestScore, double &SecondHighestScore);
int main(){
    //Declare Local Variables
    double SecondLowestScore, SecondHighestScore, JudgeScore1, JudgeScore2, JudgeScore3, JudgeScore4;
    cout << "Figure Skating Judge Score Calculator (R)" << endl << endl;
    //Typical Input Validators
    do{
        cout << "Please Enter Judge 1 Score (Must Be >= 0)..." << endl;
        cin >> JudgeScore1;
        if (JudgeScore1 < 0){
            cout << SYSTEM_ERROR_INVALID_INPUT_MESSAGE << endl;
        };
    }while(JudgeScore1 < 0);
    do{
        cout << "Please Enter Judge 2 Score (Must Be >= 0)..." << endl;
        cin >> JudgeScore2;
        if (JudgeScore2 < 0){
            cout << SYSTEM_ERROR_INVALID_INPUT_MESSAGE << endl;
        };
    }while(JudgeScore2 < 0);
    do{
        cout << "Please Enter Judge 3 Score (Must Be >= 0)..." << endl;
        cin >> JudgeScore3;
        if (JudgeScore3 < 0){
            cout << SYSTEM_ERROR_INVALID_INPUT_MESSAGE << endl;
        };
    }while(JudgeScore3 < 0);
    do{
        cout << "Please Enter Judge 4 Score (Must Be >= 0)..." << endl;
        cin >> JudgeScore4;
        if (JudgeScore4 < 0){
            cout << SYSTEM_ERROR_INVALID_INPUT_MESSAGE << endl;
        };
    }while(JudgeScore4 < 0);
    //Call The Function GetSecondLowestAndHighestJudgeScores
    GetSecondLowestAndHighestJudgeScores(JudgeScore1,JudgeScore2,JudgeScore3,JudgeScore4,SecondLowestScore,SecondHighestScore);
    //Display Output
    cout << endl << "Second Highest Score Is: " << fixed << setprecision(2) << SecondHighestScore << " & Second Lowest Score Is: " << SecondLowestScore << endl << endl;
    cout << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: GetSecondLowestAndHighestJudgeScores
Purpose: Get Second Lowest And Highest Judge Scores
Incoming: Judge Score 1 (Double), Judge Score 2 (Double), Judge Score 3 (Double), Judge Score 4 (Double), Second Lowest Score (Double), Second Highest Score (Double)
Outgoing: Lowest Score (Double), Highest Score (Double)
Return: Void
*/
void GetSecondLowestAndHighestJudgeScores(double JudgeScore1, double JudgeScore2, double JudgeScore3, double JudgeScore4, double &SecondLowestScore, double &SecondHighestScore){
    if (JudgeScore1 <= JudgeScore2 && JudgeScore2 <= JudgeScore3 && JudgeScore3 <= JudgeScore4){
        //This Checks If Multiple Inputs Have The Same Exact Values, Example: Inputs -> {10,10,10,9} -> 2nd Smallest Is 10, 2nd Largest Is 9.
        SecondLowestScore = JudgeScore1;
        for (int Index = 1; Index <=3; Index++){
            if (Index == 1 && JudgeScore2 > JudgeScore1){
                SecondLowestScore = JudgeScore2;
                break;
            }else if (Index == 2 && JudgeScore3 > JudgeScore1){
                SecondLowestScore = JudgeScore3;
                break;
            }else if (Index == 3 && JudgeScore4 > JudgeScore1){
                SecondLowestScore = JudgeScore4;
                break;
            };
        };
        SecondHighestScore = JudgeScore4;
        for (int Index = 3; Index >= 1; Index--){
            if (Index == 3 && JudgeScore3 < JudgeScore4){
                SecondHighestScore = JudgeScore3;
                break;
            }else if (Index == 2 && JudgeScore2 < JudgeScore4){
                SecondHighestScore = JudgeScore2;
                break;
            }else if (Index == 1 && JudgeScore1 < JudgeScore4){
                SecondHighestScore = JudgeScore1;
                break;
            };
        };
    }else{
        //Recursive Function Since Arrays Are Not Allowed!!! :(
        for (int Index = 1; Index <= 3; Index++){
            if (Index == 1 && JudgeScore1 > JudgeScore2){
                double NewJudgeScore1 = JudgeScore2;
                double NewJudgeScore2 = JudgeScore1;
                GetSecondLowestAndHighestJudgeScores(NewJudgeScore1,NewJudgeScore2,JudgeScore3,JudgeScore4,SecondLowestScore,SecondHighestScore);
            }else if (Index == 2 && JudgeScore2 > JudgeScore3){
                double NewJudgeScore2 = JudgeScore3;
                double NewJudgeScore3 = JudgeScore2;
                GetSecondLowestAndHighestJudgeScores(JudgeScore1,NewJudgeScore2,NewJudgeScore3,JudgeScore4,SecondLowestScore,SecondHighestScore);
            }else if (Index == 3 && JudgeScore3 > JudgeScore4){
                double NewJudgeScore3 = JudgeScore4;
                double NewJudgeScore4 = JudgeScore3;
                GetSecondLowestAndHighestJudgeScores(JudgeScore1,JudgeScore2,NewJudgeScore3,NewJudgeScore4,SecondLowestScore,SecondHighestScore);
            };
        };
    };
};
// ARRAYS ALWAYS START AT 1! (For Lua That Is) :)
