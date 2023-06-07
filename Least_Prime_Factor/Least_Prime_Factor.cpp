// ==================================================== CODE INFINITY ===============================================================

// Least Prime Factor
// EasyAccuracy: 51.45%Submissions: 26K+Points: 2
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// Given a number N, find the least prime factors for all numbers from 1 to N.  The least prime factor of an integer X is the smallest prime number that divides it.
// Note :

// 1 needs to be printed for 1.
// You need to return an array/vector/list of size N+1 and need to use 1-based indexing to store the answer for each number.
// Example 1:

// Input: N = 6
// Output: [0, 1, 2, 3, 2, 5, 2]
// Explanation: least prime factor of 1 = 1,
// least prime factor of 2 = 2,
// least prime factor of 3 = 3,
// least prime factor of 4 = 2,
// least prime factor of 5 = 5,
// least prime factor of 6 = 2.
// So answer is[1, 2, 3, 2, 5, 2].
// Example 2:

// Input: N = 4
// Output: [0, 1, 2, 3, 2]
// Explanation: least prime factor of 1 = 1,
// least prime factor of 2 = 2,
// least prime factor of 3 = 3,
// least prime factor of 4 = 2.
// So answer is[1, 2, 3, 2].

// =======================APPROACH===================>>>>>>>>>>

// This code is an implementation of the "Least Prime Factor" algorithm. The purpose of the algorithm is to find the smallest prime factor for each number in a given range.

// The function leastPrimeFactor takes an integer n as input and returns a vector of integers. This vector will contain the smallest prime factor for each number from 0 to n.

// The code initializes a vector named prime with size n+1 and initializes all elements to -1. This vector will store the smallest prime factor for each number.

// Next, the code sets prime[0] to 0 and prime[1] to 1, indicating that 0 and 1 are not prime numbers.

// Then, the code enters a loop that starts from 2 and goes up to n. For each number i in this range, it checks if prime[i] is equal to -1. If it is, it means that i is a prime number.

// Inside the inner loop, the code increments j by i in each iteration, starting from i. This loop is used to mark all the multiples of i in the prime vector.

// For each multiple j, if prime[j] is still -1, it means that j hasn't been marked by any previous prime factor. So, the code assigns i as the smallest prime factor for j by setting prime[j] to i.

// After the loops complete, the vector prime contains the smallest prime factor for each number from 0 to n. Finally, the function returns this vector.

// In simpler terms, the code finds the smallest prime factor for each number in the given range by using a sieve-like algorithm. It iterates through the numbers, starting from 2, and marks all their multiples as non-prime by storing their smallest prime factor. This process continues until all numbers in the range have been processed, resulting in a vector that stores the smallest prime factor for each number.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> leastPrimeFactor(int n)
    {

        vector<int> prime(n + 1, -1);
        prime[0] = 0;
        prime[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == -1)
            {
                for (int j = i; j <= n; j += i)
                {
                    if (prime[j] == -1)
                        prime[j] = i;
                }
            }
        }
        return prime;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.leastPrimeFactor(n);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
