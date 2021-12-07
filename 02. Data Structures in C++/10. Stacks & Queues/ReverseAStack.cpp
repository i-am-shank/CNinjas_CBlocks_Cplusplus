// Time Complexity = O(N^2)
// Space Complexity = O(N)


#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()==0 || input.size()==1) {
        return;
    }
    int temp = input.top();
    input.pop();
    reverseStack(input, extra);
    while(input.empty() != true) {
        extra.push(input.top());
        input.pop();
    }
    input.push(temp);
    while(extra.empty() != true) {
        input.push(extra.top());
        extra.pop();
    }
    return;
}

int main() {
    stack <int> input;
    stack <int> extra;
    int size;
    cin >> size;
    for (int i=0; i<size; i++) {
        int data;
        cin >> data;
        input.push(data);
    }
    reverseStack(input, extra);
    for(int i=0; i<size; i++) {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
    return 0;
}