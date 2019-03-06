#ifndef __NUMBERS_H__
#define __NUMBERS_H__

#include "numbers.h"
#include <string>
#include <cstring>
#include <cmath>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
typedef unsigned long int ul_int;
using namespace std;

int armstrong(int n);
int brackets(const char *e);
int perfect(int x)
int collatz_count(int n);
void sort(int x, int y, int z, int *list);
void reverse(char *str, int n);
int palindrome(const char *str, int n);
int sorted(const int *array, int n);
unsigned long int hex2dec(const char *hex);
void dec2hex(unsigned int d, char *hex);


#endif
