#include <iostream>
#include <algorithm>
#include <vector>


// c(n, k) = c(n - 1, k -1) + c(n-1, k)
// c(n, 0) = c(n, n) = 1
int binomialCoefficient(int n, int k)
{
    std::vector<int> coef(k+1, 0);
    
    coef[0] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = std::min(i, k); j > 0; j--)
            coef[j] = coef[j] + coef[j-1];
    }
    
    return coef[k];
}

int main()
{
    int n = 40, k = 5;
    
    std::cout << binomialCoefficient(n, k) << std::endl;
}
