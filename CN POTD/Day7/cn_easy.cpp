#include <bits/stdc++.h>
int find_max_subarray(vector<int> &temp, int &start, int &end)
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    start = -1;
    int tempStart = 0;

    for (int i = 0; i < temp.size(); ++i)
    {
        currentSum += temp[i];

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0)
        {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    if (start == -1)
    {
        // All elements are negative, find the maximum element and its index
        maxSum = temp[0];
        start = end = 0;
        for (int i = 1; i < temp.size(); ++i)
        {
            if (temp[i] > maxSum)
            {
                maxSum = temp[i];
                start = end = i;
            }
        }
    }

    return maxSum;
}

int maxSumRectangle(vector<vector<int>> &arr, int n, int m)
{
    int maxSum = INT_MIN;
    int left = -1, right = -1, top = -1, bottom = -1;

    for (int l = 0; l < m; ++l)
    {
        vector<int> temp(n, 0);
        for (int r = l; r < m; ++r)
        {
            for (int i = 0; i < n; ++i)
            {
                temp[i] += arr[i][r];
            }

            int tempTop, tempBottom;
            int tempSum = find_max_subarray(temp, tempTop, tempBottom);

            if (tempSum > maxSum)
            {
                maxSum = tempSum;
                left = l;
                right = r;
                top = tempTop;
                bottom = tempBottom;
            }
        }
    }

    return maxSum;
}
