// ==================================================== CODE INFINITY ===============================================================

// Find Kth permutation
// MediumAccuracy: 63.45%Submissions: 13K+Points: 4
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// Given two integers N (1<=N<=9) and K. Find the kth permutation sequence of first N natural numbers. Return the answer in string format.

// Example 1:

// Input: N = 4, K = 3
// Output: 1324
// Explanation:
// Permutations of first 4 natural numbers:
// 1234,1243,1324,1342,1423,1432.....
// So the 3rd permutation is 1324.
// Example 2:

// Input: N = 3, K = 5
// Output: 312
// Explanation:
// Permutations of first 3 natural numbers:
// 123,132,213,231,312,321.
// So the 5th permutation is 312.

// =======================APPROACH===================>>>>>>>>>>

// This code is a C++ implementation of a function called kthPermutation that generates the kth permutation of numbers from 1 to n. Let's break down the code step by step:

// The function takes two parameters: n represents the range of numbers (from 1 to n), and k represents the position of the desired permutation.

// It creates a vector called fact of size n+1 and initializes all elements to 1. This vector will be used to store factorials.

// It then calculates the factorial values for each number from 1 to n and stores them in the fact vector. This is done using a loop that starts from 1 and multiplies each number with the factorial of the previous number.

// Next, it creates a boolean vector called vis of size n+1 and initializes all elements to false. This vector will be used to keep track of which numbers have been visited.

// It creates an empty string called ans, which will be used to store the resulting permutation.

// The variable i is set to n, which represents the current position of the permutation.

// The code enters a loop that continues until the length of ans is equal to n, i.e., until all numbers have been added to the permutation.

// Inside the loop, it calculates the row number by dividing k by the factorial of i-1. This gives us the row in the permutation table where the desired permutation resides.

// If k is not divisible by fact[i-1], the row number is incremented by 1. This is done to handle cases where k is not an exact multiple of the factorial. For example, if k is 7 and fact[i-1] is 6, the desired permutation is in the second row (row 1).

// It then enters another loop to find the number corresponding to the calculated row. It iterates through numbers from 1 to n and checks if a number has not been visited (vis[j] is false).

// If a number has not been visited, the row number is decremented. When the row number reaches 0, it means the desired number has been found. The number is marked as visited (vis[j] is set to true), and it is added to the ans string by converting it to a character and concatenating it.

// After finding the number for the current row, it updates the value of k by taking the remainder of k divided by fact[i-1]. This ensures that the next iteration of the loop considers the remaining numbers.

// If the updated value of k is 0, it means k was an exact multiple of fact[i-1], and the remainder becomes the maximum factorial value. This is done to handle cases where k reaches the last row of the permutation table. For example, if k is 6 and fact[i-1] is 6, the next row would be the first row (row 0).

// Finally, i is decremented to move to the next position in the permutation.

// Once the loop ends, the resulting ans string contains the kth permutation, and it is returned as the output of the function.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = i * fact[i - 1];
        vector<bool> vis(n + 1, false);
        string ans = "";
        int i = n;
        while (ans.length() != n)
        {
            int row = k / fact[i - 1];
            if (k % fact[i - 1])
                row++;
            for (int j = 1; j <= n; j++)
            {
                if (vis[j] == false)
                {
                    row--;
                }
                if (row == 0)
                {
                    vis[j] = true;
                    ans += (j + '0');
                    break;
                }
            }
            k = k % fact[i - 1];
            if (k == 0)
                k = fact[i - 1];
            i--;
        }
        return ans;
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
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
