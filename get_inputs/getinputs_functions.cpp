#include "getinputs.h"

// This function reads a positive integer from the user and returns it
int ReadPositiveNumber(const std::string &message = "")
{
    int number = 0;
    do
    {
        // Display a message to the user asking for a positive integer
        std::cout << message << std::endl;

        // Read an integer value from the user
        std::cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (std::cin.fail())
        {
            std::cin.clear();             // Clear the error flag
            std::cin.ignore(100000, '\n'); // Ignore any remaining characters in the input buffer
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        // Check if the input was negative or zero
        else if (number <= 0)
        {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    } while (number <= 0);

    // Return the valid positive integer value entered by the user
    return number;
}

// Reads an integer value from the user between the given range and returns it
int getInputInRange(const int& from, const int& to, const std::string& message = "")
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

// Reads an integer value from the user between the given range and returns it
int readNumber_From_To(int from, int to, std::string message = "")
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

// This function reads a positive integer from the user and returns it
int ReadNumber()
{
    int number = 0;
    do
    {
        // Read an integer value from the user
        std::cout << "Enter a number:\n";
        std::cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            continue;
        }
        break;
    } while (true);
    return number;
}

// This function reads an integer from the user with an optional message and returns it
int get_int(const std::string &message = "")
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
float get_float(std::string message = "")
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
double get_double(std::string message = "")
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

// This function reads a string from the user with an optional message and returns it
std::string get_string(std::string message = "")
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
char get_char(std::string message = "")
{
    char letter = ' ';
    std::cout << message;
    std::cin >> letter;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return letter;
}

// This function reads a PIN code from the user with an optional message and returns it as a string
std::string readPinCode(const std::string& message = "Please enter Pin Code: ")
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
std::string readPhoneNumber(const std::string& message = "Please enter phone number: ")
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

// This function reads a long long integer from the user with an optional message and returns it
long long GetLongLongInt(const std::string& message = "Please enter phone number: ")
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
