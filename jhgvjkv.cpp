#include <iostream>
using namespace std;

const int N = 4;

int isUpperTriangular(int mat[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && mat[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (isUpperTriangular(arr, n))
    {
        cout << "Matrix is an upper triangular matrix" << endl;
    }
    else
    {
        cout << "Matrix is not an upper triangular matrix" << endl;
    }
    return 0;
}
