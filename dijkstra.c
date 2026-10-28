
#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

// Find the unvisited vertex with minimum distance
int minDistance(int dist[], int visited[], int vertices)
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v] && dist[v] < min)
        {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Print shortest distances from source
void printSolution(int dist[], int vertices)
{
    printf("\nVertex\tDistance from Source\n");

    for (int i = 0; i < vertices; i++)
    {
        if (dist[i] == INT_MAX)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES],
              int src, int vertices)
{
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    // Initialize distances
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 0; count < vertices; count++)
    {
        int u = minDistance(dist, visited, vertices);

        // No reachable unvisited vertex remains
        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] &&
                graph[u][v] > 0 &&
                dist[u] != INT_MAX &&
                dist[u] <= INT_MAX - graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, vertices);
}

int main()
{
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int source;

    printf("Enter the number of vertices: ");

    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    printf("(Use 0 to represent no edge)\n");

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
       }
    }

    printf("Enter the source vertex (0 to %d): ",vertices - 1);

    scanf("%d", &source);

    dijkstra(graph, source, vertices);

    return 0;
}
