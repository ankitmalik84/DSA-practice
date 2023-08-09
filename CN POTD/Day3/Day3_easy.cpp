#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<int>> userMessages;

void receiveMessage(string user, int time)
{
    userMessages[user].push_back(time);
}

vector<int> getMessageCount(int l, int r, string user, int k)
{
    vector<int> result;
    if (userMessages.find(user) == userMessages.end())
    {
        return result;
        /
    }

    sort(userMessages[user].begin(), userMessages[user].end());

    int chunks = (r - l + 1 + k - 1) / k; // Calculate the number of chunks

    for (int i = 0; i < chunks; ++i)
    {
        int chunkStart = l + i * k;
        int chunkEnd = min(chunkStart + k - 1, r);

        int count = upper_bound(userMessages[user].begin(), userMessages[user].end(), chunkEnd) -
                    lower_bound(userMessages[user].begin(), userMessages[user].end(), chunkStart);

        result.push_back(count);
    }

    return result;
}