#include <iostream>
using namespace std;

int staircase(int n) {
    if(n<3 && n>0) {
        return n;
    }
    if(n == 3) {
        return 4;
    }
    int smallAns1 = staircase(n-1);
    int smallAns2 = staircase(n-2);
    int smallAns3 = staircase(n-3);
    return smallAns1 + smallAns2 + smallAns3;
}

int main() {
    int n, ans;
    cin >> n;
    ans = staircase(n);
    cout << ans << endl;
    return 0;
}