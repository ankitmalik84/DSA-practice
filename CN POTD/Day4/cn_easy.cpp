#include <bits/stdc++.h>

string stringReverse(string S)
{
    int start = 0;
    int end = S.length() - 1;
    while (start < end)
    {
        swap(S[start], S[end]);
        start++;
        end--;
    }
    return S;
}