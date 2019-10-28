#include<iostream>
#include <algorithm>
#include <vector>

/*
Starting in the top left corner of m * n grid, and only being able to move to the right 
and down to the bottom right corner.

For example, a 2 × 2 grid, there are exactly 6 routes. 

How many such routes are there through a 21 × 21 grid?
*/

long long int findRoutes(int m, int n) {
    std::vector<std::vector<long long int>> routes(m+1, std::vector<long long int>(n+1, 1));
    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            // Each grid can be divided into left and up
            routes[i][j] = routes[i - 1][j] + routes[i][j - 1];
        }
    }
    return routes[m][n];
}


int main()
{
    long long int ans = findRoutes(21, 21);
    std::cout << ans << std::endl;
}
