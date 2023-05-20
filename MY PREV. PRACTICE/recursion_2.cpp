#include <iostream>
#include <vector>
using namespace std;
void printarr(int arr[], int size, int index)
{
    if (index == size)
    {
        return;
    }
    // printarr(arr, size, index + 1);
    cout << arr[index] << " ";

    printarr(arr, size, index + 1);
}
int main()
{
    int arr[] = {1, 3, 4, 5, 6};
    int size = 5;
    printarr(arr, size, 0);
    cout << endl;
    return 0;
}