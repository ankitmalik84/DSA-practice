#include <iostream>
using namespace std;
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
int intInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
    int main()
    {
        int arr[100] = {2, 3, 56, 45};
        int size = 4, element = 45, index = 3;
        display(arr, size);
        intInsertion(arr, size, element, 100, index);
        size += 1;
        display(arr, size);
    return 0;
}