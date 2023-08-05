#include "str.h"

// Function to convert a number to its textual representation
std::string convertNumberToText(const long long& number)
{
    std::string text = NumberToText(number);
    if(text.empty())
        return "Zero";
    return text;
}

// Function to convert a number to its textual representation
std::string NumberToText(const long long& number)
{
    // Check if the number is zero
    if (number == 0)
    {
        return "";
    }

    // Check if the number is negative
    if (number < 0)
    {
        return "Negative " + NumberToText(-number);
    }

    // Handle numbers from 1 to 19
    if (number >= 1 && number <= 19)
    {
        std::string unitsText[] =
        {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        return unitsText[number] + " ";
    }

    // Handle numbers from 20 to 99
    if (number >= 20 && number <= 99)
    {
        std::string tensText[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return tensText[number / 10] + " " + NumberToText(number % 10);
    }

    // Handle numbers from 100 to 999
    if (number >= 100 && number <= 999)
    {
        return NumberToText(number / 100) + "Hundred " + NumberToText(number % 100);
    }

    // Handle numbers from 1000 to 1999
    if (number >= 1000 && number <= 1999)
    {
        return "One Thousand " + NumberToText(number % 1000);
    }
    // Handle numbers from 2000 to 999,999
    if (number >= 2000 && number <= 999999)
    {
        return NumberToText(number / 1000) + "Thousands " + NumberToText(number % 1000);
    }

    // Handle numbers from 1,000,000 to 1,999,999
    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + NumberToText(number % 1000000);
    }
    // Handle numbers from 2,000,000 to 999,999,999
    if (number >= 2000000 && number <= 999999999)
    {
        return NumberToText(number / 1000000) + "Millions " + NumberToText(number % 1000000);
    }

    // Handle numbers from 1,000,000,000 to 1,999,999,999
    if (number >= 1000000000 && number <= 1999999999)
    {
        return "One Billion " + NumberToText(number % 1000000000);
    }
    // Handle numbers from 2,000,000,000 to 999,999,999,999
    if (number >= 2000000000 && number <= 999999999999)
    {
        return NumberToText(number / 1000000000) + "Billions " + NumberToText(number % 1000000000);
    }

    // Handle numbers from 1,000,000,000,000 to 1,999,999,999,999  "I Can't Read these Numbers :")😂"
    if (number >= 1000000000000 && number <= 1999999999999)
    {
        return "One Trillion " + NumberToText(number % 1000000000000);
    }
    else
    {
        return NumberToText(number / 1000000000000) + "Trillions " + NumberToText(number % 1000000000000);
    }
}

// This function takes a string and an encryption key and returns the encrypted string.
std::string EncryptText(std::string Text, short EncryptionKey)
{
    // Iterate over each character in the string and add the encryption key to its ASCII code.
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

// This function takes a string and an encryption key and returns the decrypted string.
std::string DecryptText(std::string Text, short EncryptionKey)
{
    // Iterate over each character in the string and subtract the encryption key from its ASCII code.
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

// Function to capitalize the first letter of each word in a string
std::string capitalizeFirstLetterOfEachWord(std::string sentence)
{
    bool isNewWord = true;
    for (char &ch : sentence)
    {
        if (isNewWord && ch != ' ')
            ch = toupper(ch);
        isNewWord = (ch == ' '? true : false);
    }
    return sentence;
}

// Function to capitalize the first letter of each word in a string
std::string tittle(const std::string& sentence)
{
    std::string capitalizedSentence = sentence;

    // Set the first letter of the sentence to uppercase
    if (!capitalizedSentence.empty() && std::isalpha(capitalizedSentence[0]))
    {
        capitalizedSentence[0] = std::toupper(capitalizedSentence[0]);
    }

    // Iterate over the characters of the sentence
    for (size_t i = 1; i < capitalizedSentence.length(); ++i)
    {
        // Check if the current character is a space
        if (capitalizedSentence[i - 1] == ' ')
        {
            // Set the next non-space character to uppercase
            if (std::isalpha(capitalizedSentence[i]))
            {
                capitalizedSentence[i] = std::toupper(capitalizedSentence[i]);
            }
        }
    }

    return capitalizedSentence;
}

// Function to Lowercased the first letter of each word in a string
std::string lowercaseFirstLetterOfEachWord(const std::string& sentence)
{
    std::string LowercasedSentence = sentence;
    bool newWord = true;
    for (char& ch : LowercasedSentence)
    {
        if (newWord && std::isalpha(ch))
            ch = std::tolower(ch);
        newWord = (ch == ' ' ? true : false);
    }
    return LowercasedSentence;
}

// Function to invert the case of a character
char invertLetterCase(char ch)
{
    // If the character is uppercase, convert it to lowercase; otherwise, convert it to uppercase
    return std::isupper(ch) ? std::tolower(ch) : std::toupper(ch);
}

// InvertAllStringLettersCase is a function to invert the case of all letters in a string
std::string InvertAllStringLettersCase(const std::string &Sentence)
{
    // Create a copy of the input sentence
    std::string invertingSentence = Sentence;

    // Iterate over each character in the sentence
    for (char & c : invertingSentence)
    {
        // Call the invertLetterCase function to invert the case of the character
        c = invertLetterCase(c);
    }
    // Return the modified sentence with inverted letter case
    return invertingSentence;
}

// Function to count the number of lowercase letters in a string
int countLowerLetters(const std::string &sentence)
{
    int lowerLettersCount = 0;
    for (const char &ch : sentence)
    {
        if (std::islower(ch))
            lowerLettersCount++;
    }
    return lowerLettersCount;
}

// Function to count the number of uppercase letters in a string
int countUpperLetters(const std::string &sentence)
{
    int upperLettersCount = 0;
    for (const char &ch : sentence)
    {
        if (std::isupper(ch))
            upperLettersCount++;
    }
    return upperLettersCount;
}

// Function to count the occurrences of a specific letter in a given string
int countSpecificLetter(const std::string& sentence, char target, bool MatchCase = true)
{
    int count = 0;
    for (const char &ch : sentence)
    {
        if (MatchCase)
        {
            if (ch == target)
                count++;
        }
        else
        {
            if (tolower(ch) == tolower(target))
                count++;
        }
    }
    return count;
}

// Function to Check if the Given Character Is a Vowel or Not
bool isVowel(char ch)
{
    ch = tolower(ch);
    switch (ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

// Function to count the occurrences of vowel letters in a given string
int countVowelLetters(const std::string& sentence)
{
    int count = 0;
    for (const char &ch : sentence)
    {
        if (isVowel(ch))
            count++;
    }
    return count;
}

// This function prints each word in a given string
void printEachWordInString(std::string sentence)
{
    const std::string delimiter = " ";
    std::string currentWord;

    // Iterate through the sentence to extract and print each word
    size_t delimiterPos = 0;
    while ((delimiterPos = sentence.find(delimiter)) != std::string::npos)
    {
        currentWord = sentence.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            std::cout << currentWord << std::endl;
        }
        sentence.erase(0, delimiterPos + delimiter.length());
    }

    // Print the last word if it exists
    if (!sentence.empty())
    {
        std::cout << sentence << std::endl;
    }
}

// This function counts the number of words in a given string
size_t countWordsInString(std::string sentence)
{
    const std::string delimiter = " ";
    std::string currentWord;
    size_t wordCount = 0;

    // Iterate through the sentence to extract and count each word
    size_t delimiterPos = 0;
    while ((delimiterPos = sentence.find(delimiter)) != std::string::npos)
    {
        currentWord = sentence.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            wordCount++;
        }
        sentence.erase(0, delimiterPos + delimiter.length());
    }

    // Count the last word if it exists
    if (!sentence.empty())
    {
        wordCount++;
    }

    return wordCount;
}

// This function splits a string into words using a delimiter
std::vector<std::string> splitString(const std::string& str, const std::string& delimiter = " ")
{
    std::vector<std::string> words;
    std::string currentWord;

    // Iterate through the string to extract and add each word to the vector
    size_t delimiterPos = 0;
    std::string remainingStr = str; // Store the remaining string for manipulation
    while ((delimiterPos = remainingStr.find(delimiter)) != std::string::npos)
    {
        currentWord = remainingStr.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            words.push_back(currentWord);
        }
        remainingStr.erase(0, delimiterPos + delimiter.length());
    }

    // Add the last word if it exists
    if (!remainingStr.empty())
    {
        words.push_back(remainingStr);
    }

    return words;
}

// This function joins a vector of strings into a single string using a delimiter
std::string joinString(const std::vector<std::string> &vString, const std::string &delimiter = " ")
{
    std::string result = "";
    for (int i = 0; i < vString.size(); i++)
    {
        result += vString.at(i);
        if (i != vString.size() - 1)
            result += delimiter;
    }
    return result;
}

// This function joins an array of strings into a single string using a delimiter
std::string joinString(const std::string arr[], const short& arrLength, const std::string& delimiter = " ")
{
    std::string result = "";
    for (int i = 0; i < arrLength; i++)
    {
        result += arr[i];
        if (i != arrLength - 1)
            result += delimiter;
    }
    return result;
}

// This function reverses the order of words in a string
std::string reverseStringWords(const std::string& str)
{
    std::vector<std::string> words = splitString(str);
    std::string reversedString;

    for (auto it = words.rbegin(); it != words.rend(); ++it)
    {
        reversedString += *it;
        if (std::next(it) != words.rend())
        {
            reversedString += " ";
        }
    }

    return reversedString;
}

// This function reverses the order of words in a string (without using splitString() function and without using vector).
std::string reverse_words(const std::string& str)
{
    std::string result = ""; // Initialize an empty string to store the reversed words
    std::string temp = ""; // Initialize an empty string to store each word temporarily

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            // If a space is encountered, it means the current word is complete
            // Append the temporary word to the result string along with a space
            result = temp + " " + result;
            temp = ""; // Reset the temporary string for the next word
        }
        else
        {
            // If a non-space character is encountered, append it to the temporary string
            temp += str[i];
        }
    }

    // Add the last word to the result string (there is no space after the last word)
    result = temp + " " + result;

    // remove the last space 
    result.pop_back();

    return result;
}

