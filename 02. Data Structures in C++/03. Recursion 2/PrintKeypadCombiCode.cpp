// TIme Complexity = O(NlogN)
// Space Complexity = O(N)


#include <iostream>
#include <string>
using namespace std;

string letters(int n) {
    string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return arr[n];
}

void printKey(int num, string str) {
    if (num==0 || num==1) {
        cout << str << endl;
        return;
    }
    int n = num % 10;
    string s = letters(n);
    for (int i=0; i<s.size(); i++) {
        printKey(num/10, s[i]+str);
    }
    return;
}

void printKeypad(int num) {
    string s = "";
    printKey(num, s);
    return;
}

int main() {
    int n;
    cin >> n;
    printKeypad(n);
    return 0;
}