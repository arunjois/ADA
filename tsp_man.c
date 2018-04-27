#include "stdio.h"

int n = 6, totalDistance = 0;
int path[20], rear = 0, min, temp[20], s, visited[20], firstVertex,cost_matrix[20][20];

/*
int cost_matrix[5][5] = {{0,  3,  6,  17, 2},
                         {3,  0,  12, 15, 13},
                         {6,  12, 0,  11, 14},
                         {17, 15, 11, 0,  5},
                         {2,  13, 14, 5,  0}};


int cost_matrix[4][4] = {{0, 1, 3, 6},
                         {1, 0, 2, 3},
                         {3, 2, 0, 1},
                         {6, 3, 1, 0}};




int cost_matrix[6][6] = {{0,  58, 37, 57, 49, 34},
                         {58, 0,  44, 17, 53, 36},
                         {37, 44, 0,  45, 48, 50},
                         {57, 17, 45, 0,  6,  5},
                         {49, 53, 48, 6,  0,  24},
                         {34, 36, 50, 5,  24, 0}};
*/
int min_value(int a, int b) {
    min = a < b ? a : b;
    return min;
}

void tsp() {
    int i = 0, j = 0, rowCounter = 0;
    visited[i] = 1;
    firstVertex = 0;
    path[rear++] = i;
    printf("\n Values selected: ");
    while (i < n && rowCounter < n) {
        j = 0;
        min = 9999;
        s = 0;
        while (j < n) {
            if (i != j && !visited[j]) {
                temp[s++] = min_value(cost_matrix[j][i], min);
            } else {
                temp[s++] = -1;
            }
            j++;
        }
        for (s = 0; s < n; ++s) {
            if (temp[s] == min) {
                printf(" %d ",min);
                i = s;
                totalDistance+=min;
                path[rear++] = s;
                visited[i] = 1;
                break;
            }
        }
        if (rowCounter + 1 == n) {
            printf(" %d ",cost_matrix[firstVertex][i]);
            totalDistance+=cost_matrix[firstVertex][i];
            path[rear] = firstVertex;
        }
        rowCounter++;
    }

}

//driver function to display
void displayMatrix() {
    int i, j;
    for (i = 0; i < n; ++i) {
        visited[i] = 0;
        for (j = 0; j < n; ++j) {
            printf(" %d ", cost_matrix[i][j]);
        }
        printf("\n");
    }
}

//driver function to display visited nodes (boolean value) optional
void printVisited() {
    int i;
    printf("\nVisited: ");
    for (i = 0; i < n; ++i) {
        printf(" %d ", visited[i]);
    }
    printf("\n");
}

void printPathInDigit() {
    int i;
    printf("\nTotal Distance: %d",totalDistance);
    printf("\nPath: ");
    for (i = 0; i <= n; ++i) {
        printf(" %d ", path[i]);
    }
    printPathInAlphabet();
}

void printPathInAlphabet() {
    int i;
    printf("\nPath: ");
    for (i = 0; i <= n; ++i) {
        if (i != n)
            printf(" %c ->", path[i] + 65);
        else
            printf(" %c ", path[i] + 65);
    }

}

int main() {
    


   // Remove comment for manual input
    int i, j,sv;
    printf("\n Input number of objects: ");
    scanf("%d", &n);
    printf("\n Input matrix: \n");
    for (i = 1; i <= n; ++i) {
        visited[i] = 0;
        for (j = 1; j <= n; ++j) {
            scanf("%d", &cost_matrix[i][j]);
        }
    }
    printf("\n Input starting vertex: ");
    scanf("%d",&s);

    

    displayMatrix();
    tsp();
    printPathInDigit();

    return 0;
}

