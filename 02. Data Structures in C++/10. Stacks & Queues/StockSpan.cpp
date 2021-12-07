// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <stack>
using namespace std;

int* stockSpan(int *price, int size) {
    int *span = new int[size];
    stack <int> s;
    for(int i=0; i<size; i++) {
        while(!s.empty()  &&  price[i] > price[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            span[i] = i+1;
        }
        else {
            span[i] = i-s.top();
        }
        s.push(i);
    }
    return span;
}

int main() {
    int size;
    cin >> size;
    int *price = new int[size];
    for (int i=0; i<size; i++) {
        cin >> price[i];
    }
    int *stockSpanArray = stockSpan(price, size);
    for(int i=0; i<size; i++) {
        cout << stockSpanArray[i] << " ";
    }
    cout << endl;
    delete []price;
    delete []stockSpanArray;
    return 0;
}