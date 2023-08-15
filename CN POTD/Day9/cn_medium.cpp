#include <bits/stdc++.h>
using namespace std; // Don't forget this line!

struct Pair {
    bool found;
    int value;
};

Pair ex(int n, int m, vector<vector<int>>& mat, int i, int j, int x, int y, vector<vector<bool>>& vis) {
    if (i == x && j == y) {
        Pair p = {true, 0};
        return p;
    }
    if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 0 || vis[i][j]) {
        Pair p = {false, INT_MAX};
        return p;
    }

    vis[i][j] = true;
    int res = INT_MIN;

    Pair sol = ex(n, m, mat, i, j - 1, x, y, vis);
    if (sol.found) res = max(res, sol.value);

    sol = ex(n, m, mat, i, j + 1, x, y, vis);
    if (sol.found) res = max(res, sol.value);

    sol = ex(n, m, mat, i - 1, j, x, y, vis);
    if (sol.found) res = max(res, sol.value);

    sol = ex(n, m, mat, i + 1, j, x, y, vis);
    if (sol.found) res = max(res, sol.value);

    vis[i][j] = false;

    if (res != INT_MIN) {
        Pair p = {true, 1 + res};
        return p;
    } else {
        Pair p = {false, INT_MAX};
        return p;
    }
}

int longestPath(int n, int m, vector<vector<int>>& mat, int sx, int sy, int dx, int dy) {
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    Pair p = ex(n, m, mat, sx, sy, dx, dy, vis);

    if (p.found)
        return p.value;
    else
        return -1;
}
