// Time Complexity = O ( (N*2)logN )
// Space Complexity = O ( NlogN )


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str(int n) {
    string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return letters[n];
}

int keypad(int num, string output[]) {
    if (num == 0) {    // Base case to prevent num=0 to go into recursion, i.e. (nun/10) call.
        output[0] = "";
        return 1;
    }
    int n = num % 10;
    string s = str(n);
    int len = s.size();
    int smallOutput = keypad(num/10, output);
    for (int i=0; i<len-1; i++) {
        for (int j=smallOutput*(i+1); j<smallOutput*(i+2); j++) {
            output[j] = output[j-smallOutput];
        }
    }
    int k=0;
    for (int i=0; i<len; i++) {
        for (int j=0; j<smallOutput; j++) {
            output[k] += s[i];
            k++;
        }
    }
    return len*smallOutput;
}

int main() {
    int num, n;
    cin >> num;
    string *output = new string [10000];
    n = keypad(num, output);
    for (int i=0; i<n; i++) {
        cout << output[i] << endl;
    }
    delete []output;
    return 0;
}