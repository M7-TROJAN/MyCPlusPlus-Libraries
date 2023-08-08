
#ifndef INPUT_VALIDATE_H
#define INPUT_VALIDATE_H

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

class clsInputValidate
{
private:
    clsInputValidate() {} // Private constructor to prevent object creation
public:
    // Check if a given value is within a specified range.
    // Returns true if the value is greater than or equal to the lower bound
    // and less than or equal to the upper bound, otherwise returns false.
    static bool isInRange(int value, int lowerBound, int upperBound)
    {
        return value >= lowerBound && value <= upperBound;
    }

    // Check if a given value is within a specified range.
    static bool isInRange(float value, float lowerBound, float upperBound)
    {
        return value >= lowerBound && value <= upperBound;
    }

    // Check if a given value is within a specified range.
    static bool isInRange(long value, long lowerBound, long upperBound)
    {
        return value >= lowerBound && value <= upperBound;
    }

    // Check if a given value is within a specified range.
    static bool isInRange(double value, double lowerBound, double upperBound)
    {
        return value >= lowerBound && value <= upperBound;
    }

    // Check if a given value is within a specified range.
    static bool isInRange(char value, char lowerBound, char upperBound, bool matchCase = true)
    {
        if (matchCase)
        {
            return value >= lowerBound && value <= upperBound;
        }
        else
        {
            char lower = std::tolower(lowerBound);
            char upper = std::tolower(upperBound);
            char val = std::tolower(value);
            return val >= lower && val <= upper;
        }
    }

    // This function reads an integer from the user with an optional message and returns it
    static int get_int(const std::string &message = "")
    {
        int number = 0;
        do
        {
            // Read an integer value from the user
            std::cout << message;
            std::cin >> number;

            // Check if the input was invalid (i.e. not an integer)
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // cout << "Invalid input. Please enter a valid integer.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } while (true);
        return number;
    }

    // This function reads a float from the user with an optional message and returns it
    static float get_float(std::string message = "")
    {
        float number = 0;
        do
        {
            // Read a float value from the user
            std::cout << message;
            std::cin >> number;

            // Check if the input was invalid (i.e. not a number)
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // cout << "Invalid input. Please enter a valid number." << endl;
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } while (true);
        return number;
    }

    // This function reads a double from the user with an optional message and returns it
    static double get_double(std::string message = "")
    {
        double number = 0;
        do
        {
            // Read a double value from the user
            std::cout << message;
            std::cin >> number;

            // Check if the input was invalid (i.e. not an number)
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // cout << "Invalid input. Please enter a valid number." << endl;
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } while (true);
        return number;
    }

    // This function reads a long integer from the user with an optional message and returns it
    static long get_Long(const std::string &message = "")
    {
        long number = 0;
        do
        {
            std::cout << message;
            std::cin >> number;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } while (true);
        return number;
    }

    // This function reads a long long integer from the user with an optional message and returns it
    static long long getLongLongInt(const std::string &message = "")
    {
        long long number = 0;
        do
        {
            std::cout << message;
            std::cin >> number;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } while (true);
        return number;
    }

    // This function reads a string from the user with an optional message and returns it
    static std::string get_string(std::string message = "")
    {
        std::string text = "";
        do
        {
            std::cout << message;
            std::cin >> text;

            // Check if the input was invalid
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            break;
        } while (true);
        return text;
    }

    // This function reads a single character from the user with an optional message and returns it
    static char get_char(std::string message = "")
    {
        char letter = ' ';
        std::cout << message;
        std::cin >> letter;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return letter;
    }

    // Reads an integer value from the user between the given range and returns it
    static int getInputInRange(const int &from, const int &to, const std::string &message = "")
    {
        float number = 0;
        do
        {
            // Read an integer value from the user
            std::cout << message;
            std::cin >> number;

            // Check if the input was invalid (i.e. not an integer)
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer between " << from << " to " << to << std::endl;
                continue;
            }
            if (number < from || number > to)
            {
                std::cout << "Please enter a number between " << from << " to " << to << std::endl;
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } while (true);
        return number;
    }

    // This function reads a PIN code from the user with an optional message and returns it as a string
    static std::string readPinCode(const std::string &message = "Please enter Pin Code: ")
    {
        std::string pinCode;

        while (true)
        {
            std::cout << message;
            std::cin >> pinCode;

            // Check if the input was invalid
            if (std::cin.fail() || pinCode.length() != 4 || !std::all_of(pinCode.begin(), pinCode.end(), isdigit))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid input! Pin Code should be a 4-digit numeric value." << std::endl;
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        return pinCode;
    }

    // This function reads a Phone Number code from the user with an optional message and returns it as a string
    static std::string readPhoneNumber(const std::string &message = "Please enter phone number: ")
    {
        std::string phoneNumber;

        while (true)
        {
            std::cout << message;
            std::cin >> phoneNumber;

            if (std::cin.fail() || phoneNumber.length() != 11 || !std::all_of(phoneNumber.begin(), phoneNumber.end(), isdigit))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid input! Phone number should be a 11-digit numeric value." << std::endl;
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        return phoneNumber;
    }
};

#endif // INPUT_VALIDATE_H