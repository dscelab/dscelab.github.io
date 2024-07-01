#include <stdio.h>
#include <limits.h>

#define MAX 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyds(int cost[MAX][MAX], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX)
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main() {
    int n, cost[MAX][MAX], i, j;

    printf("Enter the number of vertices of the graph\n");
    scanf("%d", &n);

    printf("Enter the cost matrix of the graph (use %d for infinity)\n", INT_MAX);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    floyds(cost, n);

    printf("The following matrix shows the shortest distances between every pair of vertices\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", cost[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
