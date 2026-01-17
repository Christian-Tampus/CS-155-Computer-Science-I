/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 3 Batter Up
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/4/2024
Batting Average Formula: https://miniwebtool.com/batting-average-calculator/
On Base Percentage Formula: https://miniwebtool.com/on-base-percentage-calculator/
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int Hits, AtBats, Walks, HitByPitch, SacrificeFlies;
    double BattingAvg, OnBasePercentage;
    cout << "Enter Softball Player Hits During A Season..." << endl;
    cin >> Hits;
    cout << "Enter Softball Player At Bats During A Season..." << endl;
    cin >> AtBats;
    cout << "Enter Softball Player Walks During A Season..." << endl;
    cin >> Walks;
    cout << "Enter Softball Player Hit By Pitch During A Season..." << endl;
    cin >> HitByPitch;
    cout << "Enter Softball Player Sacrifice Flies During A Season..." << endl;
    cin >> SacrificeFlies;
    BattingAvg = (double) Hits/AtBats;
    OnBasePercentage = (double) (Hits + Walks + HitByPitch) / (AtBats + Walks + HitByPitch + SacrificeFlies);
    cout << "The Softball Player's Batting Average Is: " << fixed << setprecision(3) << BattingAvg << endl;
    cout << "The Softball Player's On Base Percentage Is: " << fixed << setprecision(3) << OnBasePercentage << endl;
    return 0;
};
