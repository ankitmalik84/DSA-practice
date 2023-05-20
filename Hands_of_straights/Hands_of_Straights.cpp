// ==================================================== CODE INFINITY ===============================================================

// Problem Statement (Level Medium)

// Alice has some cards, each card has one number written on it. She wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
// Given an integer array hand of size N where hand [ i ] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

// Example 1:

// Input:
// N = 9
// groupSize = 3
// hand[ ] = {1, 2, 3, 6, 2, 3, 4, 7, 8}
// Output: true
// Explanation:
// Alice's hand can be rearranged as {1, 2, 3} , {2, 3, 4}, {6, 7, 8}. There are three groups with size 3. Each group has 3 consecutive cards.

// =======================APPROACH===================>>>>>>>>>>

// 1. The isStraightHand function takes three parameters: n (the number of cards in the hand), g (the size of each group), and hand (a vector containing the cards in the hand).

// 2. The code first checks if it's possible to form groups of size 'g' from the given hand. If the number of cards is not divisible evenly by 'g', it returns false because it won't be possible to form straight hands with the given configuration.

// 3. Next, a map<int,int> named mp is declared to store the frequency of each card in the hand.

// 4. The code then iterates through the hand vector and updates the frequency of each card in the mp map.

// 5. The variable total_sets is calculated by dividing the number of cards in the hand (n) by the group size (g). This represents the number of groups that need to be formed.

// 6. The variable ans is initialized to 0. This variable will keep track of the number of groups that can be formed as straight hands.

// 7. The code enters a loop to process each group. It iterates total_sets times.

// 8. Inside the loop, the variable start_ele is set to the first element in the mp map (which represents the lowest value card in the current group).

// 9. A flag variable is set to 0, indicating that the current group can be formed as a straight hand.

// 10. Another loop is executed 'g' times to process each card in the current group.

// 11. Within this loop, the code checks if the current card (start_ele) exists in the mp map and has a count greater than 0. If so, it reduces the count of that card by 1. If the count becomes 0, it removes the card from the mp map.

// 12. If the current card does not exist in the mp map or its count is 0, it means it's not possible to form a straight hand, so the flag variable is set to 1, and the loop is broken.

// 13. After processing all the cards in the current group, the code checks the flag variable. If it's 1, it means the current group cannot be formed as a straight hand, so the function returns false.

// 14. If the flag variable is 0, it means the current group can be formed as a straight hand, so the ans variable is incremented.

// 15. After processing all the groups, the code compares the value of ans with total_sets. If they are equal, it means all the groups can be formed as straight hands, so the function returns true. Otherwise, it returns false.

// .
// ================= CODE ==================>>>>>>>
// .

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isStraightHand(int n, int g, vector<int> &hand)
    {
        // checking is it possible or not at intial change
        if (n % g != 0)
            return false;

        // taking a map for storing in frequency
        map<int, int> mp;

        for (auto it : hand)
        {
            mp[it]++;
        }

        // Caluclating how many sets are there
        int total_sets = n / g;

        int ans = 0;

        for (int i = 0; i < total_sets; i++)
        {
            int start_ele = (mp.begin())->first;
            int flag = 0;
            int k = g;

            while (k--)
            {
                if (mp[start_ele] > 0)
                {
                    mp[start_ele]--;
                    if (mp[start_ele] == 0)
                    {
                        mp.erase(start_ele);
                    }
                }
                else
                {
                    flag = 1;
                    break;
                }
                start_ele++;
            }

            if (flag == 1)
            {
                return false;
            }
            else
            {
                ans++;
            }
        }

        if (ans == total_sets)
        {
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++)
            cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends