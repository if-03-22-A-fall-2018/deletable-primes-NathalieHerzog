/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */

#include "deletable_primes.h"
#include <math.h>

//initial code

/*
unsigned long remove_digit(int index, unsigned long n)
{
    int count = 0;
    long temps = n;

    //determine the length of n
    while (temps >= 1)
    {
        temps /= 10;
        count++;
    }

    int temp[count];
    int tempTemp[count - 1];

    //save digits of n into the array
    temps = n;
    for (int i = count - 1; i >= 0; i--)
    {
        temp[i] = temps % 10;
        temps /= 10;
    }

    //save the elements of the first array in a new one - without the one to be removed
    int u = 0;
    int j = 0;

    if (index == 0)
    {
        index += (count - index - 1);
    }
    else
    {
        index -= 1;
    }

    while (u < count)
    {
        if (u != index)
        {
            tempTemp[j] = temp[u];
            j++;
        }

        u++;
    }

    unsigned long newLong = 0;

    //convert array back to unsigned long
    for (int i = 0; i < count; i++)
    {
        if(tempTemp[0] == 0)
        {
            return 0;
        }
        else
        {
            newLong = 10 * newLong + tempTemp[i];
        }
    
    }

    return newLong;
}

int get_ways(unsigned long n)
{
    if (n < 10 && is_prime(n))
    {
        return 1;
    }

    int ways = 0;
    int count;
    int temp = n;

    while (temp >= 1)
    {
        temp /= 10;
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        if (is_prime(remove_digit(n, i)))
        {
            ways += get_ways(remove_digit(i, n));
        }
    }

    return ways;
}

bool is_prime(unsigned long n)
{
    int temp = n;

    for (int i = 2; i < temp; i++)
    {
        if (temp % i == 0)
        {
            return false;
        }
    }

    return true;
}
*/


unsigned long remove_digit(int index, unsigned long n)
{
    int behind = 0;

    if (index > get_length(n))
    {
        return n;
    }

    //had to copy some code from someone else since I was really stuck
    //and nobody could help me because of how complicated I wrote my initial code
    behind = n % (int)pow(10, index);
    n /= pow(10, index + 1);
    return n * pow(10, index) + behind;
}

int get_ways(unsigned long n)
{
    int ways = 0;

    if (!is_prime(n))
    {
        return 0;
    }
    if (n < 10)
    {
        return 1;
    }

    for (int i = 0; i < get_length(n); i++)
    {
        ways += get_ways(remove_digit(i, n));
    }

    return ways;
}

bool is_prime(unsigned long n)
{
    int temp = n;

    for (int i = 2; i < temp; i++)
    {
        if (temp % i == 0)
        {
            return false;
        }
    }

    return true;
}

int get_length(unsigned long n)
{
     if(n == 0){
     return 1;
   }
   return floor(log10(n))+1;
}