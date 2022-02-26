#include <iostream>
#include <string>
using namespace std;

int lcs_condition(string s1, int n, string s2, int m, int** arr) {
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(s1[i-1] == s2[j-1]  &&  i != j) {
                arr[i][j] = 1 + arr[i-1][j-1];
            }
            else {
                arr[i][j]  =  max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    return arr[n][m];
}

int longestRepeatingSubsequence(string s, int n) {
    int **arr = new int* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[n+1];
        for(int j=0; j<n+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;
            }
        }
    }
    int ans = lcs_condition(s, n, s, n, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = longestRepeatingSubsequence(s, n);
    cout << ans << endl;
    return 0;
}