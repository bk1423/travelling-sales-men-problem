#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5 // number of cities

// adjacency matrix representing the distances between cities
int adj_matrix[N][N] = {
    {0, 10, 15, 20, 30},
    {10, 0, 35, 25, 20},
    {15, 35, 0, 30, 25},
    {20, 25, 30, 0, 10},
    {30, 20, 25, 10, 0}
};

// array to keep track of visited cities
int visited[N];

// function to find the nearest unvisited city
int find_nearest(int city) {
    int nearest = -1;
    int min_dist = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && adj_matrix[city][i] < min_dist) {
            nearest = i;
            min_dist = adj_matrix[city][i];
        }
    }
    return nearest;
}

// function to find the shortest tour using the nearest neighbor algorithm
void tsp_nearest_neighbor() {
    int tour[N+1]; // array to store the tour
    int start_city = rand() % N; // start at a random city
    int current_city = start_city;
    visited[current_city] = 1;
    tour[0] = start_city;
    for (int i = 1; i < N; i++) {
        int nearest_city = find_nearest(current_city);
        visited[nearest_city] = 1;
        tour[i] = nearest_city;
        current_city = nearest_city;
    }
    tour[N] = start_city; // return to starting city to complete the tour
    int tour_length = 0;
    for (int i = 0; i < N; i++) {
        tour_length += adj_matrix[tour[i]][tour[i+1]];
    }
    printf("Shortest tour length: %d\n", tour_length);
    printf("Tour: ");
    for (int i = 0; i <= N; i++) {
        printf("%d ", tour[i]);
    }
    printf("\n");
}

int main() {
    srand(123); // set random seed
    tsp_nearest_neighbor();
    return 0;
}
