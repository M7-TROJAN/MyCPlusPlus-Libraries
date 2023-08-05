#include "mathematic.h"

// This function takes an integer number and reverses its digits.
int ReverseNumber(int Number)
{
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
    /* The Above loop extracts the last digit of the number and adds it to Number2,
    which is the reversed number. Then it removes the last digit from Number
    and repeats until all digits have been reversed. */
}

// Function to generate a random number
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// This function returns the absolute value of a float number.
float absolute(float num)
{
    if (num == 0)
        return 0;
    else if(num < 0)
        return -1 * num;
    else
        return num;

    // return num == 0? 0 : num < 0? -1 * num : num;
}

// This function returns the absolute value of a float number (alternative implementation).
float MyABS(float num)
{
    if (num == 0) {
        return 0;
    } else if (num < 0) {
        return -num;
    } else {
        return num;
    }

    // return num == 0? 0 : num < 0? -num : num;
}

// This function takes a double number as an argument and rounds it to the nearest integer.
int roundNumber(double num)
{
    /*
    steps:
        1. Add 0.5 to the number.
        2. Cast the result to an integer, which will truncate the decimal part of the number and leave only the integer part.
        3. If the original number was negative, subtract 1 from the rounded value.
    */
    int rounded = (int)(num + 0.5); // Add 0.5 to the number and cast to int
    if (num < 0)
        rounded--; // Subtract 1 if the original number was negative
    return rounded;
}

// This function takes a double number as an argument and rounds it up to the nearest integer.
int ceilNumber(double num)
{
    double fractionalPart = num - int(num); // FractionsPart means => (الجزء العشري) الكسور 

    if(fractionalPart <= 0)
        return (int)num;
    else
        return (int)num + 1;
    
    // return (fractionalPart <= 0) ? (int)num : (int)num + 1;
}

// This function calculates the sum of digits of a given number
int SumOfDigits(int Number)
{
    int Sum = 0, Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Sum = Sum + Remainder;
    }
    return Sum;
}

/*  
    This function takes two arguments, an integer Number and a short integer DigitToCheck.
    It counts the frequency of DigitToCheck in Number by repeatedly 
*/
int CountDigitFrequency(int Number, short DigitToCheck)
{
    int FreqCount = 0, Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        if (DigitToCheck == Remainder)
        {
            FreqCount++;
        }
    }
    return FreqCount;
}

// This function takes an integer number and print its digits.
void PrintDigits(int number)
{
    number = ReverseNumber(number);
    int Remainder = 0;
    while (number > 0)
    {
        Remainder = number % 10;
        number = number / 10;
        std::cout << Remainder << std::endl;
    }
}

// This function checks if the number is a palindrome or not
bool isPalindromeNumber(int number)
{
    int reversedNumber = 0, remainder = 0, temp = number;
    while (temp > 0)
    {
        remainder = temp % 10;
        temp /= 10;
        reversedNumber = reversedNumber * 10 + remainder;
    }

    // Check if the number is equal to its reversed form
    if (number == reversedNumber) return true;

    return false;
}

// Function to print a number pattern
// Prints a pattern of numbers from 1 up to the input Number
void PrintNumberPattern(int Number)
{
    std::cout << "=========================\n";
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

// Function to print an inverted number pattern
// Prints a pattern of numbers in descending order based on the input Number
void PrintInvertedNumberPattern(int Number)
{
    std::cout << "=========================\n";
    for (int i = Number; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

// Function to calculate the square root of a number
// Returns the square root of the input num
// If the number is negative, returns -1
double square_root(double num) {
    if (num < 0) {
        return -1;
    }
    return pow(num, 0.5);
}

// Function to check if a number is prime
// A prime number is a number greater than 1 that is divisible only by 1 and itself.
// In other words, it is a number that has no positive divisors other than 1 and itself.
bool isPrimeNumber(int number)
{
    if (number <= 1) // 0 and 1 are not prime numbers
        return false;

    // Loop from 2 to number - 1
    for(int i = 2; i < number; i++)
        if(number % i == 0) return false; // If number is divisible by i, it's not prime

    return true; // If no divisors found, number is prime
}

// Function to check if a number is prime
// A prime number is a number greater than 1 that is divisible only by 1 and itself.
bool isPrimeNumber_faster(long long number)
{
    if (number <= 1) // 0 and 1 are not prime numbers
        return false;

    // Create a vector of boolean values to mark prime and non-prime numbers
    std::vector<bool> sieve(number + 1, true); // sieve → غربال

    for (int i = 2; i * i <= number; i++)
    {
        if (sieve[i])
        {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= number; j += i)
                sieve[j] = false;
        }
    }

    return sieve[number]; // Return the result for the given number
}

// Function to check if a number is prime
// A prime number is a number greater than 1 that is divisible only by 1 and itself.
bool isPrimeNumberFaster(long long n)
{
    if (n <= 1) // 0 and 1 are not prime numbers
        return false;

    int sqrtN = n / 2; // Calculate the square root of n

    // Iterate from 2 up to the square root of n to check for divisors
    for (int i = 2; i <= sqrtN; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;

    // The reason for iterating from 2 up to the square root of n (sqrtN) instead of iterating up to n - 1 is based on a mathematical property of prime numbers.
    // When checking for the primality of a number n, we only need to consider divisors up to the square root of n. If n is not a prime number, it can be factored into two numbers a and b such that n = a * b.
    // If both a and b are greater than the square root of n, their product a * b would be greater than n, which contradicts the assumption that n = a * b.
    // So, if there are no divisors smaller than or equal to the square root of n, then there will be no divisors greater than the square root of n either. Therefore, by iterating up to the square root of n, we can efficiently check for divisors and determine if n is a prime number or not.
    // This optimization significantly reduces the number of iterations needed to determine primality, making the algorithm more efficient, especially for larger numbers.
}

// Returns the number of unique elements in the array a with the provided length
int count_unique(int a[], int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        bool match_found = false;
        for (int j = 0; j < length; j++)
        {
            if (a[i] == a[j] && i != j)
                match_found = true;
        }
        if (!match_found)
            count++;
    }
    return count;
}

// Returns the number of unique elements in the vector
int count_unique(std::vector<int>a)
{
    int count = 0;
    int length = a.size();

    for (int i = 0; i < length; i++)
    {
        bool match_found = false;
        for (int j = 0; j < length; j++)
        {
            if (a[i] == a[j] && i != j)
                match_found = true;
        }
        if (!match_found)
            count++;
    }
    return count;
}

// Returns the number of unique elements in the vector
int count_unique(std::vector<std::string>a)
{
    int count = 0;
    int length = a.size();

    for (int i = 0; i < length; i++)
    {
        bool match_found = false;
        for (int j = 0; j < length; j++)
        {
            if (a[i] == a[j] && i != j)
                match_found = true;
        }
        if (!match_found)
            count++;
    }
    return count;
}