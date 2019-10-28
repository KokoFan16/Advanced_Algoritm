#include<iostream>
#include <algorithm>
#include <vector>


long long int fib()
{
    std::vector<long long int> nums;
    long long int f = 0;
    nums.push_back(5);
    nums.push_back(6);
    
    long long int sum = 5;
    
    while (f < 50000000000) {

        long long int n = nums.size();
        f = nums[n-1] + nums[n-2];
        
        if (f > 50000000000)
            continue;
        
        nums.push_back(f);
        std::cout << f << std::endl;
        if(f%2 == 1)
        {
            sum += f;
        }
    }
    
    return sum;
}


int main()
{
    long long int sum = fib();
    std::cout << "sum is " << sum << std::endl;
}
