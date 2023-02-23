#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <math.h>

bool isPalindrome(int x) {
    int digit, num = x, inverse_num = 0, max_pow = 1;
    double temp = 10;
    if (x < 0)
        return false;
    while (x % (int)temp != x) {
        temp *= 10;
        max_pow += 1;
    }
    //printf("max power is: %f\n", pow(10, max_pow - 1));

    while (num >= 10) {
        digit = (num % 10);
        num = (num - digit) / 10;
        //printf("%d\n", digit);
        inverse_num += pow(10, max_pow - 1) * digit;
        max_pow -= 1;
    }
    digit = num % 10;
    //printf("%d\n", digit);
    inverse_num += pow(10, max_pow - 1) * digit;
    max_pow -= 1;
    //printf("The inverse number is: %d\n", inverse_num);
    return x == inverse_num;
}




bool isPalindrome_super_efficient(int x) {
    if (x == 0)
        return true;
    if (x < 0 || x % 10 == 0)
        return false;
    long res = 0;       
    int y = x;
    while (y != 0) {
        res = res * 10 + y % 10;
        y = y / 10;
    }
    return (x == res ? true : false);
}

int main() 
{
	int number = 1221;
	printf("%d %s palindrome number.\n", number, isPalindrome_super_efficient(number)  ? "is a" : "is not a");
    
	return 0;
}