#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited, int *weight, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((minVertex == -1) || weight[minVertex] < weight[i]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void primes(int **edges, int v)
{
    bool *visited = new bool[v];
    int *parent = new int[v];
    int *weight = new int[v];
    for (int i = 0; i < v; i++)
    {
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        // Get minVErtex i.e unvisited vertex with minimum weight
        int minVertex = getMinVertex(visited, weight, v);
        visited[minVertex] = true;

        // Explore all the neighbours of minimum vertex and update parent and weight array according to that

        for (int j = 0; j < v; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (weight[j] > edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < v; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
    delete[] parent;
    delete[] visited;
    delete[] weight;
}
int main()
{
    int v;
    int e;
    cin >> v >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout << endl;
    primes(edges, v);

    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}