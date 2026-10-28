
#include <stdio.h>

int visited[10] = {0};
int cost[10][10], min, mincost = 0;

int prims(int num)
{
    int i, j, ne = 1, a = 0, b = 0;
    
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[0] = 1;

    while (ne < num)
    {
        min = 999;

        for (i = 0; i < num; i++)
        {
            if (visited[i] != 0)
            {
                for (j = 1; j < num; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == 999)
        {
            printf("\nGraph is disconnected. MST does not exist.\n");
            return -1;
        }

        printf("\nEdge %d: (%d - %d), cost: %d",
               ne++, a, b, min);

        mincost += min;
        visited[b] = 1;

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMinimum cost = %d\n", mincost);
    return mincost;
}

int main()
{
    int n, i, j;

    printf("\n\t\tPrim's Algorithm");
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n);

    return 0;
}
