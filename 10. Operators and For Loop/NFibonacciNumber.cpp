// Time Complexity = O(n)
// Space Complexity = O(1)

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n==1 || n==2){
        int ans = 1;
        cout << ans << endl;
    }
    else{
        int a = 1, b=1, c;
        for (int i=1; i<=(n-2); i++){
            c = a+b;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
}