#include <iostream>
// wrong code not working state
#include <queue>
void BFS(int edge[][], int n)
{
    n = sizeof(edge) / sizeof(edge[0]);
    bool visited[n];
    printBFShelper(edge, 0, visited);
}
void printBFShelper(int *edge, int sv, bool visited[])
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
}
using namespace std;
int main()
{
    int n, e, fv, sv;
    cin >> n >> e;
    int edge[n][n];
    for (int i = 0; i < e; i++)
    {
        cin >> fv;
        cin >> sv;
        edge[fv][sv] = 1;
        edge[sv][fv] = 1;
    }
    BFS(edge, n);

    return 0;
}