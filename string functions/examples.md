# Examples of Using C++ String Manipulation and Transformation Functions

This document provides examples of how to use the functions from the C++ String Manipulation and Transformation Library. Each section includes code snippets and explanations for different functions.

## Conversion Functions

### Example: Converting Numbers to Text

```cpp
#include "str.h"

int main() {
    long long number = 12345;
    std::string text = convertNumberToText(number);
    std::cout << "Number: " << number << " in text: " << text << std::endl;
    return 0;
}
```

## Transformation Functions

### Example: Capitalizing the First Letter of Each Word

```cpp
#include "str.h"

int main() {
    std::string sentence = "hello world";
    std::string capitalized = capitalizeFirstLetterOfEachWord(sentence);
    std::cout << "Original: " << sentence << "\nCapitalized: " << capitalized << std::endl;
    return 0;
}
```

## Utility Functions

### Example: Counting Lowercase and Uppercase Letters

```cpp
#include "str.h"

int main() {
    std::string sentence = "Hello World";
    int lowerCount = countLowerLetters(sentence);
    int upperCount = countUpperLetters(sentence);
    std::cout << "Lowercase count: " << lowerCount << "\nUppercase count: " << upperCount << std::endl;
    return 0;
}
```

## Example: Replacing Substrings

```cpp
#include "str.h"

int main() {
    std::string sentence = "The cat in the hat";
    std::string replaced = replaceSubstring(sentence, "cat", "dog");
    std::cout << "Original: " << sentence << "\nReplaced: " << replaced << std::endl;
    return 0;
}
```

## String Splitting and Joining

### Example: Splitting and Joining Strings

```cpp
#include "str.h"

int main() {
    std::string sentence = "Hello,world,this,is,a,test";
    std::vector<std::string> words = splitString(sentence, ",");
    std::string joined = joinString(words, " ");
    std::cout << "Original: " << sentence << "\nJoined: " << joined << std::endl;
    return 0;
}
```

## Other Functions

### Example: Generating Strong Passwords

```cpp
#include "str.h"

int main() {
    std::string password = GeneratePassword();
    std::cout << "Generated Password: " << password << std::endl;
    return 0;
}
```

### Example: Printing Letter Patterns

```cpp
#include "str.h"

int main() {
    int numRows = 5;
    PrintLetterPattern(numRows);
    return 0;
}
```

### Conclusion
These are just a few examples of the functions available in the C++ String Manipulation and Transformation Library. You can explore and utilize these functions to streamline various string-related tasks in your C++ programs.

## Created by 
- [Mahmoud Mohamed]
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)
