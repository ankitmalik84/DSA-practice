// ==================================================== CODE INFINITY ===============================================================

// Topological sort
// MediumAccuracy: 56.52%Submissions: 147K+Points: 4
// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.
// Example 2:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 5, 4, 2, 1, 3, 0.

// =======================APPROACH===================>>>>>>>>>>

// 1. The dfs function is a helper function that performs a depth-first search starting from a given node. It takes four parameters:

// node: The current node being visited.
// vis: A boolean vector indicating whether a node has been visited or not.
// ans: A vector that will store the nodes in the topological order.
// adj: An array of vectors representing the adjacency list of the graph.
// 2. Inside the dfs function, we mark the current node as visited by setting the corresponding entry in the vis vector to true.

// 3. We iterate over all the neighbors of the current node using a range-based for loop: for(int x: adj[node]).

// 4. If a neighbor node x has not been visited (!vis[x]), we recursively call the dfs function with x as the new starting node. This ensures that we visit all the nodes reachable from the current node.

// 5. After visiting all the neighbors of the current node, we push the current node into the ans vector. This is done because we want the nodes to be added to the ans vector in the reverse order of when they finish their DFS traversal. The reason for this will become clear shortly.

// 6. The topoSort function is the main function that performs topological sorting. It takes two parameters:

// V: The total number of vertices in the graph.
// adj: An array of vectors representing the adjacency list of the graph.
// 7. It initializes a boolean vector vis of size V to keep track of visited nodes and creates an empty vector ans to store the nodes in topological order.

// 8. It iterates over all the nodes from 0 to V-1 using a for loop. For each unvisited node, it calls the dfs function to perform a DFS traversal starting from that node.

// 9. Finally, after all nodes have been visited and the ans vector contains all the nodes in reverse order of their finish times, we reverse the ans vector using the reverse function from the <algorithm> library. This gives us the nodes in the correct topological order.

// 10. The ans vector is then returned as the result of the topoSort function.

// In summary, this code uses a depth-first search approach to perform a topological sort on a directed graph. It starts from each unvisited node and explores its neighbors recursively until all nodes have been visited. The nodes are added to the ans vector in reverse order of their finish times, resulting in a topological ordering of the graph's vertices.

// ================= CODE ==================>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<bool> &vis, vector<int> &ans, vector<int> adj[])
    {
        vis[node] = true;
        for (int x : adj[node])
        {
            if (!vis[x])
            {
                dfs(x, vis, ans, adj);
            }
        }
        ans.push_back(node);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, ans, adj);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
