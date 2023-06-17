// ==================================================== CODE INFINITY ===============================================================

// Queue Operations
// EasyAccuracy: 77.76%Submissions: 29K+Points: 2
// Given N integers, the task is to insert those elements in the queue. Also, given M integers, the task is to find the frequency of each number in the Queue.
// Note:

// insert() will be called N times by main().
// findFrequency() will be called M times by main();
// Where k is each element passing through respective function calls.
// Example 1:

// Input:
// N = 8
// 1 2 3 4 5 2 3 1
// M = 5
// 1 3 2 9 10
// Output:
// 2
// 2
// 2
// -1
// -1
// Explanation:
// After inserting 1, 2, 3, 4, 5, 2, 3 and 1 into the queue, frequency of 1 is 2, 3 is 2 and 2 is 2. Since 9 and 10 are not there in the queue we output -1 for them.
// Example 2:

// Input:
// N = 6
// 1 2 1 1 1 4
// M = 4
// 1 5 4 3
// Output:
// 4
// -1
// 1
// -1
// Explanation:
// After inserting 1, 2, 1, 1, 1 and 4 into the queue, frequency of 1 is 4 and that of 4 is 1. Since 5 and 3 are not there in the queue we output -1 for them.

// =======================APPROACH===================>>>>>>>>>>

// This code is implementing a class called Solution that provides two functions: insert and findFrequency.
// Let's break down what each function does.

// void insert(queue<int> &q, int k): This function takes two parameters, a reference to a queue of integers q and an integer k. It inserts the integer k into the queue q.
// Additionally, it keeps track of the frequency of each integer inserted into the queue by maintaining a count in the temp_map unordered map. The temp_map is a data structure that maps integers to their frequencies.
// So, each time an integer k is inserted into the queue, its frequency is incremented by one in the temp_map.

// int findFrequency(queue<int> &q, int k): This function takes two parameters, a reference to a queue of integers q and an integer k.
// It looks up the frequency of the integer k in the temp_map. If the frequency is zero, it means that the integer k has not been inserted into the queue or has been removed from the queue.
// In this case, the function returns -1 to indicate that the frequency of k is not available.
// Otherwise, if the frequency is greater than zero, it means that k has been inserted into the queue at least once, and the function returns the frequency value stored in the temp_map.

// In simple terms, this code allows you to insert integers into a queue and find the frequency of a specific integer in the queue.
// The frequency is updated and stored in the temp_map each time an integer is inserted.
// The findFrequency function retrieves the frequency from the temp_map if the integer is present in the queue, and returns -1 if the integer is not found in the queue.

// .
// ================= CODE ==================>>>>>>>
// .

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
//  Helper class Solution to implement
//  insert() and findFrequency()
class Solution
{
public:
    unordered_map<int, int> temp_map;
    void insert(queue<int> &q, int k)
    {
        temp_map[k]++;
    }
    int findFrequency(queue<int> &q, int k)
    {
        if (temp_map[k] == 0)
            return -1;

        return temp_map[k];
    }
};

int main()
{

    int testcase;
    cin >> testcase;

    while (testcase-- > 0)
    {
        // Declaring Queue
        queue<int> q;
        int n, k;
        cin >> n;

        Solution obj;

        for (int i = 0; i < n; i++)
        {
            cin >> k;
            obj.insert(q, k);
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> k;
            int f = obj.findFrequency(q, k);
            if (f != 0)
            {
                cout << f << endl;
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    return 0;
}
