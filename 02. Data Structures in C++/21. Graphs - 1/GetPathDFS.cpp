#include <iostream>
#include <vector>
using namespace std;

vector<int>* getPathDFSHelp(int **edges, int n, int start, int target, bool* visited) {
    if(start == target) {
        vector<int>* output = new vector<int> ();
        output->push_back(start);
        return output;
    }
    visited[start] = true;
    for(int i=0; i<n; i++) {
        if(edges[start][i] == 1) {
            if(!visited[i] && start != i) {
                vector<int>* smallAns = getPathDFSHelp(edges, n, i, target, visited);
                if(smallAns != NULL) {
                    smallAns->push_back(start);
                    return smallAns;
                }
            }
        }
    }
    return NULL;
}

vector<int>* getPathDFS(int **edges, int n, int start, int target) {
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) {
        visited[n] = false;
    }
    vector<int>* ans = getPathDFSHelp(edges, n, start, target, visited);
    delete []visited;
    return ans;
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
    int v1, v2;
    cin >> v1 >> v2;
    vector<int>* ans = getPathDFS(adjacencyMatrix, v, v1, v2);
    if(ans != NULL) {
        for(int i=0; i<ans->size(); i++) {
            cout << ans->at(i) << " ";
        }
        cout << endl;
    }
    for(int i=0; i<v; i++) {
        delete []adjacencyMatrix[i];
    }
    delete []adjacencyMatrix;
    return 0;
}