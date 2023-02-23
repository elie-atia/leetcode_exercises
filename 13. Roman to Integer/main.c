#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>

int symbolToInt(char c) {
    if (c == 'I') {
        return 1;
    }
    else if (c == 'V') {
        return 5;
    }
    else if (c == 'X') {
        return 10;
    }
    else if (c == 'L') {
        return 50;
    }
    else if (c == 'C') {
        return 100;
    }
    else if (c == 'D') {
        return 500;
    }
    else {
        return 1000;
    }
}

int romanToInt(char* s) {
    int length = strlen(s);
    bool passToNextSymbol = false;  //true if we previously added this symbol with the previous symbol
                                    //because it was a special pattern (IV, IX, ...)
    int number = 0;
    for (int i = 0; i < length; i++) {
        if (passToNextSymbol) {
            passToNextSymbol = false;
            continue;
        }
        if (i == length - 1) {
            number += symbolToInt(s[i]);
            continue;
        }
        passToNextSymbol = true;
        if (s[i] == 'I' && s[i + 1] == 'V') {
            number += 4;
        }
        else if (s[i] == 'I' && s[i + 1] == 'X') {
            number += 9;
        }
        else if (s[i] == 'X' && s[i + 1] == 'L') {
            number += 40;
        }
        else if (s[i] == 'X' && s[i + 1] == 'C') {
            number += 90;
        }
        else if (s[i] == 'C' && s[i + 1] == 'D') {
            number += 400;
        }
        else if (s[i] == 'C' && s[i + 1] == 'M') {
            number += 900;
        }
        else {
            number += symbolToInt(s[i]);
            passToNextSymbol = false;
        }
    }
    return number;
}




int main()
{
    int number = romanToInt("VI");
    printf("%d", number);
   
    return 0;
}


