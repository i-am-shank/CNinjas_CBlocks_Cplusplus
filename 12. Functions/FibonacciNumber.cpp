// Time Complexity = O(n)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int fib_lessthan_n(int n){
    int a=0, b=1, c=0;
    while (c < n){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

bool checkMember(int n){
    if(fib_lessthan_n(n) == n) {
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    if(checkMember(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}