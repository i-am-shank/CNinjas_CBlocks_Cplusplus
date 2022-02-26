#include <iostream>
#include <string>
using namespace std;

// Recursive
int longestSubsequence(string s1, int n, string s2, int m) {
    if(n==0 || m==0) {
        return 0;
    }
    if(s1[n-1] == s2[m-1]) {
        return 1 + longestSubsequence(s1, n-1, s2, m-1);
    }
    else {
        int choice1 = longestSubsequence(s1, n, s2, m-1);
        int choice2 = longestSubsequence(s1, n-1, s2, m);
        return max(choice1, choice2);
    }
}

// Memoization
int longestSubsequence_mem_help(string s1, int n, string s2, int m, int** arr) {
    if(arr[n][m] != -1) {
        return arr[n][m];
    }
    if(n==0 || m==0) {
        arr[n][m] = 0;
        return 0;
    }
    if(s1[n-1] == s2[m-1]) {  // Last character common..  + 1
        arr[n][m] = 1 + longestSubsequence(s1, n-1, s2, m-1);
        return arr[n][m];
    }
    else {
        int choice1 = longestSubsequence(s1, n, s2, m-1);
        int choice2 = longestSubsequence(s1, n-1, s2, m);
        arr[n][m] = max(choice1, choice2);
        return arr[n][m];
    }
}

int longestSubsequence_mem(string s1, int n, string s2, int m) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[m+1];
        for(int j=0; j<m+1; j++) {
            arr[i][j] = -1;
        }
    }
    int ans = longestSubsequence_mem_help(s1, n, s2, m, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

// Top-down approach
int longestSubsequence_td_help(string s1, int n, string s2, int m, int** arr) {
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

int longestSubsequence_td(string s1, int n, string s2, int m) {
    int ** arr = new int* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[m+1];
        for(int j=0; j<m+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;
            }
        }
    }
    int ans = longestSubsequence_td_help(s1, n, s2, m, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int length1 = longestSubsequence(s1, n, s2, m);
    int length2 = longestSubsequence_mem(s1, n, s2, m);
    int length3 = longestSubsequence_td(s1, n, s2, m);
    cout << length1 << endl;
    cout << length2 << endl;
    cout << length3 << endl;
    return 0;
}