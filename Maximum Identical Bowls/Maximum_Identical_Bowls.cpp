// ==================================================== CODE INFINITY ===============================================================

// Maximum Identical Bowls
// EasyAccuracy: 54.52%Submissions: 21K+Points: 2
// Finding A Job Is Now Easier Than Today's Problem! Explore Job Fair 2023

// There are N bowls containing cookies. In one operation, you can take one cookie from any of the non-empty bowls and put it into another bowl. If the bowl becomes empty you discard it. You can perform the above operation any number of times. You want to know the maximum number of bowls you can have with an identical number of cookies.

// Note: All the non-discarded bowls should contain the identical number of cookies.

// Example 1:

// Input:
// N = 3
// arr[] = {3, 1, 5}
// Output: 3
// Explanation: We can put 2 cookies from the 3rd bowl
// and put them into the 2nd bowl.Now the array
// becomes {3, 3, 3}. Each bowl now contains 3 cookies.

// =======================APPROACH===================>>>>>>>>>>
// 1. The code initializes a variable called sum with the value of 0. This variable will be used to calculate the sum of all elements in the vector arr.

// 2. The code then enters a loop that iterates over each element in the vector arr. For each element, it adds its value to the sum variable.

// 3. After calculating the sum of all elements in the vector, the code enters another loop that continues as long as the value of N is not zero. This loop will gradually decrease the value of N by 1 in each iteration.

// 4. Inside the loop, the code checks if the remainder of the division sum % N is equal to zero. In other words, it checks if sum is divisible evenly by N. If it is, it means that N is a factor of the sum, and it returns the current value of N as the maximum value.

// 5. If the remainder is not zero, the code continues to the next iteration of the loop, decreasing the value of N by 1.

// 6. If the loop finishes without finding a factor of sum, it means that no value of N exists such that the sum of arr is divisible by N. In this case, the code returns the value of N as 0.

// In summary, this code finds the maximum value of N such that the sum of all elements in the vector arr is divisible by N. It iterates over decreasing values of N and checks if the sum is divisible by each value until it finds a factor or reaches 0.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution
{
public:
    int getMaximum(int N, vector<int> &arr)
    {

        long long int sum = 0;
        for (auto i : arr)
        {
            sum += i;
        }

        while (N)
        {
            if (sum % N == 0)
                return N;
            N--;
        }
        return N;
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> arr(N);
        Array::input(arr, N);

        Solution obj;
        int res = obj.getMaximum(N, arr);

        cout << res << endl;
    }
}
