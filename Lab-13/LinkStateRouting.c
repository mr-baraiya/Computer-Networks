#include <stdio.h>
#define INF 999

int n;
int cost[50][50];

// Function to find shortest path from source to all other vertices
void dijkstra(int source) {
    int dist[50], visited[50], nextHop[50];
    int i, j, count, minDist, u;

    // Initialization
    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
        if (cost[source][i] != INF && source != i)
            nextHop[i] = i;  // direct path
        else
            nextHop[i] = -1; // no direct path
    }
    dist[source] = 0;
    visited[source] = 1;

    // Dijkstra's Algorithm
    for (count = 1; count < n - 1; count++) {
        minDist = INF;
        u = -1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break; // No reachable vertex left
        visited[u] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[u] + cost[u][i] < dist[i]) {
                dist[i] = dist[u] + cost[u][i];
                nextHop[i] = nextHop[u];
            }
        }
    }
    // Print routing table for this router
    printf("\nRouting Table for Router %d:\n", source + 1);
    printf("Dest\tNextHop\tCost\n");
    for (i = 0; i < n; i++) {
        if (i != source) {
            printf("%d\t", i + 1);
            if (nextHop[i] != -1)
                printf("%d\t", nextHop[i] + 1);
            else
                printf("-\t");
            if (dist[i] != INF)
                printf("%d\n", dist[i]);
            else
                printf("INF\n");
        }
    }
}
int main() {
    int i, j;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no link):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    // Run Dijkstra for each router
    for (i = 0; i < n; i++) {
        dijkstra(i);
    }
    return 0;
}
