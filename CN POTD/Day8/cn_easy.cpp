#include <bits/stdc++.h> 

int findMinNumbers(vector<int> &arr, int sum, int maxVal) {
    int ans = 0;
    int wholeSum = accumulate(arr.begin(), arr.end(), 0);

    // Calculate the difference between desired sum and the total sum
    int diff = sum - wholeSum;

    if (diff == 0) {
        return 0; // No modifications needed
    }

    // Calculate the number of operations needed to achieve the desired difference
    ans = abs(diff) / maxVal;
    if (abs(diff) % maxVal != 0) {
        ans++; // Need one more operation if there's a remainder
    }
    
    return ans;
}
