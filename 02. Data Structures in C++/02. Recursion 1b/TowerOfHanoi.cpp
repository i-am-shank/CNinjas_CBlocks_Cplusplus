// TIme Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) {
        return;
    }
    if (n == 1) {
        cout << source << ' ' << destination << endl;
        return;
    }
    towerOfHanoi(n-1, source, destination, auxiliary);
    cout << source << ' ' << destination << endl;
    towerOfHanoi(n-1, auxiliary, source, destination);
    return;
}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}