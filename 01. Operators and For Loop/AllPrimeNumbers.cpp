// Time Complexity = O(n^2)
// Space Complexity = O(n)

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n==1){
        return 0;
    }
    else{
        for (int i=2; i<=n; i++){
            bool flag = true;
            for (int j=2; j<=(i/2); j++){
                if (i%j == 0){
                    flag = false;
                    break;
                }
            }
            if (flag == true){
                cout << i << endl;
            }
        }
    }
}