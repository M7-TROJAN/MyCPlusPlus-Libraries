#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <vector>

struct stDate
{
    short day;
    short month;
    short year;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enDateCompare {Before = -1, Equal = 0, After = 1};

bool isLeapYear(const short &Year);
short NumberOfDaysInAYear(const short &Year);
short NumberOfHoursInAYear(const short &Year);
int NumberOfMinutesInAYear(const short &Year);
int NumberOfSecondsInAYear(const short &Year);

short getNumberOfDaysInAMonth(const short &month, const short &year);
short getNumberOfHoursInAMonth(const short& month, const short& year);
int getNumberOfMinutesInAMonth(const short& month, const short& year);
int getNumberOfSecondsInAMonth(const short& month, const short& year);

short calculateDayOfWeekOrder(const short &day, const short &month, const short &year);
short calculateDayOfWeekOrder(const stDate &date);
std::string getDayShortName(const short &dayOfWeekOrder);
std::string getDayShortName(const stDate &date);


std::string monthShortName(const short &monthNumber);
void printMonthCalendar(const short &month, const short &year);
void printYearCalendar(const short &year);

short getNumberOfDaysFromTheBeginningOfYear(const short& day, const short& month, const short& year);
short getNumberOfDaysFromTheBeginningOfYear(stDate date);


stDate GetDateFromDayOrderInYear(const short &daysOrderInYear, const short &year);
stDate dateAddDays(stDate date, const int &daysToAdd);

bool IsDate1BeforeDate2(const stDate &date1, const stDate &date2);
bool IsDate1EqualDate2(const stDate &date1, const stDate &date2);
bool IsDate1AfterDate2(const stDate &date1, const stDate &date2);
bool IsLastDayInMonth(const stDate &date);
bool IsLastMonthInYear(const short &month);
bool IsFirstDayInMonth(const short &day);
bool IsFirstMonthInYear(const short &month);
bool IsEndOfWeek(const stDate &date);
bool IsWeekEnd(const stDate &date);
bool IsWeekEndEuropeanSys(const stDate &date);
bool IsBusinessDay(const stDate &date);
bool IsBusinessDayEuropeanSys(const stDate &date);
stDate MinDate(const stDate &date1, const stDate &date2);
stDate MaxDate(const stDate &date1, const stDate &date2);


short compareDates(const stDate &date1, const stDate &date2);
enDateCompare compDates(const stDate &date1, const stDate &date2);

bool IsOverlapPeriods(const stPeriod &period1, const stPeriod &period2);
int PeriodLengthInDays(const stPeriod &Period, bool IncludeEndDate = false);
bool isDateInPeriod(const stDate &Date, const stPeriod &Period);
int countOverlapDays(const stPeriod &period1, const stPeriod &period2);
int Count_Overlap_Days(stPeriod Period1, stPeriod Period2); // another algorithm

short daysUntilTheEndOfWeek(const stDate &date);
short daysUntilTheEndOfMonth(const stDate &date, const bool &IncludeCurrentDay);
short daysUntilTheEndOfYear(const stDate &date, bool IncludeCurrentDay);

stDate IncreaseDateByOneDay(stDate Date);
stDate IncreaseDateByXDays(stDate date, const short &daysToAdd);
stDate IncreaseDateByOneWeek(stDate date);
stDate IncreaseDateByXWeeks(stDate date, const short &weeksToAdd);
stDate IncreaseDateByOneMonth(stDate date);
stDate IncreaseDateByXMonths(stDate date, const short &MonthsToAdd);
stDate IncreaseDateByOneYear(stDate date);
stDate IncreaseDateByXYears(stDate date, const short &YearsToAdd);
stDate IncreaseDateByOneDecade(stDate date);
stDate IncreaseDateByXDecades(stDate date, const short &DecadesToAdd);
stDate IncreaseDateByOneCentury(stDate date);
stDate IncreaseDateByOneMillennium(stDate date);

stDate DecreaseDateByOneDay(stDate Date);
stDate DecreaseDateByXDays(stDate date, const short &numberOfDays);
stDate DecreaseDateByOneWeek(stDate date);
stDate DecreaseDateByXWeeks(stDate date, const short &numberOfWeeks);
stDate DecreaseDateByOneMonth(stDate date);
stDate DecreaseDateByXMonths(stDate date, const short &numberOfMonths);
stDate DecreaseDateByOneYear(stDate date);
stDate DecreaseDateByXYears(stDate date, const short &numberOfYears);
stDate DecreaseDateByOneDecade(stDate date);
stDate DecreaseDateByXDecades(stDate date, const short &numberOfDecades);
stDate DecreaseDateByOneCentury(stDate date);
stDate DecreaseDateByOneMillennium(stDate date);


int getDifferenceBetween2Dates(stDate date1, stDate date2, bool IncludeEndDay = false);
int differenceBetween2Dates(stDate date1, stDate date2, bool includeEndDay = false);
short calculateVacationDays(stDate dateFrom, const stDate &dateTo);
stDate calculateVacationReturnDate(const stDate &VacationStartsDate, const short &VacationDays);


bool isValidDate(const stDate &date);

std::vector<std::string> splitString(const std::string& str, const std::string& delimiter);
std::string removeSpaces(const std::string &str);
stDate stringToDate(const std::string &dateString);
std::string dateToString(const stDate &Date);
std::string readStringDate(const std::string &message);
stDate readDate(const std::string &message = "Please enter a date in the format (dd-mm-yyyy): ");

std::string replaceWordInString(const std::string &input, const std::string &wordToReplace, const std::string &replacement);
std::string formateDate(const stDate &date, const std::string &dateFormat = "dd-mm-yyyy");


stPeriod ReadPeriod();

stDate readDateOldVersion();
// stDate readFullDate();

stDate getCurrentDate();

void swapDates(stDate &date1, stDate &date2);
void swapPeriods(stPeriod &Period1, stPeriod &Period2);
#endif // DATE_H
