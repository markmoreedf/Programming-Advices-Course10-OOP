#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "clsString.h";
#include <ctime> 
using namespace std;


class clsDate
{

private:
    short _day;
    short _month;
    int _year;

    static void PrintMonthHeader(const short& month, const short& year)
    {
        string monthName = clsDate::MonthOrderToName(month) + ", " + to_string(year);   // "March, 2002"

        for (int i = 0; i < round((37 - monthName.length()) / 2); i++)
            cout << "-";

        cout << " " << monthName << " ";

        for (int i = 0; i < round((38 - monthName.length()) / 2); i++)
            cout << "-";

        cout << endl;
        cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl << endl;
    }
    static void PrintMonthBody(const short& month, const short& noOfDays, const int& year)
    {
        clsDate d;
        d._year = year;
        d._month = month;


        for (int i = 1; i <= noOfDays; i++)
        {
            d._day = i;
            short dayOrder = clsDate::WeekDayOrder(d);

            //printing enough spaces before the first day if it isn't sunday so it wouldn't be printed at the begining of the row
            if (i == 1 && dayOrder != 0)
            {
                for (int i = 0; i < dayOrder; i++)
                    cout << setw(6) << " ";
            }

            cout << setw(6) << std::left << i;

            if (dayOrder == 6)
                cout << endl;

        }
        cout << endl;
    }
    static void PrintMonthFooter(const short& month)
    {
        for (int i = 0; i < 39; i++)
            cout << "-";
        cout << endl;

    }
    static void PrintYearHeader(const int& year)
    {
        cout << "_______________________________________\n";
        cout << "                 " << year << endl;
        cout << "_______________________________________\n\n";
    }
    static string WeekDayOrderToName(const short& weekday)
    {
        switch (weekday)
        {
        case 0:
            return "SunDay";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        }
    }
    static short ReadDay()
    {
        short day = 1;
        cout << "Enter day: ";
        if (cin >> day)
        {
            return day;
        }

        else { cout << "Error occured while reading day  \n"; }
    }
    static short ReadMonth()
    {
        short month = 1;

        cout << "Enter month: ";
        if (cin >> month)
        {
            return month;
        }

        else { cout << "Error occured while reading month  \n"; }
    }
    static short ReadYear()
    {
        short year = 1;

        cout << "Enter year: ";
        if (cin >> year)
            return year;

        else
            cout << "Error occured while reading year  \n";
    }


public:
    void SetDay(const short& day)
    {
        if (clsDate::IsDateValid(day, this->_month, this->_year))
            this->_day = day;
    }
    short GetDay() const { return this->_day; }

    void SetMonth(const short& month)
    {
        if (clsDate::IsDateValid(this->_day, month, this->_year))
            this->_month = month;
    }
    short GetMonth() const { return this->_month; }

    void SetYear(const int& year)
    {
        if (clsDate::IsDateValid(this->_day, this->_month, year))
            this->_year = year;
    }
    int GetYear() const { return this->_year; }

    __declspec(property(get = GetDay, put = SetDay)) short Day;
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;
    __declspec(property(get = GetYear, put = SetYear)) int Year;


    clsDate()
    {
        LoadCurrentSystemDate();
    }
    clsDate(const short& day, const short& month, const int& year)
    {
        if (clsDate::IsDateValid(day, month, year))
        {
            this->_day = day;
            this->_month = month;
            this->_year = year;
        }
        else
        {
            LoadCurrentSystemDate();
            cout << "date is not valid\n";
        }
    }
    // be carful while using this constructor as it may throw exception if the date string isn't valid
    clsDate(const string& dateString)
    {
        clsDate date = StringToDate(dateString);
        if (IsDateValid(date))
        {
            this->_day = date._day;
            this->_month = date._month;
            this->_year = date._year;
        }
        else
        {
            LoadCurrentSystemDate();
            cout << "date is not valid\n";
        }

    }
    clsDate(const int& numberOfDays, const int& year)
    {
        *this = clsDate::GetDateByDayOrderInYear(numberOfDays, year);
    }

    // functions -------------------------------------------------------------------------------
    static void ReadFullDate(clsDate& date)
    {
        do {

            date._day = clsDate::ReadDay();
            date._month = clsDate::ReadMonth();
            date._year = clsDate::ReadYear();

            if (!clsDate::IsDateValid(date))
                cout << "Date is not valid, please try again \n";
        } while (!clsDate::IsDateValid(date));
    }
    static void ReadFullDate(short& day, short& month, int& year)
    {
        clsDate date;
        clsDate::ReadFullDate(date);
        day = date._day;
        month = date._month;
        year = date._year;
    }
    void ReadFullDate()
    {
        clsDate::ReadFullDate(*this);
    }


