// ==================================================== CODE INFINITY ===============================================================

// Longest Palindrome in a String
// MediumAccuracy: 23.2%Submissions: 248K+Points: 4
// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

// Example 1:

// Input:
// S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic
// substring is "aabbaa".
// Example 2:

// Input:
// S = "abc"
// Output: a
// Explanation: "a", "b" and "c" are the
// longest palindromes with same length.
// The result is the one with the least
// starting index.

// =======================APPROACH===================>>>>>>>>>>

// 1. Initialize start and end variables to keep track of the indices of the longest palindrome substring found so far. Initially, both are set to 0.

// 2. Start a loop that iterates through each character in the string S.

// 3. For each character, consider two cases: one for odd-length palindromes and one for even-length palindromes.

// 4. For odd-length palindromes, set low to i - 1 and high to i. This means that the center of the palindrome is at the current character.

// 5. Inside a while loop, continue expanding the palindrome by decrementing low and incrementing high as long as the characters at low and high are equal, and the indices are within the bounds of the string.

// 6. Check if the current palindrome length (high - low + 1) is greater than the previously recorded end. If so, update start and end to the indices of the current palindrome.

// 7. Repeat steps 4-6 for even-length palindromes by setting low to i - 1 and high to i + 1. This means that the center of the palindrome is between the current character and the next character.

// 8. Repeat steps 2-7 for each character in the string.

// 9. After the loop, check if no palindrome was found (end == 0). If so, return a substring of length 1 starting from the character at index start.

// 10. Otherwise, return the substring of S starting from start with a length of end.

// .
// ================= CODE ==================>>>>>>>
// .

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalin(string S)
    {
        int start = 0, end = 0;
        int low, high;
        for (int i = 0; i < S.length(); i++)
        {
            // odd part
            low = i - 1;
            high = i;
            while (low >= 0 && high < S.length() && S[low] == S[high])
            {

                if (high - low + 1 > end)
                {
                    end = high - low + 1; // current longest pallindrome length
                    start = low;
                }
                low--;
                high++;
            }
            // Even part
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < S.length() && S[low] == S[high])
            {

                if (high - low + 1 > end)
                {
                    end = high - low + 1; // current longest pallindrome length
                    start = low;
                }
                low--;
                high++;
            }
        }
        if (end == 0)
            return S.substr(start, 1); // no pallindrome at all
        return S.substr(start, end);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
