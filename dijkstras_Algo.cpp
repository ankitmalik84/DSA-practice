#include <bits/stdc++.h>
using namespace std;
int getMinVertex(int *dist, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    { // here yaha agar vo phela element hoga toh vo usse hi return kar dega otherwise check karega------------->
        if (!visited[i] && (minVertex == -1 || (dist[i] < dist[minVertex])))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges, int n)
{
    bool *visited = new bool[n]();
    int *dist = new int[n];
    // here we assign the maximum distance of every element of the graph--------------------->
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    // distance of first element is zero initially--------------------->
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // Get unvisited vertex with minimum distance
        int minVertex = getMinVertex(dist, visited, n);
        // minVertex ko visited mark kar denge -------------------->
        visited[minVertex] = true;
        // Explore all the neighbours of minVertex which are unvisited and update the distance array if required
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] && !visited[j])
            {
                int currD = dist[minVertex] + edges[minVertex][j];
                if (dist[j] > currD)
                {
                    dist[j] = currD;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    delete[] visited;
    delete[] dist;
}
int main()
{
    int v;
    int e;
    // Enter the number of edges and vertex-------------->
    cin >> v >> e;
    int **edges = new int *[v];
    // Here we intitalize matrix with zero--------------------->
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    // here we enter the edge with weight in the matrix---------------->
    for (int i = 0; i < e; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout << endl;
    dijkstra(edges, v);
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}