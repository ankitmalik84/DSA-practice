// ==================================================== CODE INFINITY ===============================================================

// Tree Transformation
// MediumAccuracy: 54.63%Submissions: 13K+Points: 4
// Finding A Job Is Now Easier Than Today's Problem! Explore Job Fair 2023

// You are given a tree containing N nodes in the form of an array P where Pi represents the parent of the i-th node and P0 = -1 as the tree is rooted at node 0. In one move, you can merge any two adjacent nodes. Calculate the minimum number of moves required to turn the tree into a star tree.

// -> Merging adjacent nodes means deleting the edge between them and considering both the nodes as a single one.
// -> A Star tree is a tree with a center node, and all other nodes are connected to the center node only.

// =======================APPROACH===================>>>>>>>>>>
// 1. The function initializes some variables: i is an integer variable, and ans is set to n - 1. The variable ans will be used to keep track of the answer.

// 2. A vector named degree is created with a size of n + 1 and all elements are initialized to 0. This vector will be used to keep track of the degree of each vertex in a graph.

// 3. The code enters a loop that iterates from 1 to n - 1. Inside the loop, it increments the degree of p[i] and i in the degree vector. In other words, it counts the number of edges connected to each vertex.

// 4. Another loop is executed that iterates from 0 to n - 1. Inside this loop, it checks if the degree of the current vertex (degree[i]) is equal to 1. If it is, it decrements ans by 1. This is done to count the number of vertices that have only one edge connected to them.

// 5.After the loops, there is an if statement that checks if ans is less than 0. If it is, the function returns 0. This means that if the initial value of ans (which is n - 1) is less than 0, it is not a valid input, and the function returns 0 as an error code.

// 6. Finally, if the above condition is not satisfied, the function returns the value of ans.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> p)
    {
        // code here
        int i, ans = n - 1;
        vector<int> degree(n + 1, 0);
        for (i = 1; i < n; i++)
        {
            degree[p[i]]++;
            degree[i]++;
        }
        for (i = 0; i < n; i++)
            if (degree[i] == 1)
                ans--;

        if (ans < 0)
            return 0;
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> p(N);
        for (int i = 0; i < N; i++)
        {
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}
