// code studio frog jump question------------->
// striver dp series lecture 3--------->
#include <bits/stdc++.h>
using namespace std;
// Approach 1----Using memorization technic--------->
//  int f(int ind, vector<int> &height, vector<int> &dp)
//  {
//      if (ind == 0)
//          return 0;
//      if (dp[ind] != -1)
//          return dp[ind];
//      int left = f(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
//      int right = INT_MAX;
//      if (ind > 1)
//          right = f(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
//      return dp[ind] = min(left, right);
//  }

// int frogJump(int n, vector<int> &height)
// {
//     vector<int> dp(n + 1, -1);
//     return f(n - 1, height, dp);
// }

// Approach 2 ---- use tabulation technic-------------->
// int frogJump(int n, vector<int> &height)
// {
//     vector<int> dp(n, 0);
//     dp[0] = 0;
//     for (int i = 1; i < n; i++)
//     {
//         int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
//         int ss = INT_MAX;
//         if (i > 1)
//             ss = dp[i - 2] + abs(height[i] - height[i - 2]);

//         dp[i] = min(fs, ss);
//     }
//     return dp[n - 1];
// }

// Approach 3 ----------------------->

int frogJump(int n, vector<int> &height)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = prev + abs(height[i] - height[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(height[i] - height[i - 2]);
        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n;
    cout << "Enter the number of stairs " << endl;
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the number of height of each stairs " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << frogJump(n, heights);

    return 0;
}