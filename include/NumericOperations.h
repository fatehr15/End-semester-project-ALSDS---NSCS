#ifndef NUMERIC_OPERATIONS_H
#define NUMERIC_OPERATIONS_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

/* Basic Number Operations */
int sumOFDigits(int num);
int reverseNumber(int num);
bool isPalindrome(int num);
bool isPrime(int num);
int gcd(int a, int b);
int lcm(int a, int b);
long factorial(int num);
int Combination(int n, int p);
bool isEven(int num);
int nd(int num);

/*Intermediate operations on numbers*/
void primeFactors(int num);
bool isArmstrong(int num);
void fibonacciSeries(int n);
int sumDivisors(int num);
bool isPerfect(int num);
bool isMagic(int num);
bool isAutomorphic(int num);

/* Advanced Number Operations */
void toBinary(int num);
bool isNarcissistic(int num);
double sqrtApprox(int num);
double power(int base, int exp);
bool isHappy(int num);
bool isAbundant(int num);
bool isDeficient(int num);
int sumEvenFibonacci(int n);
bool isHarshad(int num);
unsigned long catalanNumber(int n);
void pascalTriangle(int n);
unsigned long bellNumber(int n);
bool isKaprekar(int num);
bool isSmith(int num);
int sumOfPrimes(int n);

#endif 
