#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


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
