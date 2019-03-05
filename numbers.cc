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


int q1_armstrong(int n){
    int sum = 0;
    int digit = 0;
    int power = 0;
    int number = n;
    int counter = 1;
    
    // narcissistic number cannot be zero so that is checked first
    if (n < 0) return 0;
    else{
        // calculate the number of digits
        while (number) {
            number = (int)(n) / pow(10,counter);
            power++;
            counter++;
        }
        
        // reinitialize digit to 0 and
        number = n;
        
        // calculate the sum of the digits
        while (number) {
            // gets the right-most digit
            digit = (number % 10);
            // adds the right-most digit to the sum
            sum = sum + pow(digit,power);
            // removes the rightmost digit from the number
            number = (int)(number) / 10;
        }
        //std::cout << "final digit: " << digit << endl;
        if (sum == n) return 1;
        else return 0;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 Q02: Uses a counter to keep a running tally
 of the brackets. If the value of the counter is
 a negative number or a positive number i.e. any 
 non-zero number, then we can say that the number
 of brackets is not balanced.
 * * * * * * * * * * * * * * * * * * * * * * * * * */
int q2_brackets(const char *e){
    
    int sum = 0;
    // by default we are assuming that the number of brackets is balanced
    int balanced = 1;
    // copy of the character array so we can do pointer arithmetic
    const char *copy = e;
    
    // while the pointer copy is not pointing to NULL,
    // keep a running tally of the brackets
    while (*copy) {
        // if it is a left bracket, add 1
        if (*copy == '['){
            sum++;
            copy++;
        }
        // if it is a right bracket, subtract 1
        else{
            sum--;
            copy++;
        }
    }
    // If the sum is any non-zero integer, then balanced will be set to 0
    if (sum < 0 || sum != 0) balanced = 0;
    return balanced;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 Q03:
 * * * * * * * * * * * * * * * * * * * * * * * * * */
int q3_perfect(int x){
    
    // By default we are going to assume that perfect is false
    int sum = 0;
    int perfect = 0;
    
    // Odd numbers cannot be perfect numbers so you need to check for that first
    if ((x % 2 != 0) || x == 0){
        return 0;
    }
    else {
        for (int i = 1; i <= (x/2); i++){
            // If there is no remainder, then we can consider
            // the value of i to be a proper divisor
            if (x % i == 0){
                sum += i;
            }
        }
        // If the total sum equals the input for x, then the number is perfect
        if (sum == x) perfect = 1;
    }
    
    return perfect;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 Q06: CORRECT
 * * * * * * * * * * * * * * * * * * * * * * * * * */
int q6_collatz_count(int n){
    
    int count = 0;
    
    //
    if (n <= 0)return 0;
    else {
    //
        while (n > 0 && n != 1){
        //
            if (n % 2 == 0){
                n = n / 2;
                count++;
        }
        //
            else {
                n = (3*n) + 1;
                count++;
            }
        }
    }
    return count;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 Q09: Simple sorting algorithm that takes sorts three
 numbers from least to greatest.
 * * * * * * * * * * * * * * * * * * * * * * * * * */
void q9_sort(int x, int y, int z, int *list){
    
    // makes the first comparison between the first two numbers
    if (x < y) {
        if (y < z){
            list[0] = x;
            list[1] = y;
            list[2] = z;
        }
        // if x is less than z and y, y will be the largest
        else if (x < z) {
            list[0] = x;
            list[1] = z;
            list[2] = y;
        }
        else{
            list[0] = z;
            list[1] = x;
            list[2] = y;
        }
    }
    // assumes that the second number is larger
    else {
        if (x < z){
            list[0] = y;
            list[1] = x;
            list[2] = z;
        }
        else if (y < z) {
            list[0] = y;
            list[1] = z;
            list[2] = x;
        }
        else{
            list[0] = z;
            list[1] = y;
            list[2] = x;
        }
    }
    // prints the sorted elements of the list
    for (int i = 0; i <= 2; i++) {
        std::cout << " " << list[i] << " ";
    }
}



void q1_reverse(char *str, int n){
  // temporary var to hold a character
  char temp;
  // when n is less than or equal to 1 you are at the middle of the string
  if (n <= 1) return;
  else {
    // swap the character at the index of ∗str with the character at the last index
    temp = *str;
    *str = *(str+n-1);
    *(str+n-1) = temp;
    // omit the last character from the end by skipping over the current element
    n -= 2;
    // call reverse on the subsequent index of str return reverse(str+1,n);
    return q1_reverse(str+1,n);
  }
}

int q2_palindrome(const char *str, int n){
  // if the string has only one letter then it is a palindrome
  if (strlen(str) == 1) return 1;
  // if the current element is not equal to the last element , then it is not a palindrome
  if (*(str) != *(str+n-1)) return 0;
  // when the length is 1 or less , then the word is a palindrome
  if (n <= 1) return 1;
  n -= 2;
  return q2_palindrome(str+1,n);
}

int q3_sorted(const int *array, int n){
  // when the the array pointer points to the last index, we can say that the array is sorted
  if (array == array+n-1) return 1;
  // when the current element is greater than the subsequent element , the array is not sorted
  if (*array < *(array+1)) return 0;
  return q3_sorted(array+1,n-1);
}

long int q4_unique(const int *A, int n, int k){
  return 1;
}



unsigned long int q6_hex2dec(const char *hex){
  ul_int hex_num;
  ul_int sum = 0;
  int len = strlen(hex);

  // iterating from the beginning to the end of the string
  for(int i = 0; i < len; i++){
    // hex characters
    switch(*(hex+len-1-i)) { // starting at the last character in the string
        case '0': hex_num = 0;
          break;
        case '1': hex_num = 1;
          break;
        case '2': hex_num = 2;
          break;
        case '3': hex_num = 3;
          break;
        case '4': hex_num = 4;
          break;
        case '5': hex_num = 5;
          break;
        case '6': hex_num = 6;
          break;
        case '7': hex_num = 7;
          break;
        case '8': hex_num = 8;
          break;
        case '9': hex_num = 9;
          break;
        case 'A': hex_num = 10;
          break;
        case 'B': hex_num = 11;
          break;
        case 'C': hex_num = 12;
          break;
        case 'D': hex_num = 13;
          break;
        case 'E': hex_num = 14;
          break;
        case 'F': hex_num = 15;
          break;
        default:
          hex_num = -1;
          std::cout << "THIS AIN'T NO HEX" << std::endl;
          break;
    }
    sum += hex_num * pow(16,i); // add digit to sum where it starts at 16^highest power for that position
  }
  return sum;
}


void q7_dec2hex(unsigned int d, char *hex){
  // add the 0 and x character to the string
  *(hex) = '0';
  *(hex+1) = 'x';
  // fill in the rest of the string with zeroes
  for (int i = 2; i <= 9; i++){
    *(hex+i) = '0';
  }
  // starting at the end of the string and moving inward until the 'x' character is found
  for (int i = 9; i >= 2; i--){
    // find the remainder of d when it is divided by 16
    // this value is the coefficient that corresponds to the hex character
    switch(d % 16) {
          case 0: *(hex+i) = '0';
              break;
          case 1: *(hex+i) = '1';
              break;
          case 2: *(hex+i) = '2';
              break;
          case 3: *(hex+i) = '3';
              break;
          case 4: *(hex+i) = '4';
              break;
          case 5: *(hex+i) = '5';
              break;
          case 6: *(hex+i) = '6';
              break;
          case 7: *(hex+i) = '7';
              break;
          case 8: *(hex+i) = '8';
              break;
          case 9: *(hex+i) = '9';
              break;
          case 10: *(hex+i) = 'A';
              break;
          case 11: *(hex+i) = 'B';
              break;
          case 12: *(hex+i) = 'C';
              break;
          case 13: *(hex+i) = 'D';
              break;
          case 14: *(hex+i) = 'E';
              break;
          case 15: *(hex+i) = 'F';
              break;
          default:
              *(hex+i) = 'Z';
              std::cout << "THIS AIN'T NO HEX" << std::endl;
              break;
      } // end switch
      // find the new value of d
      d = d /16;
  }

}// ENDDDD
