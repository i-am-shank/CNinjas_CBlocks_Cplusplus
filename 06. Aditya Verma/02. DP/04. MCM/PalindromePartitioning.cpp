#include <iostream>
#include <string>
using namespace std;

bool palindrome(string s, int start, int end) {
    if(start >= end) {
        return true;
    }
    int i=start, j=end;
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string s, int start, int end) {
    if(start >= end  ||  palindrome(s, start, end)) {
        return 0;
    }
    int minCount = INT_MAX;
    for(int k=start; k<end; k++) {
        int leftAns = palindromePartitioning(s, start, k);
        int rightAns = palindromePartitioning(s, k+1, end);
        int temp = 1 + leftAns + rightAns;
        minCount = min(minCount, temp);
    }
    return minCount;
}

// Memoization

int pp_mem_help(string s, int start, int end, int** arr) {
    if(arr[start][end] != -1) {
        return arr[start][end];
    }
    if(palindrome(s, start, end)) {
        arr[start][end] = 0;
        return 0;
    }
    int minCount = INT_MAX;
    for(int k=start; k<end; k++) {
        int leftAns, rightAns;
        if(arr[start][k] != -1) {    //  Calculating leftAns
            leftAns = arr[start][k];
        }
        else {
            leftAns = pp_mem_help(s, start, k, arr);
            arr[start][k] = leftAns;
        }
        if(arr[k+1][end] != -1) {    //  Calculating rightAns
            rightAns = arr[k+1][end];
        }
        else {
            rightAns = pp_mem_help(s, k+1, end, arr);
            arr[k+1][end] = rightAns;
        }
        int temp = 1 + leftAns + rightAns;
        minCount = min(minCount, temp);
    }
    arr[start][end] = minCount;
    return arr[start][end];
}

int pp_mem(string s, int start, int end) {
    int **arr = new int*[end+2];
    for(int i=0; i<end+2; i++) {
        arr[i] = new int[end+2];
        for(int j=0; j<end+2; j++) {
            arr[i][j] = -1;
            if(i >= j) {
                arr[i][j] = 0;
            }
        }
    }
    int ans = pp_mem_help(s, start, end, arr);
    for(int i=0; i<end+2; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int count = palindromePartitioning(s, 0, n-1);
    int count2 = pp_mem(s, 0, n-1);
    cout << count << endl;
    cout << count2 << endl;
    return 0;
}