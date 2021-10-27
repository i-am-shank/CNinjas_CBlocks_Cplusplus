// Time Complexity = O(n)
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    int n, i=0;
    cin >> n;
    if(n==1 || n==0){
        i = n;
    }
    else{
        while ((i * i <= n) && (i <= n/2)){
            i++;
        }
        i--;
    }
    cout << i << endl;
}