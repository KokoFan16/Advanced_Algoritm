#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <iterator>


/*
In a matrix, the minimal path sum from the top left to the bottom right, by only moving to the right and down.

For the attached 80 × 80 matrix [matrix.txt], find the minimal path sum.
*/


int findMinPath(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    std::vector<int> cur(n, matrix[0][0]);
    
    for(int i = 1; i < n; i++)
    {
        cur[i] = cur[i-1] + matrix[i][0];
    }
    
    for(int j = 1; j < m; j++)
    {
        cur[0] += matrix[0][j];
        for(int i = 1; i < n; i++)
        {
            cur[i] = std::min(cur[i-1], cur[i]) + matrix[i][j];
        }
    }
    
    return cur[m-1];
}

int main()
{
    
    std::vector<std::vector<int>> matrix;


    std::string filename = "./matrix.txt";

    std::ifstream infile(filename);

    if(!infile)
    {
        std::cerr << "Cannot open the File: " << filename << std::endl;
    }

    std::string str;

    while(std::getline(infile, str))
    {
        std::istringstream ss(str);
        std::vector<int> seq;
       
        for (int i; ss >> i;) {
            seq.push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
        
        matrix.push_back(seq);
    }
    
    std::cout << findMinPath(matrix) << std::endl;
}
