// ==================================================== CODE INFINITY ===============================================================

// Express as sum of power of natural numbers
// MediumAccuracy: 45.35%Submissions: 22K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given two numbers n and x, find out the total number of ways n can be expressed as the sum of the Xth power of unique natural numbers. As the total number of ways can be very large, so return the number of ways modulo 109 + 7.

// Example 1:

// Input:
// n = 10, x = 2
// Output:
// 1
// Explanation:
// 10 = 12 + 32, Hence total 1 possibility.

// =======================APPROACH===================>>>>>>>>>>
// Let's go through it step by step:

// 1. The Solution class is defined, which contains the numOfWays function.
// 2. The numOfWays function takes two parameters: n and x.
//      n represents the given number.
//      x represents the power to which the numbers are raised.
// 3. The function initializes an empty vector al to store the numbers raised to the power x.
// 4. It iterates from i = 1 to n and calculates curr = pow(i, x). If curr is less than or equal to n, it adds curr to the al vector. Otherwise, it breaks the loop.
//  This step populates the vector al with numbers raised to the power x that are less than or equal to n.
// 5. It initializes a 2D vector dp of size (n+1) x (n+1) with all values set to -1. This vector will be used for memoization in the recursive help function.
// 6. The function then calls the help function with the initial parameters:
//      al is the vector containing numbers raised to the power x.
//      i is the current index (initially 0).
//      n is the given number.
//      al.size() is the size of the al vector.
//      dp is the memoization vector.
// 7. The help function is a recursive function that calculates the number of ways to represent n as the sum of powers of numbers from the al vector.
//      If n is less than 0, it means the sum has exceeded n, so it returns 0.
//      If i is equal to the size of the al vector, it means we have considered all numbers, and if n is 0, it means we have found a valid way to represent n. So it returns 1 in this case, and 0 otherwise.
//      If the value of dp[i][n] is not -1, it means the result for these parameters has already been calculated and stored in dp, so it directly returns that value.
//      Otherwise, it calculates the result recursively by adding the results of two recursive calls:
//          The first call help(al, i + 1, n, size, dp) represents the case where the current number from al is not included in the sum.
//          The second call help(al, i + 1, n - al[i], size, dp) represents the case where the current number from al is included in the sum.
//      The result is stored in dp[i][n] and returned.
// 8. Finally, the numOfWays function returns the result of the help function call.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int mod = 1000000007;

    int help(vector<int> &al, int i, int n, int size, vector<vector<int>> &dp)
    {
        if (n < 0)
            return 0;

        if (i == size)
        {
            if (n == 0)
                return dp[i][n] = 1;
            else
                return dp[i][n] = 0;
        }

        if (dp[i][n] != -1)
            return dp[i][n];

        return dp[i][n] = (help(al, i + 1, n, size, dp) % mod + help(al, i + 1, n - al[i], size, dp) % mod) % mod;
    }

    int numOfWays(int n, int x)
    {
        vector<int> al;
        for (int i = 1; i <= n; i++)
        {
            int curr = pow(i, x);
            if (curr <= n)
                al.push_back(curr);
            else
                break;
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return help(al, 0, n, al.size(), dp);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        Solution ob;
        cout << ob.numOfWays(n, x) << endl;
    }
    return 0;
}
