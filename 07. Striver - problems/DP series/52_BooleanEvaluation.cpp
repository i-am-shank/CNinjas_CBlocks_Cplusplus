#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Tabulation
// Time : O(n^3)
// Space : O(n^2)
ll evaluate_dp(string& exp) {
	int n = exp.size();
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2,0)));
	// Base case
	for(int i=0; i<n; i++) {
		dp[i][i][1] = (exp[i] == 'T');
		dp[i][i][0] = (exp[i] == 'F');
	}
	ll mod = (1e9 + 7);
	for(int s=n-1; s>=0; s--) {
		for(int e=s+2; e<n; e++) {
			for(int isTrue=0; isTrue<=1; isTrue++) {
				ll ans = 0;
			    for(int i=s+1; i<e; i++) {
			        ll lT = dp[s][i-1][1] % mod;
			        ll lF = dp[s][i-1][0] % mod;
			        ll rT = dp[i+1][e][1] % mod;
			        ll rF = dp[i+1][e][0] % mod;
			        char c = exp[i];
			        ll smallAns;
			        if(c == '&') {
			            if(isTrue == 1) {
			                smallAns = (lT * rT) % mod;
			            }
			            else {
			                smallAns = ((lT*rF) + (lF*rT) + (lF*rF)) % mod;
			            }
			        }
			        else if(c == '|') {
			            if(isTrue == 1) {
			                smallAns = ((lT*rT) + (lT*rF) + (lF*rT)) % mod;
			            }
			            else {
			                smallAns = (lF*rF) % mod;
			            }
			        }
			        else {
			            if(isTrue == 1) {
			                smallAns = ((lT*rF) + (lF*rT)) % mod;
			            }
			            else {
			                smallAns = ((lF*rF) + (lT*rT)) % mod;
			            }
			        }
			        ans += smallAns;
			        ans %= mod;
			    }
			    dp[s][e][isTrue] = ans % mod;
			}
		}
	}
	return (dp[0][n-1][1] % mod);
}

// Memoization
// Time : O(n^3)
// Space : O(n^2)  .. Last vector of size 2 is O(1)
ll evaluate_mem_help(string& exp, int s, int e, int isTrue, vector<vector<vector<ll>>>& dp) {
    // Base case
    if(s > e) {
        return 0;
    }
    if(s == e) {
        if(isTrue == 1) {
            return (exp[s] == 'T');
        }
        else {
            return (exp[s] == 'F');
        }
    }
    if(dp[s][e][isTrue] != -1) {
        return dp[s][e][isTrue];
    }
    ll ans = 0;
    ll mod = (1e9 + 7);
    for(int i=s+1; i<e; i++) {
        ll lT = evaluate_mem_help(exp, s, i-1, 1, dp) % mod;
        ll lF = evaluate_mem_help(exp, s, i-1, 0, dp) % mod;
        ll rT = evaluate_mem_help(exp, i+1, e, 1, dp) % mod;
        ll rF = evaluate_mem_help(exp, i+1, e, 0, dp) % mod;
        char c = exp[i];
        ll smallAns;
        if(c == '&') {
            if(isTrue == 1) {
                smallAns = (lT * rT) % mod;
            }
            else {
                smallAns = ((lT*rF) + (lF*rT) + (lF*rF)) % mod;
            }
        }
        else if(c == '|') {
            if(isTrue == 1) {
                smallAns = ((lT*rT) + (lT*rF) + (lF*rT)) % mod;
            }
            else {
                smallAns = (lF*rF) % mod;
            }
        }
        else {
            if(isTrue == 1) {
                smallAns = ((lT*rF) + (lF*rT)) % mod;
            }
            else {
                smallAns = ((lF*rF) + (lT*rT)) % mod;
            }
        }
        ans += smallAns;
        ans %= mod;
    }
    dp[s][e][isTrue] = ans % mod;
    return dp[s][e][isTrue];
}

int evaluate_mem(string& exp, int s, int e, int isTrue) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2,-1)));
    ll ans = evaluate_mem_help(exp, s, e, isTrue, dp);
    int mod = (1e9 + 7);
    ans %= mod;
    return ans;
}

// Recursion
// Time : Exponential
// Space : O(n) .. Recursion stack
ll evaluate_rec(string& exp, int s, int e, int isTrue) {
    // Base case
    if(s > e) {
        return 0;
    }
    if(s == e) {
        if(isTrue == 1) {
            return (exp[s] == 'T');
        }
        else {
            return (exp[s] == 'F');
        }
    }
    ll ans = 0;
    for(int i=s+1; i<e; i++) {
        ll lT = evaluate_rec(exp, s, i-1, 1);
        ll lF = evaluate_rec(exp, s, i-1, 0);
        ll rT = evaluate_rec(exp, i+1, e, 1);
        ll rF = evaluate_rec(exp, i+1, e, 0);
        char c = exp[i];
        ll smallAns;
        if(c == '&') {
            if(isTrue == 1) {
                smallAns = (lT * rT);
            }
            else {
                smallAns = (lT*rF) + (lF*rT) + (lF*rF);
            }
        }
        else if(c == '|') {
            if(isTrue == 1) {
                smallAns = (lT*rT) + (lT*rF) + (lF*rT);
            }
            else {
                smallAns = (lF*rF);
            }
        }
        else {
            if(isTrue == 1) {
                smallAns = (lT*rF) + (lF*rT);
            }
            else {
                smallAns = (lF*rF) + (lT*rT);
            }
        }
        ans += smallAns;
    }
    ll mod = (1e9+7);
    return (ans % mod);
}

int evaluateExp(string& exp) {
    int n = exp.size();
    // int ans1 = evaluate_rec(exp, 0, n-1, 1);
    // int ans2 = evaluate_mem(exp, 0, n-1, 1);
    int ans3 = evaluate_dp(exp);
    return ans3;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string exp;
		cin >> exp;
		int ans = evaluateExp(exp);
		cout << ans << endl;
	}
	return 0;
}