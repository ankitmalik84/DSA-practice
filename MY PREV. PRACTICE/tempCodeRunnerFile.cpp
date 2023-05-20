#include <stdio.h>

int main()
{
    int n, j;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i > j && arr[i][j] != 0)
            {
                printf("0");
                break;
            }
        }
        if (j != n - 1)
        {
            break;
        }
    }
    printf("1");
    return 0;
}