#include <bits/stdc++.h>
using namespace std;
// Approach 1 here we use memorization in recusrion
//  int f(int n, vector<int> &dp)
//  {
//      if (n <= 1)
//          return n;

//     if (dp[n] != -1)
//         return dp[n];

//     return dp[n] = f(n - 1, dp) + f(n - 2, dp);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1, -1);
//     cout <<"Your fibonacci number is "<< f(n, dp);
//     return 0;
// }

// Approach 2 here we also reduce space complexity------------------------>

int main()
{
    int n;
    cout << "Enter the number " << endl;
    cin >> n;
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << "Your fibonacci number is " << prev;
    return 0;
}