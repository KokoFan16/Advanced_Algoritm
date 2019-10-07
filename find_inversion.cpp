#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

// Brute force
int findInversion1(int nums[], int n)
{
    // The size of the array
    int count = 0;
    // Compare numbers[i] with the elements behind it
    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            //Counting
            if (nums[i] > nums[j])
                count++;
        }
    }
    return count;
}


// Using merge sort to find the inversions
// The defination of Merge sort
int mergeSort(int nums[], int tmp[], int left, int right);
int merge(int nums[], int tmp[], int left, int mid, int right);

// Divide and conquer
int findInversion2(int nums[], int n)
{
    int tmp[n]; // Store the temporary array in mergeSort
    return mergeSort(nums, tmp, 0, n - 1); // Call mergeSort which returns the number of inversions
}

// Merge Sort
int mergeSort(int nums[], int tmp[], int left, int right)
{
    int mid, count = 0;
    if(left < right)
    {
        // Divide the array into left and right, then recursive call itself
        mid = left + (right - left)/2;
        // count is sum of nversions in left, right, and merging
        count = mergeSort(nums, tmp, left, mid);
        count += mergeSort(nums, tmp, mid + 1, right);
        // Merge the two parts
        count += merge(nums, tmp, left, mid + 1, right);
    }
    return count;
}


int merge(int nums[], int tmp[], int left, int mid, int right)
{
    int count = 0;
    int i = left, j = mid, k = left;
    // Put the smaller one in left or rignt into tmp array
    while ((i < mid) && (j < right + 1) ) {
        // If left one is larger
        if(nums[i] <= nums[j])
        {
            tmp[k++] = nums[i++];
        }
        // If right one is larger
        else
        {
            tmp[k++] = nums[j++];
            count += mid - i;
        }
    }
    //Copy the remaining nums of left
    while (i < mid) {
        tmp[k++] = nums[i++];
    }
    //Copy the remaining nums of right
    while (j < right + 1) {
        tmp[k++] = nums[j++];
    }
    //Copy sorted array to original array
    for (i = left; i < right + 1; i++)
        nums[i] = tmp[i];
    
    return count;
}


int main()
{
    
    int n;
    std::string filename;
    std::fstream infile;
    // Get the length of array from user
    std::cout << "Please enter the length of the input array: ";
    std::cin >> n;
    
    int nums[n];
    
    // Get the file path from user
    std::cout << "Please enter the file path to read: ";
    std::cin >> filename;
    
    infile.open(filename.c_str());
    
    if(!infile)
    {
        std::cerr << "Cannot open the File: " << filename << std::endl;
    }
    
    for(int i = 0; i < n; i++)
    {
        infile >> nums[i];
    }
    std::cout << "\n";
    
    // The time for brute force
    auto start1 = std::chrono::high_resolution_clock::now();
    int count1 = findInversion1(nums, n);
    auto end1 = std::chrono::high_resolution_clock::now();
    
    // Print the time amd inversions of brute force
    std::cout << "The number of inversions of brute force is " << count1 << std::endl;
    std::cout << "The running time of brute force of file " << n << " is " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1).count() << " nanoseconds \n";
    
    // The time for divide and conquer
    auto start2 = std::chrono::high_resolution_clock::now();
    int count2 = findInversion2(nums, n);
    auto end2 = std::chrono::high_resolution_clock::now();
    
    // Print the time amd inversions of divide and conquer
    std::cout << "The number of inversions of divide and conquer is " << count2 << std::endl;
    std::cout << "The running time of divide and conquer of file " << n << " is " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2-start2).count() << " nanoseconds \n";

}
