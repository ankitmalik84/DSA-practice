#include <stdio.h>
#define N 3

int isUpperTriangular(int mat[N][N]) {
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
if (i > j && mat[i][j] != 0) {
return 0;
}
}
}
return 1;
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i])
        }
    }
int mat[N][N] = {{1, 2, 3}, {0, 5, 6}, {0, 0, 9}};
if (isUpperTriangular(mat)) {
return 1;
} else {
return 0;
}
return 0;
}