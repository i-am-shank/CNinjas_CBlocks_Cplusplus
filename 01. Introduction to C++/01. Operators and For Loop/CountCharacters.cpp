// Time Complexity = O(n)
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    char ch;
    ch = cin.get();
    int in, nchar=0, nint=0, nspace=0;
    while (ch != '$'){
        in = ch;
        if (in >= 97 && in <= 122){
            nchar += 1;
        }
        else if (in >= 48 && in <= 57){
            nint += 1;
        }
        else if (ch=='\t' || ch=='\n' || ch==' '){
            nspace += 1;
        }
        ch = cin.get();
    }
    cout << nchar << " " << nint << " " << nspace << endl;
}