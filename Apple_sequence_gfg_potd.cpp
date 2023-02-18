// Question=========>>Apple Sequences
// Easy

// There is a string of size n containing only 'A' and 'O'. 'A' stands for Apple, and 'O' stands for Orange. We have m number of spells, each spell allows us to convert an orange into an apple.

// Find the longest sequence of apples you can make, given a string and the value of m.

// Example 1:

// Input:
// N = 5
// M = 1
// arr[] = 'AAOAO'
// Output: 4
// Explanation: Changing the orange at
// 3rd position into an apple gives
// us the maximum possible answer.

// Example 2:

// Input:
// N = 5
// M = 1
// arr = 'AOOAO'
// Output: 2
// Explanation: Changing any orange into
// an apple will give us a sequence
// of length 2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appleSequences(int n, int m, string arr)
    {
        int st = 0;
        int end = 0;
        int ans = 0;
        while (end != n)
        {
            if (m > 0)
            {
                if (arr[end] == 'O')
                {
                    m--;
                }
            }
            else
            {
                if (arr[end] == 'O')
                {
                    while (arr[st] != 'O')
                    {
                        st++;
                    }
                    st++;
                }
            }
            ans = max(ans, end - st + 1);
            end++;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;

        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0;
}