// Trim the leading spaces from the string
std::string trimLeft(const std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            return str.substr(i); // returns from index 'i' until the end of the string.  =>  str.substr(i, str.length() - 1)
    }
    return "";
}

// Trim the trailing spaces from the string
std::string trimRight(const std::string& str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
            return str.substr(0, i + 1);
    }
    return "";
}

// Trim the leading and trailing spaces from the string
std::string trim(const std::string& str)
{
    return trimLeft(trimRight(str));
}

// This function replaces all occurrences of a substring with another substring in a given string
std::string replace_Substring(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr)
{
    std::string modifiedStr = originalStr;

    size_t currentPosition = 0;

    // Find and replace all occurrences of the old substring with the new substring
    while ((currentPosition = modifiedStr.find(oldSubstr, currentPosition)) != std::string::npos)
    {
        // Erase the old substring
        modifiedStr.erase(currentPosition, oldSubstr.length());

        // Insert the new substring at the same position
        modifiedStr.insert(currentPosition, newSubstr);

        // Update the current position to skip the newly inserted substring
        currentPosition += newSubstr.length();
    }

    return modifiedStr;
}

// This function replaces all occurrences of a substring with another substring in a given string
std::string replaceSubstring(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr)
{
    std::string modifiedStr = originalStr;

    size_t currentPosition = 0;

    // Find and replace all occurrences of the old substring with the new substring
    while ((currentPosition = modifiedStr.find(oldSubstr, currentPosition)) != std::string::npos)
    {
        modifiedStr.replace(currentPosition, oldSubstr.length(), newSubstr);
        currentPosition += newSubstr.length();
    }

    return modifiedStr;
}

