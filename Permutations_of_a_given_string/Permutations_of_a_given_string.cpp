// ==================================================== CODE INFINITY ===============================================================

// Permutations of a given string
// MediumAccuracy: 34.65%Submissions: 215K+Points: 4
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

// Example 1:

// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6
// forms as ABC, ACB, BAC, BCA, CAB and CBA .
// Example 2:

// Input: ABSG
// Output:
// ABGS ABSG AGBS AGSB ASBG ASGB BAGS
// BASG BGAS BGSA BSAG BSGA GABS GASB
// GBAS GBSA GSAB GSBA SABG SAGB SBAG
// SBGA SGAB SGBA
// Explanation:
// Given string ABSG has 24 permutations.

// =======================APPROACH===================>>>>>>>>>>

// This function find_permutation is a part of the Solution class and takes a string S as input. It aims to find all possible permutations of the characters in the given string and return them in lexicographically sorted order.

// Let's go through the code step by step:

// The function starts by creating an empty vector ans to store the resulting permutations and a map m to keep track of the permutations that have already been generated.

// The function then calls a helper function cal with initial parameters: i = 0 (starting index), n = S.length() (length of the input string), s = S (initial string), ans (reference to the vector to store permutations), and m (reference to the map).

// The cal function is a recursive function that generates permutations using backtracking. It takes the current index i, string length n, the current string s, the vector ans, and the map m.

// The base case of the recursion is when i becomes greater than or equal to n. This means we have considered all the characters in the string. At this point, the current permutation s is added to the ans vector only if it hasn't been added before (checked using m). Then, the count of this permutation is incremented in the map m. Finally, the function returns.

// If the base case is not met, the function proceeds to a loop that iterates from k = i to n-1. This loop aims to swap the character at index i with each character from k to n-1, generating different permutations.

// Within the loop, the characters at indices i and k in the string s are swapped using the swap function.

// The cal function is then called recursively with the updated i+1 index. This will generate permutations for the remaining characters starting from the next index.

// After the recursive call returns, the characters at indices i and k are swapped back to their original positions to maintain the original order for the next iteration of the loop.

// Once the loop finishes, the cal function returns to the find_permutation function.

// The ans vector containing all the permutations is sorted in lexicographically ascending order using the sort function.

// Finally, the sorted vector of permutations is returned as the output.

// In summary, this function generates all possible permutations of the characters in the given string using a recursive backtracking approach. It avoids duplicate permutations by using a map to keep track of generated permutations. The resulting permutations are then sorted before being returned.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void cal(int i, int n, string s, vector<string> &ans, map<string, int> &m)
    {

        if (i >= n)
        {
            if (m[s] == 0)
                ans.push_back(s);
            m[s]++;
            return;
        }

        for (int k = i; k < n; k++)
        {
            swap(s[i], s[k]);
            cal(i + 1, n, s, ans, m);
            swap(s[i], s[k]);
        }
    }

    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        map<string, int> m;
        cal(0, S.length(), S, ans, m);
        sort(begin(ans), end(ans));
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
