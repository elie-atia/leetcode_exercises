#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>

int romanToInt(char* s) {
       int t['X' + 1] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000,
    };
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
            number += t[s[i]];
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
            number += t[s[i]];
            passToNextSymbol = false;
        }
    }
    return number;
}



int main()
{
    int number = romanToInt("IM");
    printf("%d", number);
   
    return 0;
}


