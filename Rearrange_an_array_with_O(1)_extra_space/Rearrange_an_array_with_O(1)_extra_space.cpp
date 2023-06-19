// ==================================================== CODE INFINITY ===============================================================

// Rearrange an array with O(1) extra space
// MediumAccuracy: 56.34%Submissions: 91K+Points: 4
// Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].

// NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.

// Example 1:

// Input:
// N = 2
// arr[] = {1,0}
// Output: 0 1
// Explanation:
// arr[arr[0]] = arr[1] = 0.
// arr[arr[1]] = arr[0] = 1.
// Example 2:

// Input:
// N = 5
// arr[] = {4,0,2,1,3}
// Output: 3 4 2 0 1
// Explanation:
// arr[arr[0]] = arr[4] = 3.
// arr[arr[1]] = arr[0] = 4.
// and so on.

// =======================APPROACH===================>>>>>>>>>>

// In this implementation, the function rearrangeArray performs the rearrangement by modifying the array in place.
//  It iterates through the array, and for each element arr[i], it adds (arr[arr[i]] % n) * n to arr[i].
//   This operation allows us to store both the original and modified values simultaneously.

// Finally, the array is divided by n to obtain the rearranged values. The output is then displayed.

// Make sure to compile and run the code to see the rearranged array.

// .
// ================= CODE ==================>>>>>>>
// .

#include <iostream>
using namespace std;

void rearrangeArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] += (arr[arr[i]] % n) * n;

    for (int i = 0; i < n; i++)
        arr[i] /= n;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array (0 to n-1): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    rearrangeArray(arr, n);

    cout << "\nRearranged array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
