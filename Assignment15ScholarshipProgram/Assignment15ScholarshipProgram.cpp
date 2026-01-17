/*
This Program Was Programmed & Tested In Code::Blocks 20.03.
Description: Assignment 15 Scholarship Program
Name: Christian Tampus
Course: CS 155 Computer Science I
Date: 6/22/2024
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int Applicants;
    cout << "Lake Side University (TM) Scholarship Program Calculator (R)" << endl << endl;
    do{
        cout << "Please Enter Number Of Applicants (Range: 1-6 Only!)..." << endl;
        cin >> Applicants;
    }while(Applicants < 1 || Applicants > 6);
    for (int Index = 0; Index < Applicants; Index++){
        string ApplicantName;
        double GPA, ACT, Score;
        cout << "Please Enter Applicant Name..." << endl;
        cin >> ws;
        getline(cin,ApplicantName);
        do{
            cout << "Please Enter Applicant GPA (Range: 0.0-4.0 Only!)..." << endl;
            cin >> GPA;
        }while(GPA < 0 || GPA > 4);
        do{
            cout << "Please Enter Applicant ACT (Range: 1-36 Only!)..." << endl;
            cin >> ACT;
        }while(ACT < 1 || ACT > 36);
        Score = 16 + (15 * GPA) + (1.8 * ACT);
        cout << "Applicant Score: " << fixed << setprecision(2) << Score << endl;
        cout << "Applicant Name: " << ApplicantName << endl;
        cout << "Applicant Scholarship Earned: " << (Score >= 95 ? "Leo Scholarship" : (Score >= 85 ? "Una Scholarship" : "No Scholarship")) << endl;
    };
    return 0;
};
