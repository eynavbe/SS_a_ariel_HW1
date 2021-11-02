#include "NumClass.h"
#include <stdio.h>
#include <stdlib.h>

//gcc main.c advancedClassificationRecursion.c NumClass.h  -o run

int countDigits(int n){
    if (n > 0)
    {
        return 1+ countDigits(n/10);
    }
    return 0;  
}

int reverseNumber (int count, int n){
    if (n > 0)
    {
        return (count*(n%10)) + reverseNumber(count /10, n/10);
    }
    return 0;
}

int zeroDigits(int count){
    if (count > 0)
    {
        return 10 * zeroDigits(count-1);
    }
    return 1;
}

int isPalindrome(int n)
{
    if (n==0)
    {
        return 1;
    }
    int count = countDigits(n);
    int zeroD = zeroDigits(count-1);
    return n == reverseNumber(zeroD,n);
} 

int isArmstrongAz(int n,int count)
{ 
    if (count > 0)
    {
        return n * isArmstrongAz(n,count-1);
    }
    return 1;
} 

int isArmstrongSum(int n, int sum, int count)
{
    if (n > 0)
    {
        int f = isArmstrongAz(n%10, count);
        return sum + f +  isArmstrongSum(n/10, sum,count);
    } 
    return sum; 
} 

int isArmstrong(int n)
{
    int sum =0;
    int count = countDigits(n);
    return n == isArmstrongSum(n,sum,count);
} 