//
//  binary_search.cpp
//  assignment
//
//  Created by kokofan on 9/15/19.
//  Copyright © 2019 koko Fan. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <chrono>
#include <string>



//Binary search
int binary_search(std::vector<int> &a, int x, int low, int high, int &count)
{
    // Record the recursive time
    count++;
    
    // Only the numbers in a[low-high] are vaild
    if(high >= low)
    {
        // The mid of the array
        int mid = (low + high)/2;
        
        // Recursion
        if(a[mid] == x)
        {
            return mid;
        }
        // Return left side
        else if(a[mid] > x)
        {
            return binary_search(a, x, low, mid - 1, count);
        }
        // Return right side
        else
        {
            return binary_search(a, x, mid + 1, high, count);
        }
    }
    
    // If this target x cannot be found in the array, return -1
    return -1;
}


//Ternary search
int ternary_search(std::vector<int> &a, int x, int low, int high, int &count)
{
    // Record the recursive time
    count++;

     // Only the numbers in a[low-high] are vaild
    if (high >= low)
    {
        // First mid
        int mid1 = low + (high - low)/3;
        // Second mid
        int mid2 = high - (high - low)/3;
        
        if(a[mid1] == x)
        {
            return mid1;
        }
        else if(a[mid2] == x)
        {
            return mid2;
        }
        
        // Return left side
        else if(a[mid1] > x)
        {
            return ternary_search(a, x, low, mid1 -1, count);
        }
        // Return right side
        else if(a[mid2] < x)
        {
            return ternary_search(a, x, mid2 + 1, high, count);
        }
        // Return mid side (> mid1, < mid2)
        else
        {
            return ternary_search(a, x, mid1 + 1, mid2 -1, count);
        }
    }
    // If this target x cannot be found in the array, return -1
    return -1;
}


int main(int argc, const char * argv[])
{
    // Input array
    std::vector<int> a;
    
    // Read File
    // File path
    std::string filename = "./100000";
    // Open file
    std::ifstream infile(filename);
    
    // Print error if the file cannot be opened
    if(!infile)
    {
        std::cerr << "Cannot open the File: " << filename << std::endl;
    }
    
    std::string str;
    
    // Read file line by line
    while (std::getline(infile, str)) {
        if(str.size() > 0)
        {
            // Put in the input array
            a.push_back(std::stoi(str));
        }
    }
    // Close file
    infile.close();
    
    std::cout << "Read " << a.size() << " numbers" << std::endl;
    std::cout << "\n";
    
    // The length of the input array
    int n = int(a.size());
    
    // All the targets given by the assignment
    std::vector<int> input = {1, 56, 100, 769, 950, 952, 1200, 1505, 4349, 52028, 2712892, 9999616, 4369620, 4369621, 2421119, 2421120, 7336918, 7788346, 7336919, 9235296, 9235299, 10000000};
    
    // Find the target with binary search and ternary search
    int x = 1;
    for(x = 0; x < input.size(); x++)
    {
        std::cout << "***********************************************************\n";
        
        // Binary Search
        // Get the start time of binary search
        auto start1 = std::chrono::high_resolution_clock::now();
        int count1 = 0;
        int ret1 = binary_search(a, input[x], 0, n-1, count1);
        // Get the end time of ternary search
        auto end1 = std::chrono::high_resolution_clock::now();
        
        // Print the result of binary search
        if (ret1 == -1)
        {
            std::cout << "Binary_search: This value " << input[x] <<" isn't in the array, and the recursive time is " << count1 << ". \n";
        }
        else
        {
            std::cout << "Binary_search: Find this value " << input[x] << " in the array, and the recursive time is " << count1 << ". \n";
        }
        
        std::cout << "The elapsed time of binary search is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1).count() << " nanoseconds \n";
        
        std::cout << "\n";
        
        // Ternary search
        // Get the start time of ternary search
        auto start2 = std::chrono::high_resolution_clock::now();
        int count2 = 0;
        int ret2 = ternary_search(a, input[x], 0, n -1, count2);
        // Get the end time of ternary search
        auto end2 = std::chrono::high_resolution_clock::now();
    
         // Print the result of ternary search
        if (ret2 == -1)
        {
            std::cout << "Ternary_search: This value " << input[x] << " isn't in the array, and the recursive times is " << count2 << ". \n";
        }
        else
        {
            std::cout << "Ternary_search: Find this value " << input[x] << " in the array, and the recursive times is " << count2 << ". \n";
        }
        
       
        std::cout << "The elapsed time of binary search is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2-start2).count() << " nanoseconds \n";
        
        std::cout << "***********************************************************\n";
        std::cout << "\n";
        
    }
    
    
    
}


