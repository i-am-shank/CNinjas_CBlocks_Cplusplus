// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str) {
    string ans = "";
    unordered_map <char, bool> ourmap;
    for(int i=0; i<str.size(); i++) {
        if(ourmap.find(str[i]) == ourmap.end()) {
            ans += str[i];
            ourmap[str[i]] = true;
        }
        else {
            continue;
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    string ans = uniqueChar(str);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << "";
    }
    cout << endl;
    return 0;
}