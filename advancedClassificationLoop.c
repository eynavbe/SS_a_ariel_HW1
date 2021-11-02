#include "NumClass.h"
#include <stdio.h>
#include <stdlib.h>

int countDigits(int n)
{
    int count = 1;
    n = n/10;
    while (n>0)
    {
        count++;
        n = n/10;
    }
    return count;  
}

int isArmstrong(int n)
{
    int sum = 0;
    int n2 = n;
    int a = 1;
    int count = countDigits(n);
    int r = 1;
    while (n2 > 0)
    {
        r = n2%10;
        for (int i = 0; i < count; i++)
        {
            a = a * r; 
        }
        sum = sum + a;
        a = 1;
        n2 = n2/10;
    }
    return sum == n;
} 

char * intToChar(int n, int count){
    char *s = malloc(count);
    while (n > 0)
    {
        count--;
        char r = (n%10) +'0';
        s[count] = r;
        n = n/10;
    }
    return s;
}

int isPalindrome(int n)
{
    int count = countDigits(n);
    char * s = intToChar(n,count);
    int i = 0;
    while (n > 0)
    {
        if (s[i] != ((n%10)+'0'))
        {
            return 0;
        }
        n = n/10;
        i++;
    }
    return 1;
}
  