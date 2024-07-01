#include <stdio.h>

#define MAX 10

void warshall(int cost[MAX][MAX], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cost[i][j] = cost[i][j] || (cost[i][k] && cost[k][j]);
            }
        }
    }
}

int main() {
    int n, cost[MAX][MAX], i, j;

    printf("Enter the number of vertices of the graph\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph (0 for no edge, 1 for edge)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    warshall(cost, n);

    printf("The transitive closure of the given graph is\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}