#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int dest;
    int weight;
};
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
int getParent(int v, int *parent)
{
    // agar parent ka element parent k bara bar h toh vo top most element hoga-------------->
    if (parent[v] == v)
    {
        return v;
    }
    return getParent(parent[v], parent);
}
Edge *kruskals(Edge *edges, int v, int e)
{
    // Sorted the edges array in increasing order--------->
    sort(edges, edges + e, compare);

    Edge *output = new Edge[v - 1];
    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    while (count < (v - 1))
    {
        // check the topmost parent of v1 and v2. v1 and v2 are vertices of current edge
        Edge currentEdge = edges[i];
        int srcParent = getParent(currentEdge.src, parent);
        int destParent = getParent(currentEdge.dest, parent);

        if (srcParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[srcParent] = destParent;
        }
        i++;
    }
    return output;
}

int main()
{
    int v, e;
    cin >> v >> e;
    Edge *edges = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edges[i].src = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }
    Edge *output = kruskals(edges, v, e);
    for (int i = 0; i < v - 1; i++)
    {
        if (output[i].src < output[i].dest)
        {
            cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
        }
    }
    return 0;
}