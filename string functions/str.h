#ifndef STR_H
#define STR_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random> // for random_device, mt19937, uniform_int_distribution

std::string convertNumberToText(const long long& number);
std::string NumberToText(const long long& number);
std::string EncryptText(std::string, short);
std::string DecryptText(std::string, short);
std::string capitalizeFirstLetterOfEachWord(std::string sentence);
std::string tittle(const std::string &sentence);
std::string lowercaseFirstLetterOfEachWord(const std::string &sentence);
char invertLetterCase(char ch);
std::string InvertAllStringLettersCase(const std::string &Sentence);
int countLowerLetters(const std::string &sentence);
int countUpperLetters(const std::string &sentence);
int countSpecificLetter(const std::string& sentence, char target, bool MatchCase);
bool isVowel(char ch);
int countVowelLetters(const std::string& sentence);
void printEachWordInString(std::string sentence);
size_t countWordsInString(std::string sentence);
std::vector<std::string> splitString(const std::string& str, const std::string& delimiter);
std::string joinString(const std::vector<std::string> &vString, const std::string &delimiter);
std::string joinString(const std::string arr[], const short& arrLength, const std::string& delimiter);
std::string reverseStringWords(const std::string& str);
std::string reverse_words(const std::string& str);
std::string trimLeft(const std::string& str);
std::string trimRight(const std::string& str);
std::string trim(const std::string& str);
std::string replaceSubstring(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr);
std::string replace_Substring(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr);
std::string lowerAllStringLetters(const std::string &originalStr);
std::string upperAllStringLetters(const std::string &originalStr);
std::string replaceSubstringMatchCase(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr, bool matchCase = true);
bool isPunctuationLetter(const char& c);
std::string removeAllPunctuationLetters(const std::string& originalStr);
bool isAllCaps(std::string s);
bool isAllLower(std::string s);
void PrintLetterPattern(int Number);
void PrintInvertedLetterPattern(int Number);
void PrintWordsFromAAAtoZZZ();
int RandomNumber(int From, int To);
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};
char GetRandomCharacter(enCharType CharType);
std::string GeneratePassword();
std::string GenerateKey();
std::string Generate_Key();
bool IsPalindromeArray(int arr[], int length);


#endif