/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 30 Sorting Algorithms
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 7/22/2024
*/
#include <iostream>
#include <unordered_map>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;
const int STATES = 71;
const string STATE_NAMES_ARRAY[STATES] = {"W","w","w","W","a","A","AA","aa","AaA","aAAa","aAaA","Alabama","Alaska","Arizona","Arkansas","California","Colorado","Connecticut","Delaware","Florida","Georgia","Hawaii","Idaho","Illinois","Indiana","Iowa","Kansas","Kentucky","Louisiana","Maine","Maryland","Massachusetts","Michigan","Minnesota","Mississippi","Missouri","Montana","Nebraska","Nevada","New Hampshire","New Jersey","New Mexico","New York", "North Carolina","North Dakota","Ohio","Oklahoma","Oregon","Pennsylvania","Rhode Island","South Carolina","South Dakota","Tennessee","Texas","Utah","Vermont","Virginia","Washington","Washington D.C","West Virginia","Wisconsin","Wyoming","z","Z","zz","ZZ","ZzZ","zZz","ZZZZZ","zzzzz","zZzZz"};
void Randomize(string InputArray[], int InputArraySize);
void CompareStrings(string String1, string String2, int StringLength, int &CompareIndex, int Index2, bool &IsCompared, string OriginalString1, string OriginalString2, string Round = "First");
void ReversedSelectionSort(string InputArray[], int InputArraySize);
void Display(const string InputArray[], int InputArraySize);
int main(){
    cout << "Alphabetic Order (For States Only, The Other Values Are Not Exactly In Order And Are Edge Cases):" << endl << endl;
    string StateNamesArrayCopy[STATES];
    for (int Index = 0; Index < STATES; Index++){
        StateNamesArrayCopy[Index] = STATE_NAMES_ARRAY[Index];
    };
    Display(StateNamesArrayCopy,STATES);
    cout << "Randomized Order:" << endl << endl;
    Randomize(StateNamesArrayCopy,STATES);
    Display(StateNamesArrayCopy,STATES);
    cout << "Reversed Order:" << endl << endl;
    ReversedSelectionSort(StateNamesArrayCopy,STATES);
    Display(StateNamesArrayCopy,STATES);
    cout << "Reversed Selection Sort Algorithm Uses CompareStrings Which Is A Recursive Function Algorithm That Compare Strings In 3 Rounds If Not Yet Sorted, Will Move To The Next Round. Round 1: Compare Both As Uppercase, Round 2: Compare Both As Original Case, Round 3: Compare Both With Total String ASCII Values, Default: String Length Comparison, Note: There Can Be Some Inconsistencies Within The Same Starting Characters Due To The Placement Of Values When Randomized But Will Generally Fall Within Their Respective Sort Locations Alphabetically. :)" << endl;
    cout << endl << "[SYSTEM MESSAGE] Program Terminated..." << endl;
    return 0;
};
/*
Name: Randomize
Purpose: Randomize Array
Incoming: Input Array (String Array), Input Array Size (Integer)
Outgoing: Input Array (String Array)
Return: Void
*/
void Randomize(string InputArray[], int InputArraySize){
    srand(time(0));
    unordered_map<int, int> UnusedIndexMap;
    for (int Index = 0; Index < InputArraySize; Index++){
        UnusedIndexMap[Index] = Index;
    };
    for (int Index = 0; Index < InputArraySize; Index++){
        int RandomIndex;
        do{
            RandomIndex = UnusedIndexMap[rand() % UnusedIndexMap.size()];
        }while(RandomIndex == Index);
        string Temp = InputArray[Index];
        InputArray[Index] = InputArray[RandomIndex];
        InputArray[RandomIndex] = Temp;
        UnusedIndexMap.erase(RandomIndex);
    };
};
/*
Name: CompareStrings
Purpose: A Recursive Function Algorithm That Compare Strings In 3 Rounds If Not Yet Sorted, Will Move To The Next Round. Round 1: Compare Both As Uppercase, Round 2: Compare Both As Original Case, Round 3: Compare Both With Total String ASCII Values, Default: String Length Comparison
Incoming: String 1 (String), String 2 (String), String Length (Integer), Compare Index (Integer), Index 2 (Integer), Is Compared (Boolean), Original String 1 (String), Original String 2 (String), Round (String)
Outgoing: Compare Index (Integer), Is Compared (Boolean)
Return: Void
*/
void CompareStrings(string String1, string String2, int StringLength, int &CompareIndex, int Index2, bool &IsCompared, string OriginalString1, string OriginalString2, string Round){
    int ASCIIString1Value = 0;
    int ASCIIString2Value = 0;
    if (Round != "Third"){
        for (int Index = 0; Index < StringLength; Index++){
            char String1Char = String1[Index];
            char String2Char = String2[Index];
            if (int(String2Char) > int(String1Char)){
                CompareIndex = Index2;
                IsCompared = true;
                break;
            }else if (int(String1Char) > int(String2Char)){
                IsCompared = true;
                break;
            };
        };
    }else{
        for (int Index = 0; Index < String1.length(); Index++){
            char String1Char = String1[Index];
            ASCIIString1Value += int(String1Char);
        };
        for (int Index = 0; Index < String2.length(); Index++){
            char String2Char = String2[Index];
            ASCIIString2Value += int(String2Char);
        };
    }
    if (Round == "Third" && ASCIIString1Value != ASCIIString2Value){
        CompareIndex = (ASCIIString2Value > ASCIIString1Value ? Index2 : CompareIndex);
        IsCompared = true;
    };
    if (!IsCompared && Round == "First"){
        String1 = OriginalString1;
        String2 = OriginalString2;
        CompareStrings(String1,String2,StringLength,CompareIndex,Index2,IsCompared,OriginalString1,OriginalString2,"Second");
    }else if (!IsCompared && Round == "Second"){
        CompareStrings(String1,String2,StringLength,CompareIndex,Index2,IsCompared,OriginalString1,OriginalString2,"Third");
    }else if (!IsCompared && Round == "Third"){
        CompareIndex = (String2.length() > String1.length() ? Index2 : CompareIndex);
    };
};
/*
Name: ReversedSelectionSort
Purpose: Sorts Array Of Strings In Reverse Order
Incoming: Input Array (String Array), Input Array Size (Integer)
Outgoing: Input Array (String Array)
Return: Void
*/
void ReversedSelectionSort(string InputArray[], int InputArraySize){
    for (int Index1 = 0; Index1 < InputArraySize-1; Index1++){
        int CompareIndex = Index1;
        for (int Index2 = Index1+1; Index2 < InputArraySize; Index2++){
            string CompareState = InputArray[CompareIndex];
            string CurrentState = InputArray[Index2];
            transform(CompareState.begin(),CompareState.end(),CompareState.begin(),::toupper);
            transform(CurrentState.begin(),CurrentState.end(),CurrentState.begin(),::toupper);
            bool IsCompared = false;
            int StringLength = (CompareState.length() < CurrentState.length() ? CompareState.length() : CurrentState.length());
            CompareStrings(CompareState,CurrentState,StringLength,CompareIndex,Index2,IsCompared,InputArray[CompareIndex],InputArray[Index2]);
        };
        string TempState = InputArray[Index1];
        InputArray[Index1] = InputArray[CompareIndex];
        InputArray[CompareIndex] = TempState;
    };
};
/*
Name: Display
Purpose: Displays String Array
Incoming: Input Array (String Array), Input Array Size (Integer)
Outgoing: Input Array (String Array)
Return: Void
*/
void Display(const string InputArray[],int InputArraySize){
    for (int Index = 0; Index < InputArraySize; Index++){
        cout << "[" + to_string(Index+1) + "] " + InputArray[Index] << endl;
    };
    cout << endl;
};