    static clsDate GetCurrentSystemDate()
    {
        clsDate date;
        time_t t = time(0);   // get time now
        struct tm now;
        localtime_s(&now, &t);
        date._day = now.tm_mday;
        date._month = now.tm_mon + 1;
        date._year = now.tm_year + 1900;
        return date;
    }
    void LoadCurrentSystemDate()
    {
        time_t t = time(0);   // get time now
        struct tm now;
        localtime_s(&now, &t);
        this->_day = now.tm_mday;
        this->_month = now.tm_mon + 1;
        this->_year = now.tm_year + 1900;
    }


    static void PrintDate(const short& day, const short& month, const int& year)
    {
        cout << clsDate::WeekDayOrderToName(WeekDayOrder(day, month, year)) << " " << day << "/" << month << "/" << year << endl;
    }
    static void PrintDate(const clsDate& date)
    {
        clsDate::PrintDate(date._day, date._month, date._year);
    }
    void PrintDate()
    {
        clsDate::PrintDate(*this);
    }


    static void PrintYearVariables(int year)
    {
        cout << "number of days in    [" << year << "] " << clsDate::NumberOfDaysInYear(year) << " day" << endl;
        cout << "number of hours in   [" << year << "] " << clsDate::NumberOfHoursInYear(year) << " hour" << endl;
        cout << "number of minutes in [" << year << "] " << clsDate::NumberOfMinutesInYear(year) << " minute" << endl;
        cout << "number of seconds in [" << year << "] " << clsDate::NumberOfSecondsInYear(year) << " second" << endl;
    }
    void PrintYearVariables() const
    {
        clsDate::PrintYearVariables(this->_year);
    }


    static void PrintmonthVariables(short month, int year)
    {
        cout << "number of days in    [" << month << "] " << clsDate::NumberOfDaysInMonth(month, year) << " day" << endl;
        cout << "number of hours in   [" << month << "] " << clsDate::NumberOfHoursInMonth(month, year) << " hour" << endl;
        cout << "number of minutes in [" << month << "] " << clsDate::NumberOfMinutesInMonth(month, year) << " minute" << endl;
        cout << "number of seconds in [" << month << "] " << clsDate::NumberOfSecondsInMonth(month, year) << " second" << endl;
    }
    void PrintmonthVariables(short month) const
    {
        clsDate::PrintmonthVariables(month, this->_year);
    }
    void PrintmonthVariables() const
    {
        clsDate::PrintmonthVariables(this->_month, this->_year);
    }


    static void PrintMonthCalender(const short& month, const int& year)
    {
        short numberOfDays = clsDate::NumberOfDaysInMonth(month, year);

        clsDate::PrintMonthHeader(month, year);
        clsDate::PrintMonthBody(month, numberOfDays, year);
        clsDate::PrintMonthFooter(month);
    }
    static void PrintMonthCalender(clsDate& date)
    {
        clsDate::PrintMonthCalender(date._month, date._year);
    }
    void PrintMonthCalender(const short& month) const
    {
        clsDate::PrintMonthCalender(month, this->_year);
    }
    void PrintMonthCalender() const
    {
        clsDate::PrintMonthCalender(this->_month, this->_year);
    }


    static void PrintYearCalender(int year)
    {
        clsDate::PrintYearHeader(year);
        for (int i = 1; i <= 12; i++)
        {
            clsDate::PrintMonthCalender(i, year);
            cout << endl;
        }
    }
    void PrintYearCalender() const
    {
        clsDate::PrintYearCalender(this->_year);
    }


    static void PrintDateVariables(const clsDate& d)
    {
        cout << "Today is ";
        clsDate::PrintDate(d);

        cout << "Is end of week ?\n";
        cout << (clsDate::IsEndOfWeek(d) ? "Yes, its the end of the week" : "No, it's not the end of the week");
        cout << endl << endl;

        cout << "Is Weekend ?\n";
        cout << (clsDate::IsWeekEnd(d) ? "Yes, its Weekend" : "No, it's not Weekend");
        cout << endl << endl;

        cout << "Is Business day ?\n";
        cout << (clsDate::IsBusinessDay(d) ? "Yes, its Business Day" : "No, it's not Business Day");
        cout << endl << endl;

        cout << "Days until the end of the week: " << clsDate::DaysUntilTheEndOfTheWeek(d) << "Day(s)" << endl;
        cout << "Days until the end of the month: " << clsDate::DaysUntilTheEndOfTheMonth(d) << "Day(s)" << endl;
        cout << "Days until the end of the year: " << clsDate::DaysUntilTheEndOfTheYear(d) << "Day(s)" << endl;
    }
    void PrintDateVariables() const
    {
        clsDate::PrintDateVariables(*this);
    }

