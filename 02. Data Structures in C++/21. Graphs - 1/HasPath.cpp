#include <iostream>
#include <queue>
using namespace std;

// BFS approach

bool hasPathBFSHelp(int **edges, int n, int start, int target, int *visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        if(front == target) {
            return true;
        }
        for(int i=0; i<n; i++) {
            if(edges[front][i] == 1) {
                if(!visited[i] && front != i) {
                    q.push(i);
                    visited[i] = true;
                    if(i == target) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool hasPathBFS(int **edges, int n, int start, int target) {
    int *visited = new int[n];
    for(int i=0; i<n; i++) {
        visited[i] = false;
    }
    bool ans = hasPathBFSHelp(edges, n, start, target, visited);
    delete []visited;
    return ans;
}

// DFS approach

bool hasPathHelp(int **edges, int n, int start, int target, bool* visited) {
    visited[start] = true;
    if(start == target) {
        return true;
    }
    for(int i=0; i<n; i++) {
        if(edges[start][i] == 1) {
            if(visited[i] == true || start == i) {
                continue;
            }
            bool temp = hasPathHelp(edges, n, i, target, visited);
            if(temp == true) {
                return true;
            }
        }
    }
    return false;
}

bool hasPath(int **edges, int n, int start, int target) {
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) {
        visited[i] = false;
    }
    bool ans = hasPathHelp(edges, n, start, target, visited);
    delete []visited;
    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    int **adjacencyMatrix = new int* [v];
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
    int v1, v2;
    cin >> v1 >> v2;
    bool ans1 = hasPath(adjacencyMatrix, v, v1, v2);
    bool ans2 = hasPathBFS(adjacencyMatrix, v, v1, v2);
    cout << (ans1==true ? "true" : "false") << endl;
    cout << (ans2==true ? "true" : "false") << endl;
    for(int i=0; i<v; i++) {
        delete []adjacencyMatrix[i];
    }
    delete []adjacencyMatrix;
    return 0;
}