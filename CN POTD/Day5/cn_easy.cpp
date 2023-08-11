#include <bits/stdc++.h>
int findSetBit(int n)
{
    if (n == 0 || (n & (n - 1)) != 0)
    {
        // If n is 0 or has more than one set bit, return -1
        return -1;
    }

    int position = 0;
    while (n > 0)
    {
        n >>= 1;    // Right-shift the n by 1
        position++; // Increment the position counter
    }

    return position;
}