    //------------------------------------------------------------------------------------------
    static bool IsDateValid(short day, short month, int year)
    {
        if (day < 1 || month < 1 || year < 1)
            return false;

        if (day > clsDate::NumberOfDaysInMonth(month, year))
            return false;

        if (month > 12)
            return false;

        return true;
    }
    static bool IsDateValid(clsDate d)
    {
        return clsDate::IsDateValid(d._day, d._month, d._year);
    }
    bool IsDateValid() const
    {
        return clsDate::IsDateValid(this->_day, this->_month, this->_year);
    }

    static bool IsLeap(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    bool IsLeap() const
    {
        return clsDate::IsLeap(this->_year);
    }

    static bool IsDate1BeforeDate2(const short& day1, const short& month1, const short& year1, const short& day2, const short& month2, const short& year2)
    {
        // 1. Check Year
        if (year1 < year2) return true;
        if (year1 > year2) return false;

        // 2. If years are equal, check Month
        if (month1 < month2) return true;
        if (month1 > month2) return false;

        // 3. If years and months are equal, check Day
        return day1 < day2;

        // We could use ternary but its less readable
        // return (d1.year < d2.year) ? true : ((d1.year == d2.year) ? ((d1.month < d2.month) ? true : (d1.month == d2.month) ? (d1.day < d2.day) : false) : false);
    }
    static bool IsDate1BeforeDate2(const clsDate& d1, const clsDate& d2)
    {
        return clsDate::IsDate1BeforeDate2(d1._day, d1._month, d1._year, d2._day, d2._month, d2._year);
    }
    bool IsDate1BeforeDate2(const clsDate& d2) const
    {
        return clsDate::IsDate1BeforeDate2(*this, d2);
    }

    static bool AreaDatesEqual(const short& day1, const short& month1, const int& year1, const short& day2, const short& month2, const int& year2)
    {
        return (day1 == day2 && month1 == month2 && year1 == year2);
    }
    static bool AreDatesEqual(clsDate d1, clsDate d2)
    {
        return clsDate::AreaDatesEqual(d1._day, d1._month, d1._year, d2._day, d2._month, d2._year);
    }
    bool AreDatesEqual(clsDate d2) const
    {
        return clsDate::AreDatesEqual(*this, d2);
    }

    static bool IsDate1AfterDate2(const short& day1, const short& month1, const int& year1, const short& day2, const short& month2, const int& year2)
    {
        return (!clsDate::IsDate1BeforeDate2(day1, month1, year1, day2, month2, year2) && !clsDate::AreaDatesEqual(day1, month1, year1, day2, month2, year2));
    }
    static bool IsDate1AfterDate2(const clsDate& d1, const clsDate& d2)
    {
        return (!clsDate::IsDate1BeforeDate2(d1, d2) && !clsDate::AreDatesEqual(d1, d2));
    }
    bool IsDate1AfterDate2(const clsDate& d2) const
    {
        return clsDate::IsDate1AfterDate2(*this, d2);
    }

    enum enDateCompare { Before = -1, Equal = 0, After = 1 };
    static enDateCompare CompareDates(const clsDate& d1, const clsDate& d2)
    {
        if (clsDate::IsDate1BeforeDate2(d1, d2))
            return enDateCompare::Before;

        if (clsDate::AreDatesEqual(d1, d2))
            return enDateCompare::Equal;

        return enDateCompare::After;

    }

    static bool IsLastDayInMonth(short day, short month, int year)
    {
        return  (day == clsDate::NumberOfDaysInMonth(month, year));
    }
    static bool IsLastDayInMonth(clsDate date)
    {
        return clsDate::IsLastDayInMonth(date._day, date._month, date._year);
    }
    bool IsLastDayInMonth() const
    {
        return clsDate::IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(clsDate date)
    {
        return  (date._month == 12);
    }
    bool IsLastMonthInYear() const
    {
        return clsDate::IsLastMonthInYear(*this);
    }

    static bool IsEndOfWeek(const clsDate& d)
    {
        return (clsDate::WeekDayOrder(d) == 6);
    }
    bool IsEndOfWeek() const
    {
        return clsDate::IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(const clsDate& d)
    {
        short dayOrder = clsDate::WeekDayOrder(d);

        return (dayOrder == 5 || dayOrder == 6);
    }
    bool IsWeekEnd() const
    {
        return clsDate::IsWeekEnd(*this);
    }

    static bool IsBusinessDay(const clsDate& d)
    {
        short dayOrder = clsDate::WeekDayOrder(d);
        return (dayOrder != 5 && dayOrder != 6);

        //easier to mantain since the logic is written only once
        return !clsDate::IsWeekEnd(d);
    }
    bool IsBusinessDay() const
    {
        return clsDate::IsBusinessDay(*this);
    }



    // ------------------------------------------------ Date Calculations Functions ------------------------------------------------

    static int NumberOfDaysInYear(const int& year)
    {
        return clsDate::IsLeap(year) ? 366 : 365;
    }
    int NumberOfDaysInYear() const
    {
        return clsDate::NumberOfDaysInYear(this->_year);
    }

    static int NumberOfHoursInYear(const int& year)
    {
        return clsDate::NumberOfDaysInYear(year) * 24;
    }
    int NumberOfHoursInYear() const
    {
        return clsDate::NumberOfHoursInYear(this->_year);
    }

    static long NumberOfMinutesInYear(const int& year)
    {
        return clsDate::NumberOfHoursInYear(year) * 60;
    }
    long NumberOfMinutesInYear() const
    {
        return clsDate::NumberOfMinutesInYear(this->_year);
    }

    static long NumberOfSecondsInYear(const int& year)
    {
        return clsDate::NumberOfMinutesInYear(year) * 60;
    }
    long NumberOfSecondsInYear() const
    {
        return clsDate::NumberOfSecondsInYear(this->_year);
    }

    static int NumberOfDaysInMonth(const short& month, const int& year)
    {
        if (month >= 1 && month <= 12)
        {
            const int numberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            return (month == 2) ? (clsDate::IsLeap(year) ? 29 : 28) : numberOfDays[month - 1];
        }
        else
            return 0;
    }
    int NumberOfDaysInMonth(const short& month) const
    {
        return clsDate::NumberOfDaysInMonth(month, this->_year);
    }
    int NumberOfDaysInMonth() const
    {
        return clsDate::NumberOfDaysInMonth(this->_month, this->_year);
    }

    static int NumberOfHoursInMonth(const short& month, const int& year)
    {
        return clsDate::NumberOfDaysInMonth(month, year) * 24;
    }
    int NumberOfHoursInMonth(const short& month) const
    {
        return clsDate::NumberOfHoursInMonth(month, this->_year);
    }
    int NumberOfHoursInMonth() const
    {
        return clsDate::NumberOfHoursInMonth(this->_month, this->_year);
    }

    static long NumberOfMinutesInMonth(const short& month, const int& year)
    {
        return clsDate::NumberOfHoursInMonth(month, year) * 60;
    }
    long NumberOfMinutesInMonth(const short& month) const
    {
        return clsDate::NumberOfMinutesInMonth(month, this->_year);
    }
    long NumberOfMinutesInMonth() const
    {
        return clsDate::NumberOfMinutesInMonth(this->_month, this->_year);
    }

    static long NumberOfSecondsInMonth(const short& month, const int& year)
    {
        return clsDate::NumberOfMinutesInMonth(month, year) * 60;
    }
    long NumberOfSecondsInMonth(const short& month) const
    {
        return clsDate::NumberOfSecondsInMonth(month, this->_year);
    }
    long NumberOfSecondsInMonth() const
    {
        return clsDate::NumberOfSecondsInMonth(this->_month, this->_year);
    }

    static short WeekDayOrder(const short& day, const short& month, const int& year)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + (12 * a) - 2;
        // 0 -> sunday, 1 -> monday,  .....,   6 -> saturday
        return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    }
    static short WeekDayOrder(const clsDate& d)
    {
        return clsDate::WeekDayOrder(d._day, d._month, d._year);
    }
    short WeekDayOrder() const
    {
        return WeekDayOrder(*this);
    }

    static short DayOfYearOrder(const short& day, const short& month, const int& year)
    {
        short dayOrder = 0;
        for (int i = 1; i < month; i++)
        {
            dayOrder += clsDate::NumberOfDaysInMonth(i, year);
        }
        dayOrder += day;
        return dayOrder;
    }
    static short DayOfYearOrder(const clsDate& d)
    {
        return clsDate::DayOfYearOrder(d._day, d._month, d._year);
    }
    short DayOfYearOrder()
    {
        return clsDate::DayOfYearOrder(*this);
    }

    static short DaysSinceYearStart(const short& day, const short& month, const int& year)
    {
        short daysSinceJan_1st = 0;

        for (short i = 1; i < month; i++)
            daysSinceJan_1st += clsDate::NumberOfDaysInMonth(i, year);

        return daysSinceJan_1st + day;
    }
    static short DaysSinceYearStart(clsDate& date) 
    {
        return clsDate::DaysSinceYearStart(date._day, date._month, date._year);
    }
    short DaysSinceYearStart() const 
    {
        return clsDate::DaysSinceYearStart(this->_day, this->_month, this->_year);
    }

    static short DaysUntilTheEndOfTheWeek(const clsDate& d)
    {
        return 6 - clsDate::WeekDayOrder(d);
    }
    short DaysUntilTheEndOfTheWeek() const
    {
        return clsDate::DaysUntilTheEndOfTheWeek(*this);
    }

    static short DaysUntilTheEndOfTheMonth(const clsDate& d)
    {
        return clsDate::NumberOfDaysInMonth(d._month, d._year) - d._day;
    }
    short DaysUntilTheEndOfTheMonth() const
    {
        return clsDate::DaysUntilTheEndOfTheMonth(*this);
    }

    static short DaysUntilTheEndOfTheYear(const clsDate& d)
    {
        return clsDate::NumberOfDaysInYear(d._year) - clsDate::DayOfYearOrder(d);
    }
    short DaysUntilTheEndOfTheYear() const
    {
        return clsDate::DaysUntilTheEndOfTheYear(*this);
    }

    static int DateToDays(const clsDate& date)
    {
        int totalDays = 0;
        int y = date._year;

        // Days from non-leap years
        totalDays += (y - 1) * 365;
        // Add the extra day for leap years, exluding every 100th year ,but including every 400th year
        totalDays += (y - 1) / 4;
        totalDays -= (y - 1) / 100;
        totalDays += (y - 1) / 400;

        for (int m = 1; m < date._month; m++)
            totalDays += clsDate::NumberOfDaysInMonth(m, y);

        totalDays += date._day;

        return totalDays;
    }
    int DateToDays() const
    {
        return clsDate::DateToDays(*this);
    }

    static int DateDifferenceInDays(const clsDate& d1, const clsDate& d2)
    {
        return abs(clsDate::DateToDays(d1) - clsDate::DateToDays(d2));
    }
    int DateDifferenceInDays(const clsDate& d2) const
    {
        return clsDate::DateDifferenceInDays(*this, d2);
    }

    static short CalculateVacationDays(clsDate dFrom, const clsDate& dTo)
    {
        int counter = 0;
        while (clsDate::IsDate1BeforeDate2(dFrom, dTo))
        {
            if (clsDate::IsBusinessDay(dFrom))
                counter++;

            dFrom = clsDate::IncreaseDateByOneDay(dFrom);
        }

        return counter;
    }

    static clsDate CalculateVacationEndDate(const clsDate& dFrom, short vacationDays)
    {
        clsDate currentDate = dFrom;
        while (vacationDays > 0)
        {
            if (IsBusinessDay(currentDate))
                vacationDays--;

            clsDate::IncreaseDateByOneDay(currentDate);
        }

        return currentDate;
    }

    static clsDate GetMinDate(const clsDate& d1, const clsDate& d2)
    {
        return  (clsDate::CompareDates(d1, d2) == Before ? d1 : d2);
    }
    clsDate GetMinDate(const clsDate& d2) const
    {
        return clsDate::GetMinDate(*this, d2);
    }

    static clsDate GetMaxDate(clsDate d1, clsDate d2)
    {
        return  (clsDate::CompareDates(d1, d2) == After ? d1 : d2);
    }
    clsDate GetMaxDate(const clsDate& d2) const
    {
        return clsDate::GetMaxDate(*this, d2);
    }


    static clsDate GetDateByDayOrderInYear(short noOfDays, const int& year)
    {
        clsDate date;

        date._year = year;
        while (noOfDays > 365)
        {
            noOfDays -= clsDate::NumberOfDaysInYear(year);
            date._year++;
        }
        for (short i = 1; i < 13; i++)
        {
            date._month = i;
            short currentMonthDays = clsDate::NumberOfDaysInMonth(date._month, year);
            if (noOfDays <= currentMonthDays)
            {
                date._day = noOfDays;
                return date;
            }
            noOfDays -= currentMonthDays;
        }

        return date;
    }
    void GetDateByDayOrderInYear(short noOfDays) 
    { 
        *this = clsDate::GetDateByDayOrderInYear(noOfDays, this->_year);
    }

    static clsDate DateAfterXDays(const clsDate& initDate, short daysAfter)
    {
        clsDate newDate = initDate;

        short currentYearDays = clsDate::DaysSinceYearStart(initDate._day, initDate._month, initDate._year);
        short remainingYearDays = clsDate::NumberOfDaysInYear(initDate._year) - currentYearDays;
        //calculating years
        while (daysAfter >= remainingYearDays)
        {
            daysAfter -= remainingYearDays;
            newDate._year++;
            remainingYearDays = clsDate::NumberOfDaysInYear(newDate._year);
        }
        newDate = clsDate::GetDateByDayOrderInYear(daysAfter, newDate._year);

        return newDate;
    }
    void DateAfterXDays(short daysAfter)
    {
        *this = clsDate::DateAfterXDays(*this, daysAfter);
    }


    // ------------------------------------------------------ Date String Functions -----------------------------------------------------
    static string DayName(const short& day, const short& month, const int& year)
    {
        return clsDate::WeekDayOrderToName(clsDate::WeekDayOrder(day, month, year));
    }
    static string DayName(const clsDate& d)
    {
        return clsDate::WeekDayOrderToName(clsDate::WeekDayOrder(d));
    }
    string DayName() const
    {
        return clsDate::DayName(*this);
    }

    static string MonthOrderToName(const short& month)
    {
        if (month > 12 || month < 1)
        {
            return "Invalid Month";
        }
        string monthName[12] = { "January" ,"February" ,"March" ,"April" ,"May" ,"June" ,"July" ,"August" ,"September" ,"October", "November" , "December" };
        return monthName[month - 1];
    }
    string MonthOrderToName() const
    {
        return clsDate::MonthOrderToName(this->_month);
    }

    static string DateToString(const clsDate& d, const string& del = "/")
    {
        return to_string(d._day) + del + to_string(d._month) + del + to_string(d._year);
    }
    string DateToString(const string& del = "/") const
    {
        return clsDate::DateToString(*this, del);
    }

    static clsDate StringToDate(const string& dateString, const string& delimiter = "/")
    {
        vector<string> dateParts = clsString::Split(dateString, delimiter);

        if (dateParts.size() != 3)
        {
            return clsDate();
        }

        short day = stoi(dateParts[0]);
        short month = stoi(dateParts[1]);
        int year = stoi(dateParts[2]);

        return clsDate(day, month, year);
    }

    // ------------------------------------------------------ Date Manipulation Functions -----------------------------------------------------

    static clsDate IncreaseDateByOneDay(clsDate d)
    {
        d._day++;
        if (d._day > clsDate::NumberOfDaysInMonth(d._month, d._year))
        {
            d._day = 1;

            if (d._month == 12)
            {
                d._month = 1;
                d._year++;
            }
            else {
                d._month++;
            }

        }
        return d;
    }
    void IncreaseDateByOneDay()
    {
        *this = clsDate::IncreaseDateByOneDay(*this);
    }

    static clsDate IncreaseDateByXDays(clsDate  d, const int& xdays)
    {
        for (int i = 0; i < xdays; i++)
        {
            d = clsDate::IncreaseDateByOneDay(d);
        }
        return d;
    }
    void IncreaseDateByXDays(const int& xdays)
    {
        *this = clsDate::IncreaseDateByXDays(*this, xdays);
    }

    static clsDate IncreaseDateByOneWeek(const clsDate& d)
    {
        return clsDate::IncreaseDateByXDays(d, 7);
    }
    void IncreaseDateByOneWeek()
    {
        *this = clsDate::IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeeks(const clsDate& d, const int& xWeeks)
    {
        return clsDate::IncreaseDateByXDays(d, xWeeks * 7);
    }
    void IncreaseDateByXWeeks(int xWeeks)
    {
        *this = clsDate::IncreaseDateByXWeeks(*this, xWeeks);
    }

    static clsDate IncreaseDateByOneMonth(clsDate d)
    {
        d._month++;

        if (d._month > 12) {
            d._month = 1;
            d._year++;
        }

        if (d._day > clsDate::NumberOfDaysInMonth(d._month, d._year))
        {
            d._day = clsDate::NumberOfDaysInMonth(d._month, d._year);
        }
        return d;
    }
    void IncreaseDateByOneMonth()
    {
        *this = clsDate::IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonths(clsDate d, const int& xMonths)
    {
        for (int i = 0; i < xMonths; i++)
        {
            d = clsDate::IncreaseDateByOneMonth(d);
        }
        return d;
    }
    void IncreaseDateByXMonths(const int& xMonths)
    {
        *this = clsDate::IncreaseDateByXMonths(*this, xMonths);
    }

    static clsDate IncreaseDateByOneYear(clsDate d)
    {
        d._year++;

        if (!clsDate::IsLeap(d._year) && d._month == 2 && d._day == 29)
            d._day = 28;

        return d;
    }
    void IncreaseDateByOneYear()
    {
        *this = clsDate::IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYears(clsDate d, const int& xYears)
    {
        d._year += xYears;
        if (!clsDate::IsLeap(d._year) && d._month == 2 && d._day == 29)
            d._day = 28;

        return d;
    }
    void   IncreaseDateByXYears(const int& xYears)
    {
        *this = clsDate::IncreaseDateByXYears(*this, xYears);
    }

    static clsDate IncreaseDateByOneDecade(clsDate d)
    {
        d._year += 10;
        if (!clsDate::IsLeap(d._year) && d._month == 2 && d._day == 29)
            d._day = 28;

        return d;
    }
    void IncreasDateByOneDecade()
    {
        *this = clsDate::IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(clsDate d, const int& xDecades)
    {
        d._year += 10 * xDecades;
        if (!clsDate::IsLeap(d._year) && d._month == 2 && d._day == 29)
            d._day = 28;

        return d;
    }
    void IncreaseDateByXDecades(const int& xDecades)
    {
        *this = clsDate::IncreaseDateByXDecades(*this, xDecades);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate d)
    {
        d._year += 1000;
        if (!clsDate::IsLeap(d._year) && d._month == 2 && d._day == 29)
            d._day = 28;

        return d;
    }
    void IncreaseDateByOneMillennium()
    {
        *this = clsDate::IncreaseDateByOneMillennium(*this);
    }

    static clsDate IncreaseDateByXMillenniums(clsDate d, const int& xMillenniums)
    {
        d._year += 1000 * xMillenniums;
        if (!clsDate::IsLeap(d._year) && d._month == 2 && d._day == 29)
            d._day = 28;

        return d;
    }
    void IncreaseDateByXMillenniums(const int& xMillenniums)
    {
        *this = clsDate::IncreaseDateByXMillenniums(*this, xMillenniums);
    }

    static clsDate DecreaseDateByOneDay(clsDate d)
    {
        d._day--;
        if (d._day < 1)
        {
            d._month--;
            if (d._month < 1)
            {
                d._year--;
                d._month = 12;
            }
            d._day = clsDate::NumberOfDaysInMonth(d._month, d._year);
        }

        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByOneDay()
    {
        *this = clsDate::DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDays(clsDate d, const int& xDays)
    {
        for (int i = 0; i < xDays; i++)
        {
            d = clsDate::DecreaseDateByOneDay(d);
        }

        return d;
    }
    void   DecreaseDateByXDays(const int& xDays)
    {
        *this = clsDate::DecreaseDateByXDays(*this, xDays);
    }

    static clsDate DecreaseDateByOneWeek(clsDate d)
    {
        for (short i = 0; i < 7; i++)
        {
            d = clsDate::DecreaseDateByOneDay(d);
        }

        return d;
    }
    void DecreaseDateByOneWeek()
    {
        *this = clsDate::DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(clsDate d, const int& xWeeks)
    {
        for (short i = 0; i < xWeeks * 7; i++)
        {
            d = clsDate::DecreaseDateByOneDay(d);
        }

        return d;
    }
    void DecreaseDateByXWeeks(const int& xWeeks)
    {
        *this = clsDate::DecreaseDateByXWeeks(*this, xWeeks);
    }

    static clsDate DecreaseDateByOneMonth(clsDate d)
    {
        d._month--;
        if (d._month < 1)
        {
            d._month = 12;
            d._year--;
        }

        //important day check 
        short lastDayInMonth = clsDate::NumberOfDaysInMonth(d._month, d._year);
        if (d._day > lastDayInMonth)
            d._day = lastDayInMonth;

        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByOneMonth()
    {
        *this = clsDate::DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonths(clsDate d, const int& xMonths)
    {
        //d.month -= xMonths;
        //while (d.month < 1) {
        //    d.month += 12;
        //    d.year--;   
        //}
        //  //  important day check 
        //short lastDayInMonth = NumberOfDaysInMonthOneLine(d.month, d.year);
        //if (d.day > lastDayInMonth)
        //    d.day = lastDayInMonth;

        // OR Simply :
        for (int i = 0; i < xMonths; i++)
        {
            d = clsDate::DecreaseDateByOneMonth(d);
        }

        return d;
    }
    void DecreaseDateByXMonths(const int& xMonths)
    {
        *this = clsDate::DecreaseDateByXMonths(*this, xMonths);
    }

    static clsDate DecreaseDateByOneYear(clsDate d)
    {
        d._year--;
        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByOneYear()
    {
        *this = clsDate::DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(clsDate d, const int& xYears)
    {
        d._year -= xYears;

        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByXYears(const int& xYears)
    {
        *this = clsDate::DecreaseDateByXYears(*this, xYears);
    }

    static clsDate DecreaseDateByDecade(clsDate d)
    {
        d._year -= 10;

        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByOneDecade()
    {
        *this = clsDate::DecreaseDateByDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(clsDate d, const int& xDecades)
    {
        d._year -= xDecades * 10;

        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByXDecades(const int& xDecades)
    {
        *this = clsDate::DecreaseDateByXDecades(*this, xDecades);
    }

    static clsDate DecreaseDateByCentury(clsDate d)
    {
        d._year -= 100;
        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByOneCentury()
    {
        *this = clsDate::DecreaseDateByCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate d)
    {
        d._year -= 1000;
        if (!clsDate::IsDateValid(d))
            d = clsDate();

        return d;
    }
    void DecreaseDateByOneMillennium()
    {
        *this = clsDate::DecreaseDateByOneMillennium(*this);
    }

    enum enDateFormat
    {
        DayMonthYear = 1,      // 01/01/2024
        MonthDayYear = 2,      // 01/01/2024
        YearMonthDay = 3,      // 2024/01/01
        DayMonthYearDash = 4,  // 01-01-2024
        MonthDayYearDash = 5,  // 01-01-2024
        FullString = 6         // Day: 01 Month: 01 Year: 2024
    };
    static string DateFormat(const clsDate& d, const enDateFormat& format = enDateFormat::DayMonthYear)
    {
        char del = '/';

        if (format == MonthDayYearDash || format == DayMonthYearDash)
            del = '-';

        switch (format)
        {
        case DayMonthYear:
        case DayMonthYearDash:
            return  to_string(d._day) + del + to_string(d._month) + del + to_string(d._year);

        case MonthDayYear:
        case MonthDayYearDash:
            return  to_string(d._month) + del + to_string(d._day) + del + to_string(d._year);

        case YearMonthDay:
            return  to_string(d._year) + del + to_string(d._month) + del + to_string(d._day);

        case FullString:
            del = ' ';
            return "Day: " + to_string(d._day) + del + del + "Month: " + to_string(d._month) + del + del + "Year: " + to_string(d._year);

        default:
            return  to_string(d._day) + del + to_string(d._month) + del + to_string(d._year);

        }

    }
    string DateFormat(const enDateFormat& format = enDateFormat::DayMonthYear) const
    {
        return clsDate::DateFormat(*this, format);
    }

    static string DateFormat(const clsDate& d, string dateFormat = "dd/mm/yyyy")
    {
        dateFormat = clsString::Replace(dateFormat, "dd", to_string(d._day));
        dateFormat = clsString::Replace(dateFormat, "mm", to_string(d._month));
        dateFormat = clsString::Replace(dateFormat, "yyyy", to_string(d._year));

        return dateFormat;
    }
    string DateFormat(string dateFormat = "dd/mm/yyyy") const
    {
        return clsDate::DateFormat(*this, dateFormat);
    }
};



// ------------------------------------------------------ Period Functions -----------------------------------------------------

struct stPeriod
{
    clsDate startDate;
    clsDate endDate;
};

static stPeriod ReadPeriod()
{
    stPeriod p;
    cout << "Enter period start date:\n";
    clsDate::ReadFullDate(p.startDate);
    cout << "Enter period end date:\n";
    clsDate::ReadFullDate(p.endDate);
    return p;
}

static bool ArePeriodsOverlap(const stPeriod& p1, const stPeriod& p2)
{
    if (
        clsDate::IsDate1AfterDate2(p1.startDate, p2.endDate)
        ||
        clsDate::IsDate1AfterDate2(p2.startDate, p1.endDate)
        )
        return false;

    return true;
}

static int CountPeriodDays(stPeriod  p, const bool& includingEndDay = false)
{
    int daysCounter = 0;
    while (clsDate::CompareDates(p.startDate, p.endDate) == clsDate::enDateCompare::Before)
    {
        daysCounter++;
        p.startDate = clsDate::IncreaseDateByOneDay(p.startDate);
    }

    return includingEndDay ? ++daysCounter : daysCounter;
}

static int CountPeriodDays(clsDate  startDate, const clsDate& endDate, const bool& includingEndDay = false)
{
    int daysCounter = 0;
    while (clsDate::CompareDates(startDate, endDate) == clsDate::enDateCompare::Before)
    {
        daysCounter++;
        startDate = clsDate::IncreaseDateByOneDay(startDate);
    }

    return includingEndDay ? ++daysCounter : daysCounter;
}

static bool IsDateWithinPeriod(const stPeriod& p, const clsDate& d)
{
    //chekcing if date is oustside the period
    return
        !(
            clsDate::CompareDates(d, p.startDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(d, p.endDate) == clsDate::enDateCompare::After
            );
}

static int CountOverLapDays(const stPeriod& p1, const stPeriod& p2)
{
    if ( ! ArePeriodsOverlap(p1, p2))
        return 0;

    clsDate overlapStartDay = clsDate::GetMaxDate(p1.startDate, p2.startDate);
    clsDate overlapEndDay = clsDate::GetMinDate(p1.endDate, p2.endDate);

    return clsDate::DateDifferenceInDays(overlapStartDay, overlapEndDay) + 1;
}