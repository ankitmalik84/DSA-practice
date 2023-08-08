#include <bits/stdc++.h>
int minimizeIt(vector<int> A, int k)
{
    int n = A.size();

    if (n <= 0)
        return -1;

    sort(A.begin(), A.end());

    int mini = 0, maxi = 0, res = 0;

    res = A[n - 1] - A[0];

    for (int i = 1; i < n; i++)
    {

        if (A[i] >= k)
        {
            mini = min(A[i] - k, A[0] + k);

            maxi = max(A[i - 1] + k, A[n - 1] - k);

            res = min(res, (maxi - mini));
        }
    }
    return res;
}