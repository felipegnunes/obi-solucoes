// Dijkstra

#include <iostream>
#include <limits.h>

using namespace std;

int find_nearest_vertex(int V, int dist[], bool in_tree[])
{
    int min_index, min_dist = INT_MAX;

    for (int u = 0; u < V; u++)
    {
        if (!in_tree[u] && dist[u] < min_dist)
        {
            min_index = u;
            min_dist = dist[u];
        }
    }

    return min_index;
}

void dijkstra(int V, int E, int source, int **adj, int dist[])
{
    bool in_tree[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        in_tree[i] = false;
    }

    dist[source] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = find_nearest_vertex(V, dist, in_tree);
        in_tree[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] && !in_tree[v] && dist[u] != INT_MAX && dist[v] > dist[u] + adj[u][v])
                dist[v] = dist[u] + adj[u][v];
        }
    }
}

int main()
{
    int V, E, source;

    cin >> V >> E;

    int **adj = new int *[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = new int[V];
    }

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++)
    {
        int u, v, p;
        cin >> u >> v >> p;
        u--;
        v--;
        adj[u][v] = adj[v][u] = p;
    }

    cin >> source;
    source--;

    int dist[V];
    dijkstra(V, E, source, adj, dist);

    int min_dist = INT_MAX, max_dist = -1;
    for (int u = 0; u < V; u++)
    {
        if (dist[u] < min_dist && u != source)
            min_dist = dist[u];

        max_dist = max(max_dist, dist[u]);
    }
    cout << max_dist - min_dist << endl;
}