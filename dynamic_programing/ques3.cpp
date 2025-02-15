#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <iterator>


/*
You are at the top of a triangle mountain made with numbers. While moving down, you can only move to 
adjacent numbers in the row below.
There are many ways to reach the bottom from the top. Pick the path that maximizes the total.

For example, for the number mountain below, the maximum total you can attain is 23.

What is the maximum total you can achieve for the attached dataset [triangles.txt] ?
*/

int findMaxPath(std::vector<std::vector<int>> &triangle)
{
    int n = triangle.size();
    std::vector<int> maxLen(triangle.back());
    
    for(int x = n - 2; x >= 0; x--)
    {
        for (int y = 0; y <= x; y++) {
            maxLen[y] = std::max(maxLen[y], maxLen[y+1]) + triangle[x][y];
        }
    }
    return maxLen[0];
}

int main()
{
    
    std::vector<std::vector<int>> triangle;
    
    
    std::string filename = "./triangles.txt";
    
    std::ifstream infile(filename);
    
    if(!infile)
    {
        std::cerr << "Cannot open the File: " << filename << std::endl;
    }
    
    std::string str;
    
    while(std::getline(infile, str))
    {
        std::istringstream iss(str);
        using iterator = std::istream_iterator<int>;
        std::vector<int> seq {iterator(iss), iterator()};
        triangle.push_back(seq);
    }
    
    int path = findMaxPath(triangle);
    std::cout << path << std::endl;
}
