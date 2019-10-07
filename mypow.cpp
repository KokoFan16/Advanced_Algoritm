#include <iostream>

double mypow(double x, int n, int &times)
{
    
    if (n == 0)
        return 1;
    
    double result = mypow(x, n/2, times);
    
    times++;
    if (n % 2 == 0)
        return result * result;
    else
        return x * result * result;
}

int main(int argc, char * argv[])
{
    double x = -2;
    int n = 10;
    int times = 0;
    double result = mypow(x, n, times);
    std::cout << result << std::endl;
    std::cout << "The recursive time is "  << times << std::endl;
}
