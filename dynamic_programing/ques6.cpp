#include <iostream>
#include <algorithm>
#include <vector>

/*
You are given a positive integer n, break it into the sum of at least two positive integers 
and maximize the product of those integers. Return the maximum product you can get.

Example Input: 10, Output: 36, Explanation: 10 = 3 3 4 = 36.

What is your answer for n = 82.
*/


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
