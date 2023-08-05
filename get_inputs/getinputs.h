
#ifndef GETiNPUTS_H
#define GETiNPUTS_H

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
int ReadPositiveNumber(const std::string &);
int getInputInRange(const int& from, const int& to, const std::string& message);
int readNumber_From_To(int from, int to, std::string);
int ReadNumber();
int get_int(const std::string &);
float get_float(std::string);
double get_double(std::string);
std::string get_string(std::string);
char get_char(std::string);
std::string readPinCode(const std::string&);
std::string readPhoneNumber(const std::string&);
long long GetLongLongInt(const std::string& message);

#endif // GETiNPUTS_H