#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <cmath>
#include <vector>
#include <random> // for random_device, mt19937, uniform_int_distribution

class util
{
    // Function to convert a number to its textual representation
    static std::string numberToText(const long long &number)
    {
        // Check if the number is zero
        if (number == 0)
        {
            return "";
        }

        // Check if the number is negative
        if (number < 0)
        {
            return "Negative " + numberToText(-number);
        }

        // Handle numbers from 1 to 19
        if (number >= 1 && number <= 19)
        {
            std::string unitsText[] =
                {
                    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            return unitsText[number] + " ";
        }

        // Handle numbers from 20 to 99
        if (number >= 20 && number <= 99)
        {
            std::string tensText[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            return tensText[number / 10] + " " + numberToText(number % 10);
        }

        // Handle numbers from 100 to 999
        if (number >= 100 && number <= 999)
        {
            return numberToText(number / 100) + "Hundred " + numberToText(number % 100);
        }

        // Handle numbers from 1000 to 1999
        if (number >= 1000 && number <= 1999)
        {
            return "One Thousand " + numberToText(number % 1000);
        }
        // Handle numbers from 2000 to 999,999
        if (number >= 2000 && number <= 999999)
        {
            return numberToText(number / 1000) + "Thousands " + numberToText(number % 1000);
        }

        // Handle numbers from 1,000,000 to 1,999,999
        if (number >= 1000000 && number <= 1999999)
        {
            return "One Million " + numberToText(number % 1000000);
        }
        // Handle numbers from 2,000,000 to 999,999,999
        if (number >= 2000000 && number <= 999999999)
        {
            return numberToText(number / 1000000) + "Millions " + numberToText(number % 1000000);
        }

        // Handle numbers from 1,000,000,000 to 1,999,999,999
        if (number >= 1000000000 && number <= 1999999999)
        {
            return "One Billion " + numberToText(number % 1000000000);
        }
        // Handle numbers from 2,000,000,000 to 999,999,999,999
        if (number >= 2000000000 && number <= 999999999999)
        {
            return numberToText(number / 1000000000) + "Billions " + numberToText(number % 1000000000);
        }

        // Handle numbers from 1,000,000,000,000 to 1,999,999,999,999  "I Can't Read these Numbers :")😂"
        if (number >= 1000000000000 && number <= 1999999999999)
        {
            return "One Trillion " + numberToText(number % 1000000000000);
        }
        else
        {
            return numberToText(number / 1000000000000) + "Trillions " + numberToText(number % 1000000000000);
        }
    }

    // Function to convert a number to its textual representation
    static std::string toText(const long long &number)
    {
        std::string text = numberToText(number);
        if (text.empty())
            return "Zero";
        return text;
    }

public:
    // Determines if the given year is a leap year
    static bool isLeapYear(const short &Year)
    {
        // Leap year if year is divisible by 4 AND not divisible by 100 OR if it's divisible by 400
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    // Returns the number of days in a year
    static short numberOfDaysInAYear(const short &Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    // This function takes a string and an encryption key and returns the encrypted string.
    static std::string encryptText(std::string Text, short EncryptionKey)
    {
        // Iterate over each character in the string and add the encryption key to its ASCII code.
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    // This function takes a string and an encryption key and returns the decrypted string.
    static std::string decryptText(std::string Text, short EncryptionKey)
    {
        // Iterate over each character in the string and subtract the encryption key from its ASCII code.
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    static std::string convertNumberToText(long double number)
    {
        std::string numberString = toText(long(number));
        int fractionalPart = static_cast<int>(round((number - int(number)) * 100));
        if (fractionalPart > 0)
            numberString += "and " + toText(fractionalPart) + "cent.";

        return numberString;
    }

    // Function to generate a random number
    static int randomNumber(int From, int To)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(From, To);
        return distribution(gen);
    }

    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MIX = 4
    };
    static char getRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(randomNumber(97, 122));
            break;
        case enCharType::CapitalLetter:
            return char(randomNumber(65, 90));
            break;
        case enCharType::Digit:
            return char(randomNumber(48, 57));
            break;
        default: // enCharType::MIX
            return getRandomCharacter(enCharType(randomNumber(1, 3)));
            break;
        }
    }

    static std::string getRandomWord(const enCharType &CharType, const int &length)
    {
        std::string word = "";
        for (int i = 0; i < length; i++)
        {
            word += getRandomCharacter(CharType);
        }
        return word;
    }

    // Function to generate a strong password
    static std::string generatePassword(const int PASSWORD_LENGTH = 16)
    {
        if (PASSWORD_LENGTH < 1)
            return "";
        const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+=";
        std::random_device rd;                                           // creates a random_device object to obtain a seed for the random number generator
        std::mt19937 gen(rd());                                          // creates a mersenne_twister_engine seeded with the random_device object
        std::uniform_int_distribution<> dis(0, CHARACTERS.length() - 1); // creates a uniform integer distribution object for generating random numbers between 0 and the length of the character set - 1

        std::string password = "";
        for (int i = 0; i < PASSWORD_LENGTH; i++)
        {
            password += CHARACTERS[dis(gen)]; // generate a random character from the character set
        }

        return password;
    }

    // Function to generate a very strong key with four groups of 4 random letters separated by hyphens
    static std::string generateKey()
    {
        const int PASSWORD_LENGTH = 16;
        const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::random_device rd;                                           // creates a random_device object to obtain a seed for the random number generator
        std::mt19937 gen(rd());                                          // creates a mersenne_twister_engine seeded with the random_device object
        std::uniform_int_distribution<> dis(0, CHARACTERS.length() - 1); // creates a uniform integer distribution object for generating random numbers between 0 and the length of the character set - 1

        std::string password = "";
        for (int i = 0; i < PASSWORD_LENGTH; i++)
        {
            if (i % 4 == 0 && i > 0)
            {
                password += '-';
            }
            password += CHARACTERS[dis(gen)]; // generate a random character from the character set
        }

        return password;
    }

    static bool isPalindromeArray(int arr[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] != arr[length - i - 1])
                return false;
        }
        return true;
    }

