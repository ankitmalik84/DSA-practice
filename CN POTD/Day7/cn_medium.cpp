#include <bits/stdc++.h>
vector<int> maximumsumSubarray(vector<int> &arr, int n)
{
    int sum = arr[0];
    int maxi = arr[0];
    int start = 0;
    int tempStart = 0;
    vector<int> maxSubarray = {arr[0]};

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > sum + arr[i])
        {
            sum = arr[i];
            tempStart = i;
        }
        else
        {
            sum += arr[i];
        }

        if (sum > maxi)
        {
            maxi = sum;
            start = tempStart;
            maxSubarray = vector<int>(arr.begin() + start, arr.begin() + i + 1);
        }
    }

    return maxSubarray;
}
