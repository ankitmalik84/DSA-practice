// ==================================================== CODE INFINITY ===============================================================

// k largest elements
// MediumAccuracy: 53.56%Submissions: 128K+Points: 4
// Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  The output elements should be printed in decreasing order.

// Example 1:

// Input:
// N = 5, K = 2
// Arr[] = {12, 5, 787, 1, 23}
// Output: 787 23
// Explanation: 1st largest element in the
// array is 787 and second largest is 23.
// Example 2:

// Input:
// N = 7, K = 3
// Arr[] = {1, 23, 12, 9, 30, 2, 50}
// Output: 50 30 23
// Explanation: 3 Largest element in the
// array are 50, 30 and 23.

// =======================APPROACH===================>>>>>>>>>>

// The given code is a function named `kLargest` that takes three parameters: an integer array `arr`, the size of the array `n`, and an integer `k`. The function aims to find and return the `k` largest elements from the given array.

// Here's an explanation of the code in simple language:
// 1. Create an integer array called `my` with a size of `k` to store the `k` largest elements.
// 2. Sort the input array `arr` in ascending order using the `Arrays.sort()` method.
// 3. Initialize a variable `j` with the value of `n-1`, which represents the last index of the sorted array.
// 4. Iterate `k` times using a for loop:
//    - Assign the value at index `j` in the sorted array to the `i`-th position in the `my` array.
//    - Decrement `j` by 1 to move to the next largest element.
// 5. Return the `my` array containing the `k` largest elements.

// .
// ================= CODE ==================>>>>>>>
// .

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        std::vector<int> my(k);
        std::sort(arr, arr + n);
        int j = n - 1;
        for (int i = 0; i < k; i++)
        {
            my[i] = arr[j];
            j--;
        }
        return my;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
