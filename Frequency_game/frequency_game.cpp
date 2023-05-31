// ==================================================== CODE INFINITY ===============================================================

// Frequency Game
// EasyAccuracy: 62.74%Submissions: 28K+Points: 2
// Given an array A of size N. The elements of the array consist of positive integers. You have to find the largest element with minimum frequency.

// Example 1:

// Input:
// 5
// 2 2 5 50 1
// Output:
// 50
// Explanation :
// All elements are having frequency 1 except 2.
// 50 is the maximum element with minimum frequency.
// Example 2:

// Input:
// 4
// 3 3 5 5
// Output:
// 5
// Explanation:
// Both 3 and 5 have the same frequency, so 5 should be returned.

// =======================APPROACH===================>>>>>>>>>>

// 1. Initialize a map called mp to store the frequency of each integer in the array. The key represents the integer itself, and the value represents its frequency.
// 2. Set the variable mn (minimum frequency) to a large value of 1e9 (10^9) to ensure it gets updated with the minimum frequency found.
// 3. Iterate over the array using a for loop. In each iteration, increment the frequency of the current integer by 1 in the map mp.
// 4. After the loop, iterate over the key-value pairs in the map mp using a range-based for loop.
// 5. For each key-value pair, update the variable mn with the minimum frequency found so far.
// 6. Initialize the variable ans to -1. This variable will store the largest integer with the minimum frequency.
// 7. Iterate over the key-value pairs in the map mp again.
// 8. For each key-value pair, check if the key (integer) is greater than the current value of ans and if the value (frequency) is equal to the minimum frequency (mn).
// 9. If both conditions are satisfied, update ans with the current key (integer).
// Finally, return the value of ans as the result.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> m;
    int LargButMinFreq(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            m[arr[i]]++;
        int res = INT_MAX;
        int ans;
        for (auto i : m)
        {
            if (i.second < res)
            {
                res = i.second;
                ans = i.first;
            }
            else if (i.second == res)
            {
                if (i.first > ans)
                {
                    ans = i.first;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
