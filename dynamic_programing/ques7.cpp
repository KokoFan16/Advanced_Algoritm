#include <iostream>
#include <algorithm>
#include <vector>


// c0 = 1; c1 = c0c0 = 1; c2 = c0c1 + c1c0 = 2

long long int catalan(int n)
{
    std::vector<long long int> nums(n+1, 0);
    
    nums[0] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            nums[i] += nums[j]*nums[i-j-1];
        }
    }
    
    return nums[n];
}

int main()
{
    int n = 20;
//    catalan(n);
    
    std::cout << catalan(n) << std::endl;
}
