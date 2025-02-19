#include <iostream>
#include "repetition.h"

using std::swap;

int factorial(int num){
    int sum = 1;
    while (num > 0){
        sum = sum * num;
        num -= 1;
    }
    return sum;
}

int gcd(int num1, int num2){
    while (num1 != num2){
        if (num1 < num2){
            swap(num1, num2);
        }
        if (num1 > num2){
            num1 -= num2;
        }
    }
    return num1;
}

