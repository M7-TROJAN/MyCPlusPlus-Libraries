#include "date.h"

// Determines if the given year is a leap year
// Leap year if year is divisible by 4 AND not divisible by 100 OR if it's divisible by 400
bool isLeapYear(const short &Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Returns the number of days in a year
short NumberOfDaysInAYear(const short &Year) 
{ 
    return isLeapYear(Year) ? 366 : 365; 
}

// Returns the number of hours in a year
short NumberOfHoursInAYear(const short &Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}

// Returns the number of minutes in a year
int NumberOfMinutesInAYear(const short &Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}

// Returns the number of seconds in a year
int NumberOfSecondsInAYear(const short &Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}

// Returns the number of hours in a specific month of a year
short getNumberOfHoursInAMonth(const short& month, const short& year)
{
    return getNumberOfDaysInAMonth(month, year) * 24;
}

// Returns the number of minutes in a specific month of a year
int getNumberOfMinutesInAMonth(const short& month, const short& year)
{
    return getNumberOfHoursInAMonth(month, year) * 60;
}

// Returns the number of seconds in a specific month of a year
int getNumberOfSecondsInAMonth(const short& month, const short& year)
{
    return getNumberOfMinutesInAMonth(month, year) * 60;
}

// Returns the number of days in a specific month of a year
short getNumberOfDaysInAMonth(const short &month, const short &year)
{
    if (month < 1 || month > 12) return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year))? 29 : NumberOfDays[month - 1];
}

