#include <iostream>
using namespace std;
void sortedArray(int *arr, int n)
{
    // base case
    if (n == 0 || n == 1)
        return;

    // 1 case solve kar lia
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    sortedArray(arr, n - 1);
}
int main()
{
    int n;
    cout << "Enter the number of element in the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the element in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sortedArray(arr, n);
    cout << "After Sorting Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}