#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


/*
In India the currency is made up of Rupees (R), and Paise (P), and there are eight coins in general circulation:
5P, 10P, 25P, 50P, 1R (100P), 2R (200p), 5R (500P), and 10R (1000P)

One way to make 2R is as follows: 1×1R+1×50P +2×25P

How many different ways can you make 5R, given you have infinite supply of coins?
*/

int makeCurrency(int s[], int m, int n)
{
    
    int table[n+1];
    
    memset(table, 0, sizeof(table));
    
    table[0] = 1;
    
    for(int i=0; i<m; i++)
        for(int j=s[i]; j<=n; j+=5)
            table[j] += table[j-s[i]];
    
    return table[n];
}

int main()
{
    int s[] = {5, 10, 25, 50, 100, 200, 500, 1000};
    int m = sizeof(s)/sizeof(s[0]);
    
    std::cout << makeCurrency(s, m, 500) << std::endl;
}
