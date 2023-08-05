Library Name: date
------------------

Author: Mahmoud Mohamed
Email : mahmoud.abdalaziz@outlook.com
linkedin: https://www.linkedin.com/in/mahmoud-mohamed-abd/
-------------------------------------

Description:
------------
The date library provides functions for working with dates in C++. It defines a struct `stDate` to represent a date with day, month, and year components. The library includes more than 70 functions, for example:

1. `getNumberOfDaysFromTheBeginningOfYear`: Calculates the number of days from the beginning of the year until the specified date.
2. `compareDates`: Compares two dates and returns an integer value based on the comparison.
3. 'getNumberOfDaysInAMonth': Returns the number of days in a specific month of a year.
4. 'dateAddDays' : Adds the specified number of days to a given date.
5. 'IsOverlapPeriods' : to check if two periods overlap.
6. 'GetDateFromDayOrderInYear' : Returns the date corresponding to the given day order within a year.
7. 'IncreaseDateByXDays' : Increases the given date by a specified number of days.

Usage:
------
1. Include the `date.h` header file in your C++ program.
2. Link against the `date.cpp` implementation file.
3. Use the provided functions in your code to work with dates.

Example:
--------
// Sample code to demonstrate the usage of the date library
#include "date.h"
#include <iostream>

int main()
{
    stDate date1 = readFullDate();
    stDate date2 = readFullDate();

    if (compareDates(date1, date2) == 0)
        std::cout << "The dates are equal." << std::endl;
    else if (compareDates(date1, date2) == 1)
        std::cout << "Date 1 is after Date 2." << std::endl;
    else
        std::cout << "Date 1 is before Date 2." << std::endl;

    return 0;
}

Note:
-----
Each function in the date library has a name that indicates its purpose, and there is a comment preceding each function to provide a clarification of its work.
Please refer to the comments preceding each function for detailed explanations of their respective tasks.

Feel free to modify and adapt the code to suit your needs. If you have any further questions, please let me know!
