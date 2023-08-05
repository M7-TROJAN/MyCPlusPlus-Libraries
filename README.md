# MyCppLibraries

Welcome to the MyCppLibraries repository! This repository contains a collection of C++ libraries developed by [mattar740].

## Libraries

### 1. Date Library

The `date` library provides functions to handle date-related operations. It offers features such as parsing dates, calculating differences between dates, and formatting dates according to various formats.

#### Usage
```cpp
#include <iostream>
#include "date.h"

int main() {
    stDate today = Date::getCurrentDate();
    std::cout << "Today's date: " << formateDate(today) << std::endl;
    return 0;
}
```

## 2. Get Inputs Library
The `get_inputs` library simplifies the process of getting user inputs from the console. It provides functions to read various data types and validate user inputs.

#### Usage

```cpp
#include <iostream>
#include "getinputs.h"

int main() {
    int age = get_int("Enter your age: ");
    std::cout << "You entered: " << age << std::endl;
    return 0;
}
```

## 3. Mathematic Library
The `mathematic` library offers a collection of mathematical functions and utilities, ranging from basic arithmetic to more advanced operations.

### Usage

```cpp
#include <iostream>
#include "mathematic.h"

int main() {
    int result = ReverseNumber(123);
    std::cout << "Result: " << result << std::endl;  // 321
    return 0;
}
```

### 4. Str Library
The `str` library provides string manipulation functions, including operations like string concatenation, substring extraction, and more.

### Usage
```cpp
#include <iostream>
#include "str.h"

int main() {
    std::string password = GeneratePassword();
    std:: cout << password;  // output for example:  hK9Y6YbXbCvPY0oC
    return 0;
}
```

### File Structure
Each library consists of two files:

Header file (.h): Contains function declarations and class definitions.

Implementation file (.cpp): Contains the actual implementation of the functions.


MyCppLibraries/
│
├── date/
│ ├── date.h
│ ├── date.cpp
│
├── get_inputs/
│ ├── get_inputs.h
│ ├── get_inputs.cpp
│
├── mathematic/
│ ├── mathematic.h
│ ├── mathematic.cpp
│
├── str/
│ ├── str.h
│ ├── str.cpp
│
├── FinalProject/
│ ├── mywebapp/
│ ├── ...
│ └── README.md
│
└── README.md



### Contributing
Feel free to contribute to the development of these libraries. Your feedback and suggestions are highly appreciated!

## Contact
For any inquiries or questions, please contact [mahmoud.abdalaziz@outlook.com].

Happy coding!

[Mahmoud Mohamed]
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)
