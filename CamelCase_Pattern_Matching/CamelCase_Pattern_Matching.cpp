// ==================================================== CODE INFINITY ===============================================================

// CamelCase Pattern Matching
// MediumAccuracy: 16.18%Submissions: 34K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given a dictionary of words where each word follows CamelCase notation, print all words (in lexicographical order) in the dictionary that match with a given pattern consisting of uppercase characters only.

// Example: GeeksForGeeks matches the pattern "GFG", because if we combine all the capital letters in GeeksForGeeks they become GFG.

// CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.

// Example 1:

// Input:
// N=3
// Dictionary=["WelcomeGeek",
// "WelcomeToGeeksForGeeks","GeeksForGeeks"]
// Pattern="WTG"
// Output:
// WelcomeToGeeksForGeeks
// Explanation:
// Since only WelcomeToGeeksForGeeks matches
// the pattern, it is the only answer.
// Example 2:

// Input:
// N=8
// Dictionary=["Hi","Hello","HelloWorld",
// "HiTech","HiGeek","HiTechWorld",
// "HiTechCity","HiTechLab"]
// Pattern="HA"
// Output:
// -1
// Explanation:
// Since the pattern matches none of the words
// of the string,the output is -1.

// =======================APPROACH===================>>>>>>>>>>

// 1. The matchPattern function takes two string parameters: word and patternToMatch. It checks if the patternToMatch is present as a subsequence in the word. It does this by iterating over each character in the word. If the character is uppercase, it is appended to the patternInWord string. Then, it checks if patternInWord is equal to patternToMatch. If they are equal, it means the pattern is found, and the function returns true. At the end, it checks if patternInWord is equal to patternToMatch to handle the case where the pattern is at the end of the word. If they are equal, it returns true; otherwise, it returns false.

// 2. The CamelCase function takes three parameters: an integer n representing the number of words in the dictionary, a vector of strings dictionary containing the words, and a string pattern representing the pattern to match.

// 3. Inside the CamelCase function, an empty vector called ans is created to store the matching words.

// 4. It iterates over each word in the dictionary vector using a range-based for loop. For each word, it calls the matchPattern function to check if the word matches the given pattern. If it does, the word is added to the ans vector.

// 5. After iterating over all the words, the ans vector is sorted in ascending order using the sort function.

// 6. If the ans vector is empty, meaning no words matched the pattern, a special string "-1" is added to the ans vector.

// Finally, the ans vector is returned as the result of the function.

// In summary, the CamelCase function takes a list of words and a pattern and returns a sorted list of words that match the pattern. If no words match the pattern, it returns a vector containing only "-1".

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool matchPattern(string &word, string &patternToMatch)
    {
        string patternInWord = "";

        for (char c : word)
        {
            if (isupper(c))
                patternInWord += c;
            if (patternInWord == patternToMatch)
                return true;
        }

        return patternInWord == patternToMatch;
    }

    vector<string> CamelCase(int n, vector<string> dictionary, string pattern)
    {

        vector<string> ans;

        for (string word : dictionary)
        {
            if (matchPattern(word, pattern))
            {
                ans.push_back(word);
            }
        }

        sort(begin(ans), end(ans));

        if (ans.empty())
            ans.push_back("-1");

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++)
            cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
