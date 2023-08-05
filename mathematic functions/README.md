# Mathematic Library

The `mathematic` library provides a collection of mathematical functions for various tasks, including number manipulation, digit operations, randomness, and more.

## Functions

### `int ReverseNumber(int Number)`

Reverses the digits of an integer number.

### `int RandomNumber(int From, int To)`

Generates a random integer within the specified range.

### `float absolute(float num)`

Returns the absolute value of a float number.

### `float MyABS(float num)`

An alternative implementation to return the absolute value of a float number.

### `int roundNumber(double num)`

Rounds a double number to the nearest integer.

### `int ceilNumber(double num)`

Rounds up a double number to the nearest integer.

### `int SumOfDigits(int Number)`

Calculates the sum of digits of a given number.

### `int CountDigitFrequency(int Number, short DigitToCheck)`

Counts the frequency of a specific digit in a number.

### `void PrintDigits(int number)`

Prints the digits of an integer number.

### `bool isPalindromeNumber(int number)`

Checks if a number is a palindrome.

### `void PrintNumberPattern(int Number)`

Prints a pattern of numbers from 1 up to the input number.

### `void PrintInvertedNumberPattern(int Number)`

Prints an inverted pattern of numbers in descending order.

### `double square_root(double num)`

Calculates the square root of a number.

### `bool isPrimeNumber(int number)`

Checks if a number is prime.

### `bool isPrimeNumber_faster(long long number)`

An optimized version to check if a number is prime.

### `bool isPrimeNumberFaster(long long n)`

An alternative optimized version to check if a number is prime.

### `int count_unique(int a[], int length)`

Counts the number of unique elements in an array.

### `int count_unique(std::vector<int>a)`

Counts the number of unique elements in a vector of integers.

### `int count_unique(std::vector<std::string>a)`

Counts the number of unique elements in a vector of strings.

## Usage

1. Include the `mathematic.h` header in your C++ program:

```cpp
#include "mathematic.h"

2. Include the `mathematic.h` header in your C++ program:

int main() {
    int num = 12345;
    int reversed = ReverseNumber(num);
    float absValue = absolute(-10.5);
    int rounded = roundNumber(10.7);
    
    // ... More mathematical operations
}
```
Feel free to modify and adapt the library's functions according to your needs. The `mathematic` library provides useful mathematical utilities to simplify your code and perform various calculations.

For more information and examples, refer to the provided functions and usage in the library's source files.

Created by [Mahmoud Mohamed]
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)