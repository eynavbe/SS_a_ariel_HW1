#include "NumClass.h"
#include <stdio.h>
#include <math.h>

int calculationAssembly(int r){
    int a = 1;
    for (int i = 2; i <= r; i++)
    {
        a = a* i;
    }
    return a;
}

int isStrong(int n)
{
    int sum = 0;
    int n2 = n;
    while (n2 > 0)
    {
        int r = n2%10;
        sum = sum + calculationAssembly(r);
        n2 = n2/10;
    }
    return sum == n;
}

int isPrime(int n)
{
    if (n%2 == 0)
    {
        return n == 2;
    }
    int i =3;
    while (i*i <= n)
    {
        if (n % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
