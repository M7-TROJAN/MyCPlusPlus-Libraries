# Util Library

`util` is a C++ utility library that provides various useful functions for working with numbers, text, encryption, randomization, and more. It aims to simplify common tasks and provide easy-to-use functions to enhance your C++ projects.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Installation

To use the `util` library in your C++ project, follow these steps:

1. Clone or download this repository to your local machine.

2. Copy the `util.h` file from the repository and add it to your project's source directory.

3. Include the `util.h` file in your C++ source files where you want to use the utility functions:

```cpp
   #include "util.h"
```

## Usage

The `util` library provides a range of utility functions that you can use in your C++ projects. Here are some examples of what you can do:

- Convert numbers to their textual representation.
- Check if a year is a leap year.
- Encrypt and decrypt text.
- Generate random numbers and characters.
- Generate strong passwords and keys.
- Check if arrays or vectors are palindromes.
- Shuffle arrays and vectors.
- For detailed usage instructions and examples, refer to the Examples section.

## Features

- Conversion of numbers to text representation.
- Leap year checking.
- Text encryption and decryption.
- Random number and character generation.
- Strong password and key generation.
- Array and vector palindrome checking.
- Array and vector shuffling.

## Examples

Converting Numbers to Text

```cpp
long long number = 12345;
std::string text = util::convertNumberToText(number);
std::cout << text << std::endl; // "Twelve Thousand Three Hundred Forty-Five"
```

Generating a Strong Password
```cpp
std::string password = util::generatePassword(12); // Generates a 12-character password
std::cout << "Generated Password: " << password << std::endl;
```

Checking for Palindromes
```cpp
int intArray[] = {1, 2, 3, 2, 1};
bool isPalindrome = util::isPalindromeArray(intArray, sizeof(intArray) / sizeof(int));
if (isPalindrome)
    std::cout << "The array is a palindrome." << std::endl;
else
    std::cout << "The array is not a palindrome." << std::endl;
```

## Author

If you find any issues or have suggestions for improvements, feel free to contact me 🫶❤️.
Mahmoud Mohamed
Email: mahmoud.abdalaziz@outlook.com
LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.