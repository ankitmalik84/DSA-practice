#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = arr[mid];
        if (element == target)
        {
            return mid;
        }
        else if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            start = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int size = 8;
    int target = 8;
    int output = binarySearch(arr, size, target);
    if (output != -1)
    {
        cout << "Target found " << output << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }
    return 0;
}
