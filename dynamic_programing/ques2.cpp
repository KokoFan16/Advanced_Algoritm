#include<iostream>
#include <algorithm>
#include <vector>


long long int findRoutes(int m, int n) {
    std::vector<std::vector<long long int>> routes(m+1, std::vector<long long int>(n+1, 1));
    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
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
