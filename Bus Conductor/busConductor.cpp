// ==================================================== CODE INFINITY ===============================================================
// Problem Statement

// Bus Conductor
// EasyAccuracy: 76.14%Submissions: 14K+Points: 2
// Finding A Job Is Now Easier Than Today's Problem! Explore Job Fair 2023

// You are conductor of a bus .There are n chairs and n passengers in the bus. You are given an array chairs of length n, where chairs[i] is the position of the ith chair. You are also given the array passengers of length n, where passengers[j] is the position of the jth passenger.

// You may perform the following move any number of times:

// Increase or decrease the position of the ith passenger by 1 (i.e., moving the ith passenger from position x to x + 1 or x - 1)
// Return the minimum number of moves required to move each passenger to a chair such that no two passengers are in the same chair and every passenger gets a chair.

// Note that there may be multiple chairs or passengers in the same position at the beginning.

// Example 1:

// Input:
// chairs = [3,1,5]
// passengers = [2,7,4]
// Output: 4
// Explanation:
// The passengers are moved as follows:
// - The first passenger is moved from position 2 to position 1 using 1 move.
// - The second passenger is moved from position 7 to position 5 using 2 moves.
// - The third passenger is moved from position 4 to position 3 using 1 move.
// In total, 1 + 2 + 1 = 4 moves were used.

// =======================APPROACH===================>>>>>>>>>>

// 1. The variable ans is initialized to 0. This variable will store the total number of moves required.

// 2. The chairs vector and the passengers vector are sorted in ascending order. Sorting these vectors allows us to compare the positions of chairs and passengers more easily.

// 3. The code enters a loop that iterates n times, starting from 0. This loop compares the positions of chairs and passengers at each index.

// 4. Inside the loop, an if-else statement is used to determine whether the current chair position is greater than the current passenger position.

// 5. If the chair position is greater, it means that the passenger needs to move towards the chair. In this case, the difference between the chair position and the passenger position is added to the ans variable.

// 6. If the chair position is not greater, it means that the passenger is already ahead of the chair. In this case, the difference between the passenger position and the chair position is added to the ans variable.

// 7. After each iteration of the loop, the ans variable keeps track of the total number of moves required for passengers to reach their corresponding chairs.

// 8. Finally, the ans variable is returned as the result of the function.

// In summary, the code sorts the positions of chairs and passengers, and then compares them one by one to calculate the minimum number of moves needed for passengers to reach their chairs. The code accounts for situations where the chairs are ahead or behind the passengers, and adds up the differences in positions to determine the total number of moves required.

// .
// ================= CODE ==================>>>>>>>
// .

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers)
    {
        int ans = 0;
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());

        for (int i = 0; i < n; i++)
        {

            if (chairs[i] > passengers[i])
            {

                ans += (chairs[i] - passengers[i]);
            }
            else
            {

                ans += (passengers[i] - chairs[i]);
            }
        }
        return ans;
    }
};

int main()
{
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> chairs(n), passengers(n);
        for (auto &val : chairs)
            cin >> val;
        for (auto &val : passengers)
            cin >> val;
        int ans = sol.findMoves(n, chairs, passengers);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends