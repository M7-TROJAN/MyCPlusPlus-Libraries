#ifndef MATHEMATIC_H
#define MATHEMATIC_H

#include <iostream>
#include <vector>
#include <cmath>

int ReverseNumber(int);
int RandomNumber(int, int);
float absolute(float);
float MyABS(float);
int roundNumber(double);
int ceilNumber(double);
int SumOfDigits(int Number);
int CountDigitFrequency(int Number, short DigitToCheck);
void PrintDigits(int number);
bool isPalindromeNumber(int number);
void PrintNumberPattern(int Number);
void PrintInvertedNumberPattern(int Number);
double square_root(double num);
bool isPrimeNumber(int number);
bool isPrimeNumber_faster(long long number);
bool isPrimeNumberFaster(long long n);
int count_unique(std::vector<int>a);
int count_unique(int a[], int length);
int count_unique(std::vector<std::string>a);

#endif