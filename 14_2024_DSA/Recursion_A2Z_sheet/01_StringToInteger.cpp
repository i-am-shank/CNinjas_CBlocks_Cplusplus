#include <iostream>
using namespace std;

#define ll long long

class Solution {
	bool isDigit(char ch) {
		return ((ch>='0') && (ch<='9'));
	}

	string getNum(string s, int n, int idx) {
		if(idx == n) {
			return "";
		}
		if(isDigit(s[idx])==true || s[idx]=='-' || s[idx]=='+') {
			return (s[idx] + getNum(s, n, idx+1));
		}
		else {
			return "";
		}
	}

public:
    ll myAtoi(string s) {
    	ll n = s.size();
		ll idx=0;
		for(ll i=0; i<n; i++) {
			if(s[i] == ' ') {
				idx++;
			}
			else {
				break;
			}
		}
		s = s.substr(idx); // removed leading space
        n = s.size(); // updated size
        string ans = getNum(s, n, 0);
        // convert string ans --> integer
        // cout<<"ans = "<<ans<<"\n";
        ll x = 0;
        bool negative = false;
        n = ans.size();
        if(n>0 && ans[0]=='-') {
        	negative = true;
        }
        else if(n>0 && ans[0]=='+') {
            negative = false;
        }
        for(int i=0; i<n; i++) {
        	if(isDigit(ans[i]) == true) {
        		x = ((x*10) + (ll)(ans[i]-'0'));
        	}
        	else {
        		if(i==0  &&  (ans[i]=='-' || ans[i]=='+')) {
        			continue;
        		}
        		else {
        			break;
        		}
        	}
        	ll num = x;
        	if(negative == true) {
        		num *= (-1);
        	}
        	if(num < INT_MIN) {
	            return INT_MIN;
	        }
	        else if(num > INT_MAX) {
	            return INT_MAX;
	        }
        }
        if(negative == true) {
        	x *= (-1);
        }
        return x;
    }
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	string x; // just to skip this line
	getline(cin, x);
	while(t--) {
		string s;
		// cin >> s;
		getline(cin, s);
		Solution solve;
		int ans = solve.myAtoi(s);
		cout << ans << "\n";
	}
	return 0;
}