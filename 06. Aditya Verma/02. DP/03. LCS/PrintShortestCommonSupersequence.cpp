#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string s1, int n, string s2, int m, int** arr) {
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(s1[i-1] == s2[j-1]) {
                arr[i][j] = 1 + arr[i-1][j-1];
            }
            else {
                arr[i][j]  =  max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    return arr[n][m];
}

void printSCS(string s1, int n, string s2, int m) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[m+1];
        for(int j=0; j<m+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;
            }
        }
    }
    int length = lcs(s1, n, s2, m, arr);
    int i=n, j=m;
    string ans;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if(arr[i][j-1] > arr[i-1][j]) {
                ans.push_back(s2[j-1]);
                j--;
            }
            else {
                ans.push_back(s1[i-1]);
                i--;
            }
        }
    }
    while(i > 0) {  // 2nd string becomes empty.. add remaining characters of 1st string
        ans.push_back(s1[i-1]);  // Supersequence of a random string & an empty string..
        i--;                     //   is the Random string.
    }
    while(j > 0) {  // 1st string becomes empty..
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
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
    printSCS(s1, n, s2, m);
    return 0;
}