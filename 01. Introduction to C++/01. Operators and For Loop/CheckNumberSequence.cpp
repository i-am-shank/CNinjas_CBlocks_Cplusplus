// Time complexity = O(n)
// Space complexity = O(1)


#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    bool type;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    if (n==0 || n==1){
        cout << "true" << endl;
        return 0;
    }
    if (a[0] > a[1]){
        type = true;
    }
    else{
        type = false;
    }

    int j=0;
    if (type == true){
        while ((a[j] > a[j+1]) && (j < (n-1))){
            j++;
        }
        if (j == (n-1)){
            cout << "true" << endl;
        }
        else if (a[j] == a[j+1]){
            cout << "false" << endl;
        }
        else {
            while ((a[j] < a[j+1]) && (j < (n-1))){
                j++;
            }
            if (j == (n-1)){
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
    }
    else{
        while ((a[j] < a[j+1]) && (j < (n-1))){
            j++;
        }
        if (j == (n-1)){
            cout << "true" << endl;
        }
        else if (a[j] == a[j+1]){
            cout << "false" << endl;
        }
        else {
            while ((a[j] > a[j+1]) && (j < (n-1))){
                j++;
            }
            if (j == (n-1)){
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
    }
}