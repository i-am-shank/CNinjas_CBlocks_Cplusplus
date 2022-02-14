#include <iostream>
#include <vector>
using namespace std;

// Shoelace-formula
float AreaOfPolygon(int* x, int* y, int sides) {
    float ans = 0.0;
    int j = sides - 1;
    for(int i=0; i<sides ; i++) {
        ans +=  ((x[j] + y[j])  *  (y[j] - y[i]));
        j = i;
    }
    return abs(ans / 2.0);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        int* x_vertex = new int[n];
        int* y_vertex = new int[n];
        for(int i=0; i<n; i++) {
            cin >> x_vertex[i] >> y_vertex[i];
        }
        
    }
}