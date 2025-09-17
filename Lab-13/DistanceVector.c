#include <stdio.h>
#define INF 999
int dist[50][50], temp[50][50], n;
void dvr() {
    int i, j, k;
    // Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    temp[i][j] = temp[i][k];
                }
            }
        }
    }
    // Print routing table
    for (i = 0; i < n; i++) {
        printf("\n\nState value for router %d is:\n", i + 1);
        for (j = 0; j < n; j++) {
            printf("Node %d via %d Distance %d\n", j + 1, temp[i][j] + 1, dist[i][j]);
        }
    }
    printf("\n");
}
int main() {
    int i, j, x;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the distance matrix (use 999 for no link):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            temp[i][j] = j;
        }
    }

    // Set diagonal elements to 0
    for (i = 0; i < n; i++)
        dist[i][i] = 0;

    // First computation
    dvr();

    // Update cost
    printf("Enter i and j for cost update: ");
    scanf("%d %d", &i, &j);
    printf("Enter new cost: ");
    scanf("%d", &x);

    dist[i][j] = x;
    printf("After update:\n");
    dvr();

    return 0;
}
