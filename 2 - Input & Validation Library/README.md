# Input Validation Library

`clsInputValidate` is a C++ input validation library that provides functions to validate and read various types of input from the user while ensuring the input is within specified ranges or conforms to specific patterns. It aims to simplify input validation and enhance the user experience in your C++ projects.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Functions](#functions)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The `clsInputValidate` library offers a set of functions to validate and read different types of input, such as integers, floats, doubles, long integers, characters, PIN codes, and phone numbers. It ensures that the entered input meets the required criteria, such as being within specified ranges or adhering to specific patterns.

## Installation

To use the `clsInputValidate` library in your C++ project, follow these steps:

1. Clone or download this repository to your local machine.

2. Copy the `InputValidate.h` file from the repository and add it to your project's source directory.

3. Include the `InputValidate.h` file in your C++ source files where you want to use the input validation functions:

```cpp
   #include "InputValidate.h"
```
## Usage

The `clsInputValidate` library provides a variety of functions to validate and read different types of input. Here are some examples of what you can do:

- Validate if an integer is within a specified range.
- Validate if a float is within a specified range.
- Validate if a double is within a specified range.
- Validate if a character is within a specified range (with optional case-sensitivity).
- Read an integer from the user with optional validation and error handling.
- Read a float from the user with optional validation and error handling.
- Read a double from the user with optional validation and error handling.
- Read a long integer from the user with optional validation and error handling.
- Read a long long integer from the user with optional validation and error handling.
- Read a string from the user with optional validation and error handling.
- Read a single character from the user with optional validation and error handling.
- Read a PIN code from the user with validation for a 4-digit numeric value.
- Read a phone number from the user with validation for an 11-digit numeric value.

For detailed usage instructions and examples, refer to the Examples section.


## Functions
The `clsInputValidate` library includes the following key functions:

- `isInRange` functions for integers, floats, long integers, and doubles to check if a value is within a specified range.
- `isInRange` function for characters to check if a character is within a specified range (with optional case-sensitivity).
- Functions to read various types of input from the user with optional validation and error handling.
- `readPinCode` function to read a 4-digit numeric PIN code from the user.
- `readPhoneNumber` function to read an 11-digit numeric phone number from the user.
For a complete list of functions and their usage, please refer to the source code.

## Examples
Here are some examples of how to use the clsInputValidate library:

### Example 1: Validating Age

```cpp
#include "InputValidate.h"

int main() {
    int age = clsInputValidate::getInputInRange(18, 100, "Please enter your age: ");
    std::cout << "You entered: " << age << std::endl;
    return 0;
}
```
### Example 2: Reading Temperature

```cpp
#include "InputValidate.h"

int main() {
    float temperature = clsInputValidate::get_float("Enter the temperature: ");
    std::cout << "Temperature: " << temperature << std::endl;
    return 0;
}
```

### Example 3: Reading PIN Code

```cpp
#include "InputValidate.h"

int main() {
    std::string pinCode = clsInputValidate::readPinCode();
    std::cout << "PIN Code: " << pinCode << std::endl;
    return 0;
}
```

### Example 4: Reading Phone Number

```cpp
#include "InputValidate.h"

int main() {
    std::string phoneNumber = clsInputValidate::readPhoneNumber();
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    return 0;
}
```

## Contributing
If you find any issues or have suggestions for improvements, feel free to contact me 🫶❤️.

Author: Your Name
Email: your.email@example.com
LinkedIn: Your LinkedIn Profile

License
This project is licensed under the MIT License - see the LICENSE file for details.