// This function converts all letters in a string to lowercase.
std::string lowerAllStringLetters(const std::string &originalStr)
{
    // Create a copy of the input sentence
    std::string modifiedStr;

    // Iterate over each character in the sentence
    for (const char & c : originalStr)
    {
        modifiedStr += tolower(c);
    }
    // Return the modified string
    return modifiedStr;
}

// This function converts all letters in a string to Uppercase.
std::string upperAllStringLetters(const std::string &originalStr)
{
    // Create a copy of the input string to store the modified string
    std::string modifiedStr;

    // Iterate over each character in the original string and convert it to uppercase
    for (const char & c : originalStr)
    {
        modifiedStr += toupper(c);
    }

    // Return the modified string with all letters converted to uppercase
    return modifiedStr;
}

/* This function replaces occurrences of a substring in a given string, with optional case sensitivity.
It splits the original string into words, and for each word, checks if it matches the old substring.
If a match is found, the word is replaced with the new substring.
The modified words are then joined back into a single string and returned. */
std::string replaceSubstringMatchCase(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr, bool matchCase = true)
{
    // Split the original string into words
    std::vector<std::string> words = splitString(originalStr);
    
    // Iterate over each word
    for(std::string& word : words)
    {
        // Check if the case should be matched or ignored
        if(matchCase)
        {
            // If case should be matched, replace the word if it matches the old substring
            if(word == oldSubstr)
                word = newSubstr;
        }
        else
        {
            // If case should be ignored, replace the word if it matches the old substring (case-insensitive)
            if(lowerAllStringLetters(word) == lowerAllStringLetters(oldSubstr))
                word = newSubstr;
        }
    }
    
    return joinString(words);
}

