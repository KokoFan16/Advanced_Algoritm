#include <iostream>
#include <algorithm>
#include <vector>


int integerBreak(int n)
{
    if (n <= 2)
        return 1;
    
    std::vector<int> maxValue(n+1, 0);
    
    maxValue[1] = 0;
    maxValue[2] = 1;
    
    for(int i = 3; i<= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            maxValue[i] = std::max(maxValue[i], std::max(j*(i-j), j*maxValue[i-j]));
        }
    }
    
    return maxValue[n];
}

int main()
{
    int n = 82;
    
    std::cout << integerBreak(n) << std::endl;
}