// Calculates the day of the week (0: Sunday, 1: Monday, ..., 6: Saturday) using the Gregorian Calendar formula
short calculateDayOfWeekOrder(const short &day, const short &month, const short &year)
{
    short a, y, m;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    // Calculate the day of the week using Gregorian Calendar formula
    // Gregorian (ميلادي) => 0: Sun, 1: Mon, 2: Tue, ... , 6: Sat
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

// Calculates the day of the week (0: Sunday, 1: Monday, ..., 6: Saturday) using the Gregorian Calendar formula
short calculateDayOfWeekOrder(const stDate &date)
{
    short a, y, m;

    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + (12 * a) - 2;

    // Calculate the day of the week using Gregorian Calendar formula
    // Gregorian (ميلادي) => 0: Sun, 1: Mon, 2: Tue, ... , 6: Sat
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


// Returns the short name of a day of the week (e.g., "Sun" for Sunday)
std::string getDayShortName(const short &dayOfWeekOrder)
{
    const std::string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[dayOfWeekOrder];
}

// Returns the short name of a day of the week (e.g., "Sun" for Sunday)
std::string getDayShortName(const stDate &date)
{
    short dayOfWeekOrder = calculateDayOfWeekOrder(date);
    const std::string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[dayOfWeekOrder];
}

// Returns the short name of a month (e.g., "Jan" for January)
std::string monthShortName(const short &monthNumber)
{
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return (months[monthNumber - 1]);
}

// Prints a calendar for a specific month and year
void printMonthCalendar(const short &month, const short &year)
{
    int currentDay, numberOfDays;

    // Get the index of the day from 0 to 6
    currentDay = calculateDayOfWeekOrder(1, month, year);

    numberOfDays = getNumberOfDaysInAMonth(month, year);

    // Print the current month name
    printf("\n_____________ %s _______________\n\n", monthShortName(month).c_str());
    // Print the columns
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate spaces for the first day
    for (int i = 0; i < currentDay; i++)
        printf("     ");

    // Print days with proper alignment
    for (int day = 1; day <= numberOfDays; day++)
    {
        printf("%-5d", day);
        if ((currentDay + day) % 7 == 0) // just some Logic Bro :)
            printf("\n");
    }

    printf("\n__________________________________\n");
}

// Prints a calendar for the entire year
void printYearCalendar(const short &year)
{
    printf("\n_________________________________\n\n");
    printf("        Calender - %hd        ", year);
    printf("\n_________________________________\n\n");
    for(int month = 1; month <= 12; month++)
    {
        printMonthCalendar(month, year);
    }
}

// Calculates the number of days from the beginning of the year until the specified date
short getNumberOfDaysFromTheBeginningOfYear(const short& day, const short& month, const short& year)
{
    short totalDays = day;
    for (int i = 1; i < month; i++)
    {
        totalDays += getNumberOfDaysInAMonth(i, year);
    }
    return totalDays;
}

// Calculates the number of days from the beginning of the year until the specified date
short getNumberOfDaysFromTheBeginningOfYear(stDate date)
{
    short totalDays = date.day;
    for (int i = 1; i < date.month; i++)
    {
        totalDays += getNumberOfDaysInAMonth(i, date.year);
    }
    return totalDays;
}

// Returns the date corresponding to the given day order within a year
stDate GetDateFromDayOrderInYear(const short &daysOrderInYear, const short &year)
{
    stDate date;
    date.year = year;

    int totalDays = 0;
    for (int month = 1; month <= 12; month++)
    {
        int daysInMonth = getNumberOfDaysInAMonth(month, year);
        for (int day = 1; day <= daysInMonth; day++)
        {
            totalDays++;
            if (totalDays == daysOrderInYear)
            {
                date.day = day;
                date.month = month;
                return date;
            }
        }
    }

    return date;
}

// Adds the specified number of days to a given date
stDate dateAddDays(stDate date, const int &daysToAdd)
{
    short remainingDays = daysToAdd + getNumberOfDaysFromTheBeginningOfYear(date.day, date.month, date.year);
    short monthDays = 0;
    date.month = 1;

    // Add the remaining days by iterating over the months
    while (true)
    {
        monthDays = getNumberOfDaysInAMonth(date.month, date.year);

        if (remainingDays > monthDays)
        {
            // Subtract the days of the current month and move to the next month
            remainingDays -= monthDays;
            date.month++;

            if (date.month > 12)
            {
                // Reset month to 1 and increment year if the current month exceeds 12
                date.month = 1;
                date.year++;
            }
        }
        else
        {
            // Assign the remaining days as the day value and break the loop
            date.day = remainingDays;
            break;
        }
    }

    return date;
}

// Checks if date1 is before date2
bool IsDate1BeforeDate2(const stDate &date1, const stDate &date2)
{
    if (date1.year < date2.year) return true;
    if (date1.year > date2.year) return false;

    if (date1.month < date2.month) return true;
    if (date1.month > date2.month)return false;

    if (date1.day < date2.day) return true;

    return false;
}

// Checks if date1 is Equal to date2
bool IsDate1EqualDate2(const stDate &date1, const stDate &date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

// Checks if date1 is after date2
bool IsDate1AfterDate2(const stDate &date1, const stDate &date2) 
{ 
    return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

// CompareDates function compares two dates and returns an integer value based on the comparison.
// If date1 is before date2, it returns -1.
// If date1 is equal to date2, it returns 0.
// If date1 is after date2, it returns 1.
short compareDates(const stDate &date1, const stDate &date2)
{
    if(IsDate1EqualDate2(date1, date2)) return 0;
    if(IsDate1AfterDate2(date1, date2)) return 1;
    return -1;
}

// compDates function compares two dates and returns an enDateCompare value based on the comparison.
// If date1 is before date2, it returns enDateCompare::Before.  -1
// If date1 is equal to date2, it returns enDateCompare::Equal.  0
// If date1 is after date2, it returns enDateCompare::After.     1
enDateCompare compDates(const stDate &date1, const stDate &date2)
{
    if (IsDate1EqualDate2(date1, date2)) 
        return enDateCompare::Equal;
    if(IsDate1AfterDate2(date1, date2)) 
        return enDateCompare::After;
    return enDateCompare::Before;
}

// Function to check if two periods overlap
bool IsOverlapPeriods(const stPeriod &period1, const stPeriod &period2)
{
    if (compareDates(period2.EndDate, period1.StartDate) == enDateCompare::Before||
    compareDates(period2.StartDate, period1.EndDate) == enDateCompare::After)
        return false;
    return true;
}

// Checks if the day in the given date is the last day of the month
bool IsLastDayInMonth(const stDate &date)
{
    return date.day == getNumberOfDaysInAMonth(date.month, date.year);
}

// Checks if the given month is the last month of the year
bool IsLastMonthInYear(const short &month)
{
    return month == 12;
}

// Returns the minimum date between two dates
stDate MinDate(const stDate &date1, const stDate &date2)
{
    return IsDate1BeforeDate2(date1, date2)? date1 : date2;
}

// Returns the maximum date between two dates
stDate MaxDate(const stDate &date1, const stDate &date2)
{
    return IsDate1BeforeDate2(date1, date2)? date2 : date1;
}

// Counts the number of overlapping days between two periods
int countOverlapDays(const stPeriod &period1, const stPeriod &period2)
{
    // Check if the two periods do not overlap
    if (!IsOverlapPeriods(period1, period2))
        return 0;

    // Determine the earliest end date between the two periods
    stDate minPeriodEndDate   = MinDate(period1.EndDate, period2.EndDate);
    // Determine the latest start date between the two periods
    stDate maxPeriodStartDate = MaxDate(period1.StartDate, period2.StartDate);

    // Calculate the difference in days between the earliest end date and the latest start date.
    int diffDays = differenceBetween2Dates(minPeriodEndDate, maxPeriodStartDate, true);

    return diffDays < 0 ? diffDays * -1 : diffDays;
}

// Counts the number of overlapping days between two periods
int Count_Overlap_Days(stPeriod Period1, stPeriod Period2)
{
    // Check if the two periods do not overlap
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    // Calculate the lengths of the two periods in days
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);

    // Initialize the counter for overlapping days
    int OverlapDays = 0;

    // If Period1 is shorter than Period2, iterate through each day in Period1
    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            // Check if the current day in Period1 falls within Period2
            if (isDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++; // Increment the counter for overlapping days

            // Move to the next day in Period1
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else // Period2 is shorter or equal to Period1, so iterate through each day in Period2
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            // Check if the current day in Period2 falls within Period1
            if (isDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++; // Increment the counter for overlapping days

            // Move to the next day in Period2
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    // Increment the overlapping days counter by 1 and return the result
    return ++OverlapDays;
}

// Checks if the given date falls on the end of the week (Saturday)
bool IsEndOfWeek(const stDate &date)
{
    return calculateDayOfWeekOrder(date) == 6;
}

// Checks if the given date falls on a weekend (Friday or Saturday in most Arab countries)
bool IsWeekEnd(const stDate &date)
{
    // Weekends in most Arab countries are Friday and Saturday, index of fri is 5 and sat is 6 in Gregorian Calendar formula.
    short dayIndex = calculateDayOfWeekOrder(date);
    return (dayIndex == 5 || dayIndex == 6);
}

// Checks if the given date falls on a weekend (Sunday or Saturday in European systems)
bool IsWeekEndEuropeanSys(const stDate &date)
{
    // Weekends are Sunday and Saturday, index of Sun is 0 and sat is 6 in Gregorian Calendar formula.
    short dayIndex = calculateDayOfWeekOrder(date);
    return (dayIndex == 0 || dayIndex == 6);
}

// Checks if the given date is a business day (not a weekend day)
bool IsBusinessDay(const stDate &date)
{
    // Business days are all days except Friday and Saturday.
    return  ! IsWeekEnd(date);
}

// Checks if the given date is a business day (not a weekend day in European systems)
bool IsBusinessDayEuropeanSys(const stDate &date)
{
    // Business days are all days except Sunday and Saturday.
    return  ! IsWeekEndEuropeanSys(date);
}

// Calculates the number of days until the end of the week (Saturday) from the given date
short daysUntilTheEndOfWeek(const stDate &date)
{
    return 6 - calculateDayOfWeekOrder(date);
}

// Calculates the number of days until the end of the month from the given date
// If IncludeCurrentDay is true, it includes the current day in the count
short daysUntilTheEndOfMonth(const stDate &date, const bool &IncludeCurrentDay = false)
{
    if(IncludeCurrentDay)
        return getNumberOfDaysInAMonth(date.month, date.year) - date.day + 1;
    
    return getNumberOfDaysInAMonth(date.month, date.year) - date.day;
}

// Calculates the number of days until the end of the year from the given date
// If IncludeCurrentDay is true, it includes the current day in the count
short daysUntilTheEndOfYear(const stDate &date, bool IncludeCurrentDay = false)
{
    if(IncludeCurrentDay)
        return NumberOfDaysInAYear(date.year) - getNumberOfDaysFromTheBeginningOfYear(date) + 1;
    
    return NumberOfDaysInAYear(date.year) - getNumberOfDaysFromTheBeginningOfYear(date);
}

// Increases the given date by one day
stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.month))
        {
            Date.month = 1;
            Date.day = 1;
            Date.year++;
        }
        else
        {
            Date.day = 1;
            Date.month++;
        }
    }
    else
    {
        Date.day++;
    }
    return Date;
}

// Increases the given date by a specified number of days
stDate IncreaseDateByXDays(stDate date, const short &daysToAdd)
{
    for (int i = 0; i < daysToAdd; i++)
        date = IncreaseDateByOneDay(date);
    return date;
}

// Increases the given date by one week (7 days)
stDate IncreaseDateByOneWeek(stDate date)
{
    date = IncreaseDateByXDays(date, 7);
    return date;
}

// Increases the given date by a specified number of weeks
stDate IncreaseDateByXWeeks(stDate date, const short &weeksToAdd)
{
    for (int i = 0; i < weeksToAdd; i++)
        date = IncreaseDateByOneWeek(date);
    return date;
}

// Increases the given date by one month
stDate IncreaseDateByOneMonth(stDate date)
{
    if (date.month == 12)
    {
        date.month = 1;
        date.year++;
    }
    else
    {
        date.month++;
    }

    // Note: day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should be 28/2/2022

    short NumberOfDaysInCurrentMonth = getNumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NumberOfDaysInCurrentMonth)
    {
        date.day = NumberOfDaysInCurrentMonth;
    }
    return date;
}

