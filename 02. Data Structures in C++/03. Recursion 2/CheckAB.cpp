#include <iostream>
using namespace std;

bool checkAB(char input[]) {
    if(input[0] == '\0') {
        return true;
    }
    bool smallAns = checkAB(input+1);
    if(input[0] == 'a') {
        if(input[1] == '\0') {
            return true;
        }
        else if(input[1] == 'a') {
            return smallAns;
        }
        else if(input[1]=='b' && input[2]=='b') {
            if(input[3] == '\0') {
                return true;
            }
            else if(input[3] == 'a') {
                return checkAB(input+3);
            }
            else {
                return false;
            }
        }
    }
    return false;
}

int main() {
    char input[1000];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if(ans == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}