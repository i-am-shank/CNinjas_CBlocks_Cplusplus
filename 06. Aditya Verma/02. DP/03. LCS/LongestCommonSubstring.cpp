#include <iostream>
#include <string>
using namespace std;

int longestSubstring(string s1, int n, string s2, int m, int longest) {
    if(n==0 || m==0) {
        return longest;
    }
    if(s1[n-1] == s2[m-1]) {
        longest = longestSubstring(s1, n-1, s2, m-1, longest+1);
    }
    else {
        int choice1 = longestSubstring(s1, n, s2, m-1, 0);
        int choice2 = longestSubstring(s1, n-1, s2, m, 0);
        longest = max(longest, max(choice1, choice2));
    }
    return longest;
}

// Memoization
int longestSubstring_mem_help(string s1, int n, string s2, int m, int longest, int**arr) {
    if(arr[n][m] != -1) {
        return arr[n][m];
    }
    if(n==0 || m==0) {
        arr[n][m] = longest;
        return arr[n][m];
    }
    if(s1[n-1] == s2[m-1]) {
        longest = longestSubstring_mem_help(s1, n-1, s2, m-1, longest+1, arr);
        arr[n][m] = longest;
        return arr[n][m];
    }
    else {
        int choice1 = longestSubstring_mem_help(s1, n-1, s2, m, longest, arr);
        int choice2 = longestSubstring_mem_help(s1, n, s2, m-1, longest, arr);
        longest = max(longest, max(choice1, choice2));
        arr[n][m] = longest;
        return arr[n][m];
    }
}

int longestSubstring_mem(string s1, int n, string s2, int m, int longest) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int [m+1];
        for(int j=0; j<m+1; j++) {
            arr[i][j] = -1;
        }
    }
    int ans = longestSubstring_mem_help(s1, n, s2, m, longest, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

// Top-down approach
int longestSubstring_td_help(string s1, int n, string s2, int m, int** arr) {
    int longest = 0;
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(s1[i-1] == s2[j-1]) {
                arr[i][j] = 1 + arr[i-1][j-1];
                longest = max(longest, arr[i][j]);
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    return longest;
}

int longestSubstring_td(string s1, int n, string s2, int m) {
    int **arr = new int* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[m+1];
        for(int j=0; j<m+1; j++) {
            if(i==0 && j==0) {
                arr[i][j] = 0;
            }
        }
    }
    int ans = longestSubstring_td_help(s1, n, s2, m, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size() , m = s2.size();
    int longest = 0;
    int length1 = longestSubstring(s1, n, s2, m, longest);
    int length2 = longestSubstring_mem(s1, n, s2, m, longest);
    int length3 = longestSubstring_td(s1, n, s2, m);
    cout << length1 << endl;
    cout << length2 << endl;
    cout << length3 << endl;
    return 0;
}