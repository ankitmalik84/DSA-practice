// ==================================================== CODE INFINITY ===============================================================

// Adding Ones
// EasyAccuracy: 48.06%Submissions: 35K+Points: 2
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// You start with an array A of size N. Initially all elements of the array A are zero. You will be given K positive integers. Let j be one of these integers, you have to add 1 to all A[i], where i ≥ j. Your task is to print the array A after all these K updates are done.

// Note: 1-based indexing is followed for updates.

// Example 1:

// Input:
// N = 3, K = 4
// 1 1 2 3
// Output:
// 2 3 4
// Explanation:
// Initially the array is {0, 0, 0}. After the
// first 1, it becomes {1, 1, 1}. After the
// second 1 it becomes {2, 2, 2}. After 2,
// it becomes {2, 3, 3} and
// After 3 it becomes, {2, 3, 4}.
// Example 2:

// Input:
// N = 2, K = 3
// 1 1 1
// Output:
// 3 3
// Explanation:
// Initially the array is {0, 0}. After the
// first 1, it becomes {1, 1}. After the
// second 1 it becomes {2, 2}. After the
// third 1, it becomes {3, 3}.

// =======================APPROACH===================>>>>>>>>>>

// This code is defining a class named "Solution" that contains a method called "update". This method takes in two arrays, 'a' and 'updates', along with their respective lengths 'n' and 'k'. The purpose of this method is to update the elements of array 'a' based on the values in array 'updates'.

// The method works as follows:

// 1. It iterates through the 'updates' array using a for loop, from 0 to 'k-1'. 'k' represents the length of the 'updates' array. In each iteration, it performs the following steps:
//    a. It retrieves the value at the current index in the 'updates' array and subtracts 1 from it. This is done because arrays are zero-based in most programming languages, so we need to adjust the index to match the array's indices.
//    b. It uses the adjusted index to access the corresponding element in array 'a' and increments its value by 1.

// 2. After updating the elements in array 'a' based on the 'updates' array, the method proceeds to another for loop that iterates through the elements of array 'a' from index 0 to 'n-1'. 'n' represents the length of array 'a'. In each iteration, it performs the following steps:
//    a. It checks if the current index is greater than 0. If it is, it means there are previous elements before the current one.
//    b. It adds the value of the previous element (i.e., the element at index 'i-1') to the current element (i.e., the element at index 'i') in array 'a'. This step updates the current element to represent the cumulative sum of all elements before it.

// In simple terms, the 'update' method takes an array 'a' and a set of updates ('updates' array) as input. It then increments the elements in array 'a' at specific positions defined by the 'updates' array. Finally, it computes the cumulative sum of the updated array 'a', where each element represents the sum of itself and all the preceding elements.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void update(int a[], int n, int updates[], int k)
    {
        for (int i = 0; i < k; i++)
        {
            int j = updates[i] - 1;
            a[j]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                a[i] += a[i - 1];
        }
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
        int a[n] = {0}, updates[k] = {0};
        for (int i = 0; i < k; i++)
            cin >> updates[i];
        Solution ob;
        ob.update(a, n, updates, k);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    return 0;
}
