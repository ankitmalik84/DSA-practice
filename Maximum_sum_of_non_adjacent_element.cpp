#include <iostream>
#include <vector>

using namespace std;
void solve(vector<int> &arr, int sum, int &maxi, int i)
{
    if (i >= arr.size())
    {
        maxi = max(maxi, sum);
        return;
    }
    // include the current element
    solve(arr, sum + arr[i], maxi, i + 2);
    // exclude the current element
    solve(arr, sum, maxi, i + 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxi = 0;
    solve(arr, 0, maxi, 0);
    cout << maxi << endl;
    return 0;
}