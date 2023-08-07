//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int isDivisible(string s)
    {
        // complete the function here
        int n = s.length() - 1;
        int num = 0;
        int i = 0;
        while (n >= 0)
        {
            if (s[n] == '1')
            {
                num += pow(2, i);
            }
            n--;
            i++;
        }

        if (num % 3 == 0)
        {
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
    return 0;
}

// } Driver Code Ends
