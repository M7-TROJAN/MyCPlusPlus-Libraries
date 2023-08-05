# Get Inputs Library

The `get_inputs` library provides convenient functions to read various types of input from the user while performing input validation. It includes functions to read integers, floats, doubles, strings, characters, PIN codes, phone numbers, and long long integers, ensuring the input is valid and meeting specific criteria.

## Functions

### `int ReadPositiveNumber(const std::string &message = "")`

Reads a positive integer from the user.

- `message` (optional): Custom message to display before input.

### `int getInputInRange(const int& from, const int& to, const std::string& message = "")`

Reads an integer value from the user within a specified range.

- `from`: The lower bound of the range.
- `to`: The upper bound of the range.
- `message` (optional): Custom message to display before input.

### `int readNumber_From_To(int from, int to, std::string message = "")`

Reads an integer value from the user within a specified range.

- `from`: The lower bound of the range.
- `to`: The upper bound of the range.
- `message` (optional): Custom message to display before input.

### `int ReadNumber()`

Reads an integer from the user.

### `int get_int(const std::string &message = "")`

Reads an integer from the user.

- `message` (optional): Custom message to display before input.

### `float get_float(std::string message = "")`

Reads a float from the user.

- `message` (optional): Custom message to display before input.

### `double get_double(std::string message = "")`

Reads a double from the user.

- `message` (optional): Custom message to display before input.

### `std::string get_string(std::string message = "")`

Reads a string from the user.

- `message` (optional): Custom message to display before input.

### `char get_char(std::string message = "")`

Reads a single character from the user.

- `message` (optional): Custom message to display before input.

### `std::string readPinCode(const std::string& message = "Please enter Pin Code: ")`

Reads a PIN code from the user.

- `message` (optional): Custom message to display before input.

### `std::string readPhoneNumber(const std::string& message = "Please enter phone number: ")`

Reads a phone number from the user.

- `message` (optional): Custom message to display before input.

### `long long GetLongLongInt(const std::string& message = "Please enter phone number: ")`

Reads a long long integer from the user.

- `message` (optional): Custom message to display before input.

## Usage

1. Include the `getinputs.h` header in your C++ program:

```cpp
#include "getinputs.h"

1. Call the desired functions to read input from the user.
int main() {
    int positiveNumber = ReadPositiveNumber("Enter a positive integer: ");
    float floatValue = get_float("Enter a float value: ");
    std::string name = get_string("Enter your name: ");
    char option = get_char("Enter an option (A/B/C): ");

    // ... More input reading and processing
}
```

Feel free to modify and adapt the library's functions according to your needs. The `get_inputs` library provides a straightforward way to handle user input and ensure the input's validity.

For more information and examples, refer to the provided functions and usage in the library's source files.

Created by [Mahmoud Mohamed]
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)