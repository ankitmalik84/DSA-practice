// ==================================================== CODE INFINITY ===============================================================
// Arranging the array
// MediumAccuracy: 37.41%Submissions: 50K+Points: 4
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// You are given an array of size N. Rearrange the given array in-place such that all the negative numbers occur before all non-negative numbers.
// (Maintain the order of all -ve and non-negative numbers as given in the original array).

// Example 1:

// Input:
// N = 4
// Arr[] = {-3, 3, -2, 2}
// Output:
// -3 -2 3 2
// Explanation:
// In the given array, negative numbers
// are -3, -2 and non-negative numbers are 3, 2.
// Example 2:

// Input:
// N = 4
// Arr[] = {-3, 1, 0, -2}
// Output:
// -3 -2 1 0
// Explanation:
// In the given array, negative numbers
// are -3, -2 and non-negative numbers are 1, 0.

// =======================APPROACH===================>>>>>>>>>>

// This code implements a function named Rearrange that takes an array arr and its size n as input. The purpose of the function is to rearrange the elements of the array in a specific way.

// Here's a step-by-step explanation of how the code works:

// It declares three stacks named a, b, and c, and a vector named v. These will be used to store and manipulate the elements of the array.

// The code loops through each element of the input array using a for loop.

// Inside the loop, if the current element is negative (less than zero), it pushes the element onto stack a. Otherwise, if the element is positive or zero, it pushes it onto stack b. This separates the negative and non-negative elements of the array into two different stacks.

// After the loop, the code starts processing the elements stored in stack a. It pops each element from stack a and appends it to the vector v. Since stack a stores the negative elements, the elements will be appended to v in the reverse order.

// The code then reverses the order of the elements stored in v using the reverse function from the <algorithm> library. This step is necessary because the negative elements were pushed onto v in reverse order.

// Next, the code processes the elements stored in stack b. It pops each element from stack b and pushes it onto stack c. Stack c is used to temporarily store the non-negative elements.

// Once all the elements from stack b have been transferred to stack c, the code proceeds to process the elements stored in stack c. It pops each element from stack c and appends it to the vector v. This ensures that the non-negative elements are added to v in the correct order.

// Finally, the code uses a for loop to update the original array arr with the rearranged elements stored in v. It assigns each element of v to the corresponding index in arr.

// In summary, this code separates the negative and non-negative elements of the input array into two separate stacks (a and b), rearranges them in a specific order, and then updates the original array with the rearranged elements.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void Rearrange(int arr[], int n)
    {
        vector<int> v;
        stack<int> a;
        stack<int> b;
        stack<int> c;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                a.push(arr[i]);
            else
                b.push(arr[i]);
        }
        while (!a.empty())
        {
            v.push_back(a.top());
            a.pop();
        }
        reverse(v.begin(), v.end());
        while (!b.empty())
        {
            c.push(b.top());
            b.pop();
        }
        while (!c.empty())
        {
            v.push_back(c.top());
            c.pop();
        }
        for (int i = 0; i < n; i++)
            arr[i] = v[i];
    }
};

void Rearrange(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long j = 0;
        Solution ob;
        ob.Rearrange(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
