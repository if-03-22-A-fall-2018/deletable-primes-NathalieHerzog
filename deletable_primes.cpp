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
    if(count < 1)
    {
    int tempTemp[count - 1];
    }
    else
    {
        int tempTemp[count];
    }
    

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
        if (i != temp && temp % i == 0)
        {
            return false;
        }
    }

    return true;
}