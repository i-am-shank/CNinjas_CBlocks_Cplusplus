// TIme Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

bool checkAB(char input[]) {
    if (strlen(input) == 0) {
        return true;
    }
    if (input[0] == 'a') {
        if (input[1] == '\0') {
            return true;
        }
        else if (input[1] == 'a') {
            return checkAB(input+1);
        }
        else if (input[1]=='b' && input[2]=='b') {
            if (input[3] == '\0') {
                return true;
            }
            else if (input[3] == 'a') {
                return checkAB(input+3);
            }
        }
    }
    return false;
}

int main() {
    char input[1000];
    cin >> input;
    bool ans = checkAB(input);
    cout << (ans == true ? "true" : "false") << endl;
    return 0;
}