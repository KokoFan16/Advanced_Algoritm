#include<iostream>
#include <algorithm>
#include <vector>

/*
FibDp sequences: 5, 6, 11, 17, 28 ...
Take into consideration the numbers in the FibDP series whose values are not more than 50000000000.
What is the sum of the odd-valued terms?
*/


long long int fib()
{
    std::vector<long long int> nums;
    long long int f = 0;
    // First and second items
    nums.push_back(5);
    nums.push_back(6);
    
    long long int sum = 5;
    
    while (f < 50000000000) {

        long long int n = nums.size();
        // FibDP series
        f = nums[n-1] + nums[n-2];
        if (f > 50000000000)
            continue;
        nums.push_back(f);
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
