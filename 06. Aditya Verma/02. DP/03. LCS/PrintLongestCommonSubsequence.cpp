#include <iostream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence_help(string s1, int n, string s2, int m, int** arr) {
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(s1[i-1] == s2[j-1]) {
                arr[i][j] = 1 + arr[i-1][j-1];
            }
            else {
                arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);
            }
        }
    }
    return arr[n][m];
}

void printLCS(string s1, int n, string s2, int m) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[m+1];
        for(int j=0; j<m+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;
            }
        }
    }
    int ans_length = longestSubsequence_help(s1, n, s2, m, arr);
    int i=n, j=m;
    string ans;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if(arr[i-1][j] > arr[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    reverse (ans.begin(), ans.end());
    cout << ans << endl;
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    printLCS(s1, n, s2, m);
    return 0;
}