#pragma once
#include <iostream>
#include <ctime>
#include<vector>
#include <string>

using namespace std;


class clsDate
{
private:
    int _Day = 0;
    int _Month = 0;
    int _Year = 0;

    vector <string> SplitString(string S1, string Delim = "#//#") {

        size_t pos = 0;
        string sWord;
        vector <string> MyDate;

        while ((pos = S1.find(Delim)) != std::string::npos) {

            sWord = S1.substr(0, pos);

            if (sWord != "")
                MyDate.push_back(sWord);

            S1 = S1.erase(0, pos + Delim.length());
        }
        if (S1 != "")
            MyDate.push_back(S1);

        return MyDate;
    }
    void StringToDate(string Line) {

      
        vector <string> vStringDate;

        vStringDate = SplitString(Line, "/");

        _Day = stoi(vStringDate[0]);
        _Month = stoi(vStringDate[1]);
        _Year = stoi(vStringDate[2]);
    };

public: 
    //First constractor if you create object Without sending any value
	clsDate() {
        GetSystemDate();
	}
    //second constractor if you create object by sending a value in the form "dd/mm/yy"
    clsDate(string date) {
        StringToDate(date);
    }

    void GetSystemDate() {
        time_t MyTime = time(0);
        tm now; // Declare a tm structure to hold the local time
        localtime_s(&now, &MyTime); // Use localtime_s correctly

        _Year = now.tm_year + 1900;
        _Month = now.tm_mon + 1;
        _Day = now.tm_mday;
    } 
    void Print() {
        cout << _Day << "/" << _Month << "/" << _Year << endl;
    }
    
};