// Function to check if a character is a punctuation letter
bool isPunctuationLetter(const char& c)
{
    switch (c)
    {
    case '.':
    case ',':
    case '?':
    case '!':
    case ':':
    case ';':
    case '"':
    case '\'':
    case '-':
    case '_':
    case '\\':
    case '/':
    case '(':
    case ')':
    case '[':
    case ']':
    case '{':
    case '}':
        return true;
    default:
        return false;
    }
}

// Function to check if a string is all capital letters
bool isAllCaps(std::string s)
{
    return std::all_of(s.begin(), s.end(), [](char c) { return isupper(c); });
}

// Function to check if a string is all lower letters
bool isAllLower(std::string s)
{
    return std::all_of(s.begin(), s.end(), [](char c) { return islower(c); });
}

// Function to remove all punctuation letters from a given string
std::string removeAllPunctuationLetters(const std::string& originalStr)
{
    std::string modifiedStr = originalStr;

    /*
    Iterate over the string in reverse order
    By iterating over the string in reverse order,
    the characters will be safely removed without affecting the correctness of the results.
    */
    for (int i = modifiedStr.length() - 1; i >= 0; i--)
    {
        // Check if the character is a punctuation letter
        if (ispunct(modifiedStr[i]))
            modifiedStr.erase(i, 1); // Remove the punctuation letter
        
    }

    return modifiedStr;
}

void PrintLetterPattern(int Number)
{
    std::cout << "====================\n";
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            std::cout << char(i);
        }
        std::cout << "\n";
    }
}

void PrintInvertedLetterPattern(int Number)
{
    std::cout << "====================\n";
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        for (int j = 65; j <= i; j++)
        {
            std::cout << char(i);
        }
        std::cout << "\n";
    }
}

void PrintWordsFromAAAtoZZZ()
{
    std::string word = "";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                std::cout << word << std::endl;

                word = "";
            }
        }
        std::cout << "\n===========================\n";
    }
}


// Function to generate a random number
// remember srand((unsigned)time(NULL)); in main function
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// remember srand((unsigned)time(NULL)); in main function
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
            break;
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
            break;
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
            break;
        case enCharType::Digit:
            return char(RandomNumber(48, 57));
            break;
    }
}

// Function to generate a strong password
std::string GeneratePassword()
{
    const int PASSWORD_LENGTH = 16;
    const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::random_device rd; // creates a random_device object to obtain a seed for the random number generator
    std::mt19937 gen(rd()); // creates a mersenne_twister_engine seeded with the random_device object
    std::uniform_int_distribution<> dis(0, CHARACTERS.length() - 1); // creates a uniform integer distribution object for generating random numbers between 0 and the length of the character set - 1

    std::string password = "";
    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        password += CHARACTERS[dis(gen)]; // generate a random character from the character set
    }

    return password;
}

// Function to generate a very strong key with four groups of 4 random letters separated by hyphens
std::string GenerateKey()
{
    const int PASSWORD_LENGTH = 16;
    const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+=";
    std::random_device rd; // creates a random_device object to obtain a seed for the random number generator
    std::mt19937 gen(rd()); // creates a mersenne_twister_engine seeded with the random_device object
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

// This function generates a key consisting of 16 characters, including 3 dashes at positions 4, 8, and 12.
// remember srand((unsigned)time(NULL)); in main function
std::string Generate_Key()
{
    int key_length = 16;
    std::string Key = "";
    for (short i = 1; i <= key_length; i++)
    {
        // Generate a random uppercase letter and append it to the key
        Key += char(rand()%(90 - 65 + 1) + 65);

        // Add a dash after every fourth character, except for the last character
        if (i % 4 == 0 && i > 0 && i != key_length)
            Key += '-';
    }

    return Key;
}

bool IsPalindromeArray(int arr[], int length)
{
    for(int i = 0 ; i < length ; i++)
    {
        if(arr[i] != arr[length - i - 1])
            return false;
    }
    return true;
}