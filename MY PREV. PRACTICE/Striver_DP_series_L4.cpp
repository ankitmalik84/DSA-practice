#include <bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &height, int k)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minStep = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                minStep = min(minStep, jump);
            }
        }
        dp[i] = minStep;
    }
    return dp[n - 1];
}
int main()
{
    int n, k;
    cout << "Enter the number of stairs " << endl;
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the number of height of each stairs " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << "Enter the number of steps ";
    cin >> k;
    cout << frogJump(n, heights, k);

    return 0;
}