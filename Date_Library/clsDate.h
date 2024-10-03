#pragma once
#include <iostream>
#include <ctime>
#include<vector>
#include <string>
#include "clsString.h"

using namespace std;


class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1990;

public:
    //Constractors
	clsDate() 
    {
        time_t MyTime = time(0);
        tm now; // Declare a tm structure to hold the local time
        localtime_s(&now, &MyTime); // Use localtime_s correctly

        _Year = now.tm_year + 1900;
        _Month = now.tm_mon + 1;
        _Day = now.tm_mday;
	}

    clsDate(string date)
    {
        vector <string> vStringDate;
        vStringDate = clsString::Split(date, "/");

        _Day = stoi(vStringDate[0]);
        _Month = stoi(vStringDate[1]);
        _Year = stoi(vStringDate[2]);
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(int NumbersDays, short Year) 
    {
        //This will construct a date by date order in year
        clsDate Date = GetDateFromDayOrderInYear(NumbersDays, Year);
        _Day = Date._Day;
        _Month = Date._Month;
        _Year = Date._Year;

    }

    //Properties Set and Get For _Day 
    void SetDay(short Day)
    {
        _Day = Day;
    }

    short GetDay()
    {
        return _Day;
    }

    __declspec(property(get = GetDay, put = SetDay)) short Day;

    //Properties Set and Get For _Month
    void SetMonth(short Month)
    {
        _Month = Month;
    }

    short GetMonth()
    {
        return _Month;
    }

    __declspec(property(get = GetMonth, put = SetMonth)) short Month;

    //Properties Set and Get For _Year
    void SetYear(short Year) 
    {
        _Year = Year;
    }

    short GetYear() 
    {
        return _Year;
    }

    __declspec(property(get = GetYear, put = SetYear)) short Year;

    //#####################################################################
    static clsDate GetDateFromDayOrderInYear(int NumbersDays, short Year)
    {

        clsDate Date;
        int RemainingDays = NumbersDays;
        short  MonthDays = 0;

        Date.Month = 1;
        Date.Year = Year;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;

                if (Date.Month > 12)
                {
                    Date.Year++;
                    Date.Month = 1;
                }
            }
            else {
                Date.Day = RemainingDays;
                break;
            }
        }
        return Date;
    }

    //#####################################################################
    void Print() 
    {
        cout << DateToString();
    }

    static string DateToString(clsDate Date) 
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string DateToString() 
    {
        return DateToString(*this);
    }

    //#####################################################################
    static clsDate GetSystemDate()
    {
        clsDate Date;
        time_t MyTime = time(0);
        tm now; // Declare a tm structure to hold the local time
        localtime_s(&now, &MyTime); // Use localtime_s correctly

        Date._Year = now.tm_year + 1900;
        Date._Month = now.tm_mon + 1;
        Date._Day = now.tm_mday;

        return Date;
    }

    //#####################################################################
    static bool IsValidateDay(clsDate Date)
    {

        if (Date.Month < 1 || Date.Month >12)
            return false;

        if (Date.Year < 1)
            return false;

        if (1 > Date.Day || NumberOfDaysInAMonth(Date.Year, Date.Month) < Date.Day)
            return false;

        return true;
    }

    bool IsValidateDay() 
    {
        return IsValidateDay(*this);
    }

    //#####################################################################
    static bool IsLeapYear(short Year)
    {
        return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
    }

    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }
    
    //#####################################################################
    static short NumberOfDaysInAYear(short Year)
    {
        return  IsLeapYear(Year) ? 365 : 364;
    }

    short NumberOfDaysInAYear()
    {
        return  NumberOfDaysInAYear(_Year);
    }

	static short NumberOfHoursInAYear(short Year)
    {
        return  NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear()
    {
        return  NumberOfHoursInAYear(_Year);
    }

    static int NumberOfMinutesInAYear(short Year)
    {
        return  NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear()
    {
        return  NumberOfMinutesInAYear(_Year);
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return  NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear()
    {
        return  NumberOfSecondsInAYear();
    }

    //#####################################################################
    static short NumberOfDaysInAMonth(short year, short month)
    {
        if (0 == month)
            return 0;
        short NumberDaysinMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (2 == month ? (IsLeapYear(year) ? 29 : 28) : NumberDaysinMonth[month - 1]);
    }

    short NumberOfDaysInAMonth()
    {
        return NumberOfDaysInAMonth(_Year, _Month);
    }

    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return  NumberOfDaysInAMonth(Month, Year) * 24;
    }

    short NumberOfHoursInAMonth()
    {
        return  NumberOfDaysInAMonth(_Month, _Year) * 24;
    }

    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return  NumberOfHoursInAMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInAMonth()
    {
        return  NumberOfHoursInAMonth(_Month, _Year) * 60;
    }

    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return  NumberOfMinutesInAMonth(Month, Year) * 60;
    }

    int NumberOfSecondsInAMonth() 
    {
        return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
    }

    //#####################################################################
    static short DayOfWeekOrder(short year, short month, short day)
    {
        short a, y, m;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder() 
    {
        return DayOfWeekOrder(_Year, _Month, _Day);
    }

    static string DayShortName(short DayOfWeekOrder) 
    {
        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder];

    }

    static string DayShortName(short Day, short Month, short Year)
    {

        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder(Day, Month, Year)];

    }

    string DayShortName() 
    {

        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];

    }

    static string MonthShortName(short month)
    {
        string months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        return (months[month - 1]);
    }

    string MonthShortName()
    {
        return MonthShortName(_Month);
    }

    //#####################################################################
    static void PrintMonthCalendar(int year, int month)
    {
        int NumberOfDays;

        //index of the day from 0 to 6
        short current = DayOfWeekOrder(year, month, 1);

        //number Day In Month 28 or 29 or 30 or 31
        NumberOfDays = NumberOfDaysInAMonth(year, month);

        printf("\n------------------- %s -------------------\n\n", MonthShortName(month).c_str());

        cout << "   Sun   Mon   Tue   Wed   Thu   Fri   Sat  \n\n";

        int i;
        for (i = 0; i < current; i++)
            cout << "      ";


        for (short j = 1; j <= NumberOfDays; j++)
        {

            printf("%6d", j);

            if (++i == 7) {
                i = 0;
                cout << endl << endl;
            }

        }
        cout << "\n\n--------------------------------------------\n\n";
    }

    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Year, _Month);
    }

    static void PrintYearCalendar(short year)
    {
        cout << "\n\n-------------------------------------\n\n";
        cout << "\tCalendar - " << year;
        cout << "\n\n-------------------------------------\n\n";

        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(year, i);
        }

    }

    void PrintYearCalendar() 
    {
        PrintYearCalendar(_Year);
    }

    //#####################################################################
    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {

        short TotalDays = 0;

        for (int i = 1; i <= Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, Year);
        }

        TotalDays += Day;

        return TotalDays;
    }

    short DaysFromTheBeginingOfTheYear()
    {

        short TotalDays = 0;

        for (int i = 1; i <= _Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, _Year);
        }

        TotalDays += _Day;

        return TotalDays;
    }

    void AddDays(short Days)
    {
        short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
        short MonthDays = 0;

        _Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(_Month, _Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;

                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;

                }
            }
            else
            {
                _Day = RemainingDays;
                break;
            }

        }


    }

    //#####################################################################
    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }

    bool IsDateBeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
    }

    bool IsDateEqualDate2(clsDate Date2)
    {
        return  IsDate1EqualDate2(*this, Date2);
    }

    //#####################################################################
    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date._Day == NumberOfDaysInAMonth(Date._Year, Date._Month));
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsLastMonthInYear() 
    {
        return IsLastMonthInYear(_Month);
    }

    //#####################################################################
    static clsDate AddOneDay(clsDate Date)
    {

        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month)) {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else {
            Date.Day++;
        }
        return  Date;
    }

    void AddOneDay() 
    {
        *this = AddOneDay(*this);
    }

    //#####################################################################
    static void  SwapDates(clsDate& Date1, clsDate& Date2) 
    {
        clsDate TempDate;
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        //this will take care of negative diff
        int Days = 0;
        short SawpFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            //Swap Dates 
            SwapDates(Date1, Date2);
            SawpFlagValue = -1;

        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
    }

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }
    //#####################################################################
    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    }
    //#####################################################################






};