    static bool isPalindromeArray(double arr[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] != arr[length - i - 1])
                return false;
        }
        return true;
    }

    static bool isPalindromeArray(std::string arr[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] != arr[length - i - 1])
                return false;
        }
        return true;
    }

    static bool isPalindromeArray(std::vector<int> vec)
    {
        int length = vec.size();
        for (int i = 0; i < length; i++)
        {
            if (vec[i] != vec[length - i - 1])
                return false;
        }
        return true;
    }

    static bool isPalindromeArray(std::vector<double> vec)
    {
        int length = vec.size();
        for (int i = 0; i < length; i++)
        {
            if (vec[i] != vec[length - i - 1])
                return false;
        }
        return true;
    }

    static bool isPalindromeArray(std::vector<std::string> vec)
    {
        int length = vec.size();
        for (int i = 0; i < length; i++)
        {
            if (vec[i] != vec[length - i - 1])
                return false;
        }
        return true;
    }

    static void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static void swap(float &a, float &b)
    {
        float temp = a;
        a = b;
        b = temp;
    }

    static void swap(std::string &a, std::string &b)
    {
        std::string temp = a;
        a = b;
        b = temp;
    }

    static void shuffleArray(int arr[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            swap(arr[randomNumber(1, length) - 1], arr[randomNumber(1, length) - 1]);
        }
    }
    static void shuffleArray(std::string arr[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            swap(arr[randomNumber(1, length) - 1], arr[randomNumber(1, length) - 1]);
        }
    }

    static void shuffleArray(std::vector<int> &vec)
    {
        int length = vec.size();
        for (int i = 0; i < length; i++)
        {
            int randomIndex1 = randomNumber(0, length - 1);
            int randomIndex2 = randomNumber(0, length - 1);
            swap(vec[randomIndex1], vec[randomIndex2]);
        }
    }

    static void shuffleArray(std::vector<std::string> &vec)
    {
        int length = vec.size();
        for (int i = 0; i < length; i++)
        {
            int randomIndex1 = randomNumber(0, length - 1);
            int randomIndex2 = randomNumber(0, length - 1);
            swap(vec[randomIndex1], vec[randomIndex2]);
        }
    }

    static void fillArrayWithRandomNumbers(int arr[], const int &length, int from = 0, int to = 100)
    {
        for (int i = 0; i < length; i++)
            arr[i] = randomNumber(from, to);
    }

    static void fillArrayWithRandomNumbers(std::vector<int> &vec, const int &length, int from = 0, int to = 100)
    {
        for (int i = 0; i < length; i++)
            vec.push_back(randomNumber(from, to));
    }
};

#endif
