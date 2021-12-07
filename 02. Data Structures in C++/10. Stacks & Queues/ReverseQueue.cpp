// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &input) {
    if(input.size()==0 || input.size()==1) {
        return;
    }
    int temp = input.front();
    input.pop();
    reverseQueue(input);
    input.push(temp);
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int size;
        cin >> size;
        queue <int> input;
        for(int i=0; i<size; i++) {
            int data;
            cin >> data;
            input.push(data);
        }
        reverseQueue(input);
        for(int i=0; i<size; i++) {
            cout << input.front() << " ";
            input.pop();
        }
        cout << endl;
    }
    return 0;
}