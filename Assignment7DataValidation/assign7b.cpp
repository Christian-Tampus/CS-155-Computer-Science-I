/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 7 B Data Validation
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/6/2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
const int INVALID_INPUT_VALUE = 0;
const string INVALID_INPUT_TEXT = "Data is not valid";
int main(){
    int Hits, AtBats, Walks, HitByPitch, SacrificeFlies;
    double BattingAvg, OnBasePercentage;
    cout << "Enter Softball Player Hits During A Season..." << endl;
    cin >> Hits;
    if (Hits < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Enter Softball Player At Bats During A Season..." << endl;
    cin >> AtBats;
    if (AtBats < INVALID_INPUT_VALUE || Hits > AtBats){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Enter Softball Player Walks During A Season..." << endl;
    cin >> Walks;
    if (Walks < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Enter Softball Player Hit By Pitch During A Season..." << endl;
    cin >> HitByPitch;
    if (HitByPitch < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    cout << "Enter Softball Player Sacrifice Flies During A Season..." << endl;
    cin >> SacrificeFlies;
    if (SacrificeFlies < INVALID_INPUT_VALUE){
        cout << INVALID_INPUT_TEXT << endl;
        return 0;
    };
    BattingAvg = (double) Hits/AtBats;
    OnBasePercentage = (double) (Hits + Walks + HitByPitch) / (AtBats + Walks + HitByPitch + SacrificeFlies);
    cout << "The Softball Player's Batting Average Is: " << fixed << setprecision(3) << BattingAvg << endl;
    cout << "The Softball Player's On Base Percentage Is: " << fixed << setprecision(3) << OnBasePercentage << endl;
    return 0;
};
