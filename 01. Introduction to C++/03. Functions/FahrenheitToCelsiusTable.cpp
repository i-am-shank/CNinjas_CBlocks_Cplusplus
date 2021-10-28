// Time Complexity = O(n)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

void printTable(int start, int end, int step){
    float c;
    for(int i=start; i<=end; i+=step){
        c = ((5 * (i-32)) / 9);
        cout << i << " " << c << endl;
    }
    return;
}

int main(){
    int start, end, step;
    cin >> start >> end >> step;
    printTable(start, end, step);
}