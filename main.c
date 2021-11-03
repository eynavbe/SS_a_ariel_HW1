#include <stdio.h>
#include "NumClass.h"
int main()
{
    int min;
    int a;
    int max;
    // printf("Write 2 positive integers: ");
    scanf("%d %d", &a, &max);
    if (a > max)
    {
        min = max;
        max = a;
    }else{
        min = a;
    }
    printf("The Armstrong numbers are:");
    for (int i = min; i <= max; i++)
    {
        if(isArmstrong(i))
        {
        printf(" %d",i);
        }
    }
    printf("\nThe Palindromes are:");
    for (int i = min; i <= max; i++)
    {
        if(isPalindrome(i))
        {
        printf(" %d",i);
        }
    }
    printf("\nThe Prime numbers are:");
    for (int i = min; i <= max; i++)
    {
        if(isPrime(i))
        {
        printf(" %d",i);
        }
    }
    printf("\nThe Strong numbers are:");
    for (int i = min; i <= max; i++)
    {
        if(isStrong(i))
        {
        printf(" %d",i);
        }
    }
    printf("\n");
}