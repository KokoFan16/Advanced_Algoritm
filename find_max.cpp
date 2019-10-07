//
//  find_max.cpp
//  assignment
//
//  Created by kokofan on 9/14/19.
//  Copyright © 2019 koko Fan. All rights reserved.
//

#include <stdio.h>
#include <iostream>

// Find the max value of a array
// This array is increasing firstly until  its maximum element, after which its elements are in decreasing order.
int findMax(int a[], int low, int high)
{
    if(low == high)
    {
        return a[low];
    }
   
    if (high == low + 1)
    {
        return (a[low] > a[high])? a[low]:a[high];
    }
    
    // Recursion
    // Divide this array into two parts
    int mid = (low + high) / 2;
    if(a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
    {
        return a[mid];
    }
    // Return left side
    else if(a[mid] > a[mid + 1] && a[mid] < a[mid - 1])
    {
        return findMax(a, low, mid - 1);
    }
    // Return right side
    else
    {
        return findMax(a, mid + 1, high);
    }
}


int main(int argc, const char * argv[]) {
    
    int n;
    // Get the length of array from user
    std::cout << "Please enter the length of the input array: " << std::endl;
    std::cin >> n;
    
    int a[n];
    // Get the numbers of array with blank space from user
    std::cout << "Please enter the values with blank space: " << std::endl;
    for(int i = 0; i < n; i++)
    {std::cin >> a[i];}
    
    // The length of the array
    int len = int(sizeof(a)/sizeof(a[0]));
    
    int max = findMax(a, 0, len - 1);
    
    std::cout << "The max value of this array is: " << max << std::endl;
}
