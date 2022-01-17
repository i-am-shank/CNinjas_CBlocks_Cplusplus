#include <iostream>
using namespace std;

void DFS(int **edges, int n, int sv, bool *visited) {
    cout << sv << " ";
    visited[sv] = true;
    for(int i=0; i<n; i++) {
        if(sv == i) {
            continue;
        }
        if(edges[sv][i] == 1) {
            if(visited[i]) {
                continue;
            }
            DFS(edges, n, i, visited);
        }
    }
    return;
}

void printDFS(int **edges, int n) {
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) {
        visited[i] = false;
    }
    for(int i=0; i<n; i++) {
        if(visited[i] != true) {
            DFS(edges, n, i, visited);
        }
    }
    cout << endl;
    delete []visited;
    return;
}

int main() {
    int v, e;
    cin >> v >> e;
    int **adjacencyMatrix = new int* [e];
    for(int i=0; i<v; i++) {
        adjacencyMatrix[i] = new int[v];
        for(int j=0; j<v; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyMatrix[a][b] = 1;
        adjacencyMatrix[b][a] = 1;
    }
    printDFS(adjacencyMatrix, v);
    for(int i=0; i<v; i++) {
        delete []adjacencyMatrix[i];
    }
    delete []adjacencyMatrix;
    return 0;
}