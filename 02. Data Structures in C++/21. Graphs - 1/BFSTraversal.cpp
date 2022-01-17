#include <iostream>
#include <queue>
using namespace std;

void BFS(int **edges, int n, int sv, bool* visited) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front << " ";
        // visited[front] = true;  .NO.  Visited only when inserted to queue 1st time.
        // Else all connections of the vertex, in queue before, will push same element.
        for(int i=0; i<n; i++) {
            if(i == front) {
                continue;
            }
            if(edges[front][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void printBFS(int **edges, int n) {
    bool *visited = new bool [n];
    for(int i=0; i<n; i++) {
        visited[i] = false;
    }
    for(int i=0; i<n; i++) {
        if(visited[i] != true) {
            BFS(edges, n, i, visited);
        }
    }
    cout << endl;
    delete []visited;
    return;
}

int main() {
    int v, e;
    cin >> v >> e;
    int ** adjacencyMatrix = new int* [v];
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
    printBFS(adjacencyMatrix, v);
    for(int i=0; i<v; i++) {
        delete []adjacencyMatrix[i];
    }
    delete []adjacencyMatrix;
    return 0;
}