// Increases the given date by a specified number of months
stDate IncreaseDateByXMonths(stDate date, const short &MonthsToAdd)
{
    for (int i = 0; i < MonthsToAdd; i++)
        date = IncreaseDateByOneMonth(date);
    return date;
}

// Increases the given date by one year
stDate IncreaseDateByOneYear(stDate date)
{
    date.year++;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Increases the given date by a specified number of years
stDate IncreaseDateByXYears(stDate date, const short &YearsToAdd)
{
    date.year += YearsToAdd;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Increases the given date by one decade (10 years)
stDate IncreaseDateByOneDecade(stDate date)
{
    const short Decade = 10;
    date.year += Decade;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Increases the given date by a specified number of decades
stDate IncreaseDateByXDecades(stDate date, const short &DecadesToAdd)
{
    const short totalDecades = 10 * DecadesToAdd;
    date.year += totalDecades;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Increases the given date by one century (100 years)
stDate IncreaseDateByOneCentury(stDate date)
{
    const short Century = 100;
    date.year += Century;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Increases the given date by one millennium (1000 years)
stDate IncreaseDateByOneMillennium(stDate date)
{
    const short millennium = 1000;
    date.year += millennium;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Decreases the given date by one day
stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.day == 1)
    {
        if (Date.month == 1)
        {
            Date.month = 12;
            Date.day = 31;
            --Date.year;
        }
        else
        {
            --Date.month;
            Date.day = getNumberOfDaysInAMonth(Date.month, Date.year);
        }
    }
    else
    {
        --Date.day;
    }
    return Date;
}

// Decreases the given date by a specified number of days
stDate DecreaseDateByXDays(stDate date, const short &numberOfDays)
{
    for (int i = 0; i < numberOfDays; i++)
        date = DecreaseDateByOneDay(date);
    return date;
}

// Decreases the given date by one week (7 days)
stDate DecreaseDateByOneWeek(stDate date)
{
    date = DecreaseDateByXDays(date, 7);
    return date;
}

// Decreases the given date by a specified number of weeks
stDate DecreaseDateByXWeeks(stDate date, const short &numberOfWeeks)
{
    for (int i = 0; i < numberOfWeeks; i++)
        date = DecreaseDateByOneWeek(date);
    return date;
}

// Decreases the given date by one month
stDate DecreaseDateByOneMonth(stDate date)
{
    if (date.month == 1)
    {
        date.month = 12;
        date.year--;
    }
    else
    {
        date.month--;
    }

    // Note: day in date should not exceed max days in the current month
    // example if date is 31/3/2022 Decreasing one month should not be 31 / 2 / 2022, it should be 28/2/2022

    short NumberOfDaysInCurrentMonth = getNumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NumberOfDaysInCurrentMonth)
    {
        date.day = NumberOfDaysInCurrentMonth;
    }
    return date;
}

// Decreases the given date by a specified number of months
stDate DecreaseDateByXMonths(stDate date, const short &numberOfMonths)
{
    for (int i = 0; i < numberOfMonths; i++)
        date = DecreaseDateByOneMonth(date);
    return date;
}

// Decreases the given date by one year
stDate DecreaseDateByOneYear(stDate date)
{
    date.year--;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day =  getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Decreases the given date by a specified number of years
stDate DecreaseDateByXYears(stDate date, const short &numberOfYears)
{
    date.year -= numberOfYears;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Decreases the given date by one decade (10 years)
stDate DecreaseDateByOneDecade(stDate date)
{
    const short Decade = 10;
    date.year -= Decade;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Decreases the given date by a specified number of decades
stDate DecreaseDateByXDecades(stDate date, const short &numberOfDecades)
{
    const short totalDecades = 10 * numberOfDecades;
    date.year -= totalDecades;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Decreases the given date by one century (100 years)
stDate DecreaseDateByOneCentury(stDate date)
{
    const short Century = 100;
    date.year -= Century;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Decreases the given date by one millennium (1000 years)
stDate DecreaseDateByOneMillennium(stDate date)
{
    const short millennium = 1000;
    date.year -= millennium;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

// Function to calculate the difference in days between two dates
int getDifferenceBetween2Dates(stDate date1, stDate date2, bool includeEndDay)
{
    int differenceInDays = 0;
    short SwapFlagValue = 1;
    if (!IsDate1BeforeDate2(date1, date2))
    {
        // Swap Dates
        swapDates(date1, date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(date1, date2))
    {
        differenceInDays++;
        date1 = IncreaseDateByOneDay(date1);
    }
    return includeEndDay ? (++differenceInDays * SwapFlagValue) : (differenceInDays * SwapFlagValue);
}

// Function to calculate the difference in days between two dates
int differenceBetween2Dates(stDate date1, stDate date2, bool includeEndDay)
{
    int differenceInDays = 0;
    
    short SwapFlagValue = 1;
    if (!IsDate1BeforeDate2(date1, date2))
    {
        // Swap Dates
        swapDates(date1, date2);
        SwapFlagValue = -1;
    }

    // Check if date1 is before date2
    if (IsDate1BeforeDate2(date1, date2))
    {
        // Check if date1 and date2 have the same year
        if (date1.year == date2.year)
        {
            differenceInDays = getNumberOfDaysFromTheBeginningOfYear(date2) - getNumberOfDaysFromTheBeginningOfYear(date1);
        }

        else
        {
            // Calculate the remaining days in year2 by subtracting the days passed from the beginning of year2
            int remainingDaysInYear2 = NumberOfDaysInAYear(date2.year) - getNumberOfDaysFromTheBeginningOfYear(date2);

            // Calculate the difference in days by iterating over each year between date1 and date2
            for (short year = date1.year; year <= date2.year; year++)
            {
                differenceInDays += NumberOfDaysInAYear(year);
            }

            // Subtract the remaining days in year2 and the days from the beginning of date1's year
            differenceInDays -= remainingDaysInYear2 + getNumberOfDaysFromTheBeginningOfYear(date1);
        }
        
    }
    return includeEndDay ? (++differenceInDays * SwapFlagValue) : (differenceInDays * SwapFlagValue);
}

// Swaps the values of two stDate variables.
void swapDates(stDate &date1, stDate &date2)
{
    stDate temp = date1;
    date1 = date2;
    date2 = temp;
}

// Swaps the values of two stPeriod variables.
void swapPeriods(stPeriod &Period1, stPeriod &Period2)
{
    stPeriod temp = Period1;
    Period1 = Period2;
    Period2 = temp;
}

// This function calculates the length of a period in days.
int PeriodLengthInDays(const stPeriod &Period, bool IncludeEndDate)
{
    return differenceBetween2Dates(Period.StartDate, Period.EndDate, IncludeEndDate);
}

// This function checks if a given date falls within a specified period
bool isDateInPeriod(const stDate &Date, const stPeriod &Period)
{
    return !(compDates(Date, Period.StartDate) == enDateCompare::Before || compDates(Date, Period.EndDate) == enDateCompare::After);
}

// Calculates the number of vacation days between the given start and end dates.
// Excludes weekends and non-business days from the count.
short calculateVacationDays(stDate dateFrom, const stDate &dateTo)
{
    if( ! IsDate1BeforeDate2(dateFrom, dateTo)) return 0;

    short DaysCount = 0;
    while (IsDate1BeforeDate2(dateFrom, dateTo))
    {
        if (IsBusinessDay(dateFrom))
            DaysCount++;
        dateFrom = IncreaseDateByOneDay(dateFrom);
    }

    // Add 1 to the count because the loop ends when VacationStarts is equal to VacationEnds
    return DaysCount + 1 ;
}


// Calculates the return date from a vacation based on the given start date and number of vacation days.
// Skips weekends and non-business days while determining the return date.
stDate calculateVacationReturnDate(const stDate &VacationStartsDate, const short &VacationDays)
{
    stDate returnDate = VacationStartsDate;
    int businessDaysCount = 0;

    //in case the data  is weekend keep adding one day until you reach business day
    //we get rid of all weekends before the first business day
    while (IsWeekEnd(returnDate))
    {
        returnDate = IncreaseDateByOneDay(returnDate);
    }

    while (businessDaysCount < VacationDays)
    {
        returnDate = IncreaseDateByOneDay(returnDate);
        if (IsBusinessDay(returnDate))
            businessDaysCount++;
    }
    return returnDate;
}

// Validates a given date by checking if the day, month, and year components are within valid ranges.
// Returns true if the date is valid, false otherwise.
bool isValidDate(const stDate &date)
{
    bool isDayValid = (date.day <= getNumberOfDaysInAMonth(date.month, date.year) && date.day > 0);
    // Ensure the day is less than or equal to the number of days in the given month and year,
    // and greater than 0 to eliminate negative or zero values.

    bool isMonthValid = (date.month <= 12 && date.month > 0);
    // Ensure the month is within the range of valid months, from 1 to 12.

    bool isYearValid = (date.year >= 1);
    // Ensure the year is greater than or equal to 1.

    // Return the overall result of the date validation
    return isDayValid && isMonthValid && isYearValid;
}

// Function to get the current system date
stDate getCurrentDate()
{
    time_t currentTime = time(0);
    tm* now = localtime(&currentTime);
    stDate currentDate;

    currentDate.day = now->tm_mday;
    currentDate.month = now->tm_mon + 1;
    currentDate.year = now->tm_year + 1900;

    return currentDate;
}


// This function splits a string into words using a delimiter
std::vector<std::string> splitString(const std::string& str, const std::string& delimiter = " ")
{
    std::vector<std::string> words;
    std::string currentWord;

    // Iterate through the string to extract and add each word to the vector
    size_t delimiterPos = 0;
    std::string remainingStr = str; // Store the remaining string for manipulation
    while ((delimiterPos = remainingStr.find(delimiter)) != std::string::npos)
    {
        currentWord = remainingStr.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            words.push_back(currentWord);
        }
        remainingStr.erase(0, delimiterPos + delimiter.length());
    }

    // Add the last word if it exists
    if (!remainingStr.empty())
    {
        words.push_back(remainingStr);
    }

    return words;
}

// Removes spaces from a string
std::string removeSpaces(const std::string &str)
{
    std::string result;
    
    for (char ch : str)
    {
        if (ch != ' ')
        {
            result += ch;
        }
    }
    
    return result;
}

// Converts a data structure to a string in the format (dd-mm-yyyy).
std::string dateToString(const stDate &Date)
{
    return std::to_string(Date.day) + "-" + std::to_string(Date.month) + "-" + std::to_string(Date.year);
}

// Converts a string of a date in the format (dd-mm-yyyy). to a date structure
stDate stringToDate(const std::string &dateString)
{
    stDate date;
    std::vector<std::string> vDate;

    vDate = splitString(dateString, "-");

    if(vDate.size() != 3)
        return {0, 0, 0};
    
    for(std::string element : vDate)
    {
        for(char ch : element)
        {
            if(!isdigit(ch)) return {0,0,0};
        }
    }

    date.day = std::stoi(vDate[0]);
    date.month = std::stoi(vDate[1]);
    date.year = std::stoi(vDate[2]);
    return date;
}

// Reads a string of a date from the user, removes leading/trailing spaces, and returns the cleaned string
std::string readStringDate(const std::string &message = "")
{
    std::string dateString;
    std::cout << message;
    std::getline(std::cin >> std::ws, dateString);
    dateString = removeSpaces(dateString);
    return dateString;
}

// Reads a full date from the user in the format (dd-mm-yyyy).
// Validates the input and returns a stDate structure representing the entered date.
stDate readDate(const std::string &message)
{
    stDate date = {0, 0, 0};
    std::string dateString = readStringDate(message);
    date = stringToDate(dateString);

    while(!isValidDate(date))
    {
        std::cout << "Invalid date. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        std::string dateString = readStringDate();
        date = stringToDate(dateString);
    }
    return date;
}

// Replaces all occurrences of a word in a string with a specified replacement.
// Returns the modified string.
std::string replaceWordInString(const std::string &input, const std::string &wordToReplace, const std::string &replacement)
{
    std::string result = input;
    size_t pos = 0;
    while ((pos = result.find(wordToReplace, pos)) != std::string::npos)
    {
        result.replace(pos, wordToReplace.length(), replacement);
        pos += replacement.length(); // Move past the replaced word
    }
    return result;
}

// Formats a date structure according to the provided date format.
// Returns a string representing the formatted date.
std::string formateDate(const stDate &date, const std::string &dateFormat)
{
    std::string formattedDateString = "";
    formattedDateString = replaceWordInString(dateFormat, "dd", std::to_string(date.day));
    formattedDateString = replaceWordInString(formattedDateString, "mm", std::to_string(date.month));
    formattedDateString = replaceWordInString(formattedDateString, "yyyy", std::to_string(date.year));
    return formattedDateString;
}

// Reads a date from the user by separately requesting the day, month, and year.
// Returns a stDate structure representing the entered date.
stDate readDateOldVersion()
{
    stDate date;
    std::cout << "Please enter a Day: ";
    std::cin >> date.day;
    std::cout << "Please enter a Month: ";
    std::cin >> date.month;
    std::cout << "Please enter a Year: ";
    std::cin >> date.year;

    return date;
    // Note: You must verify that the user's input is correct.
    // For example, ensure the user does not enter a day less than 1 or greater than 31,
    // and that the user does not enter a month less than 1 or greater than 12.
}

// Reads a period (start date and end date) from the user.
// Utilizes the readFullDate() function to read the individual dates.
// Returns a stPeriod structure containing the entered start and end dates.
stPeriod ReadPeriod()
{
    stPeriod Period;
    std::cout << "\nEnter Start Date:\n";
    Period.StartDate = readDate();
    std::cout << "\nEnter End Date:\n";
    Period.EndDate = readDate();
    return Period;
}


/*

// Reads a full date from the user in the format (dd-mm-yyyy).
// Validates the input and returns a stDate structure representing the entered date.
stDate readFullDate()
{
    stDate date;
    std::string inputDate;

    // Get the input from the user
    std::cout << "Please enter a date in the format (dd-mm-yyyy): ";
    std::getline(std::cin, inputDate);

    // Remove any non-digit characters from the input
    inputDate.erase(std::remove_if(inputDate.begin(), inputDate.end(), [](char c) { return !std::isdigit(c); }), inputDate.end());

    // Validate the input length
    if (inputDate.length() != 8)
    {
        std::cout << "Invalid date format. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        return readFullDate();
    }

    // Extract day, month, and year from the input string
    try {
        date.day = std::stoi(inputDate.substr(0, 2));
        date.month = std::stoi(inputDate.substr(2, 2));
        date.year = std::stoi(inputDate.substr(4, 4));
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid date format. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        return readFullDate();
    }

    // Validate the entered date
    if (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1 || date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        std::cout << "Invalid date. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        return readFullDate();
    }

    return date;
}

*/

