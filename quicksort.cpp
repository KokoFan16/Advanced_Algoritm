//
//  quicksort.cpp
//  isoLine
//
//  Created by kokofan on 10/6/19.
//  Copyright © 2019 koko Fan. All rights reserved.
//

#include <stdio.h>
#include <iostream>

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot -1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = low;
    int i = pivot + 1;
//    while (arr[i] < arr[low]) {
//        i++;
//    }
    for (int j = i; j < high + 1; j++)
    {
        if (arr[j] < arr[low])
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    int tmp = arr[low];
    arr[low] = arr[i - 1];
    arr[i - 1] = tmp;
    pivot = i - 1;
    return pivot;
}


//int main()
//{
//    int arr[] = {1, 8, 5, 6, 7, 4, 3, 9};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    quickSort(arr, 0, n - 1);
//
//    for(int a:arr){
//        std::cout << a << ", ";
//    }
//    std::cout << "\n";
//}
