// Time Complexity = O(n)
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    int n,c,ans;
    cin >> n >> c;
    if (c == 1){
        ans = 0;
        for (int i=1; i<=n; i++){
            ans += i;
        }
    }
    else if (c == 2){
        ans = 1;
        for (int i=1; i<=n; i++){
            ans *= i;
        }
    }
    else{
        ans = -1;
    }
    cout << ans << endl;
}