int helper(string & s, int start, int end, unordered_set<string> & dictionary, vector<vector<int>> & dp) 
{
    // If answer for this substring is already computed then we simply return its value.
    if (dp[start][end] != -1) 
    {
        return dp[start][end];
    }

    // If the substring of s from index start to end is already present in the dictionary,
    if (dictionary.count(s.substr(start, end - start + 1)) == 1) 
    {
        return 0;
    }

    // If the current substring is of length 1, then there is no way to break it any more
    if (start == end) 
    {
        return 1e9;
    }

    // Variable which will store the minimum number breaks required for string starting 
    int minBreaks = 1e9;

    // Trying all possible way to break current substring
    for (int i = start; i < end; i++) 
    {
        minBreaks = min(minBreaks, 1 + helper(s, start, i, dictionary, dp) + helper(s, i + 1, end, dictionary, dp));
    }

    // Storing the minBreaks for current substring for future calls to this state.
    dp[start][end] = minBreaks;

    return minBreaks;
}

int stringBreaker(string s, int n, vector<string> dictionary) 
{
    // N * N sized table for storing minBreaks for all substrings of s.
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    unordered_set < string > dict;

    // Inserting words into 'dict'
    for (int i = 0; i < n; i++) 
    {
        dict.insert(dictionary[i]);
    }

    // Calculating the minimum breaks required for the given string.
    int minBreaks = helper(s, 0, s.size() - 1, dict, dp);

    if (minBreaks >= 1e9)
    {
        minBreaks = -1;
    }

    // Returning minBreaks required to break the given string s.
    return minBreaks;
}
