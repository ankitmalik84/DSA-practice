int splitString(string s)
{
    // Write your code here
    int n = s.length();

    vector<int> prefix(n);

    vector<int> suffix(n);

    vector<int> freq(26, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int ch = s[i] - 'a';
        freq[ch]++;

        if (freq[ch] == 1)
            cnt++;

        prefix[i] = cnt;
    }
    freq = vector<int>(26, 0);
    cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int idx = s[i] - 'a';
        freq[idx]++;
        if (freq[idx] == 1)
            cnt++;

        suffix[i] = cnt;
    }
    int splits = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (prefix[i] == suffix[i + 1])
        {
            splits++;
        }
    }
    return splits;
}