#include <iostream>
#include <string>
using namespace std;

int lcs_help(string s1, int n, string s2, int m, int** arr) {
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(s1[i-1] == s2[j-1]) {
                arr[i][j] = 1 + arr[i-1][j-1];
            }
            else {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    return arr[n][m];
}

int lcs(string s1, int n, string s2, int m) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[m+1];
        for(int j=0; j<m+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;
            }
        }
    }
    int ans = lcs_help(s1, n, s2, m, arr);
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
    string s2;
    for(int i=n-1; i>=0; i--) {
        s2.push_back(s[i]);
    }
    int length_lps = lcs(s, n, s2, n); // No. of insertion to make palindrome = No. of
    int minInsertion = n - length_lps; //   deletion to make palindrome.
    cout << minInsertion << endl;
    return 0;
}