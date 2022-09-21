#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Solution {
	// Tabulation --> space optimization
	// Time : O(n)
	// Space : O(1)
	int fib_dp_space(ll n) {
		int mod = 1e9+7;
		int prev2=0, prev=1;
		for(ll i=2; i<=n; i++) {
			int curr = ((prev2%mod) + (prev%mod)) % mod;
			prev2 = prev;
			prev = curr;
		}
		return prev; // curr of last iteration
	}

	// Tabulation
	// Time : O(n)
	// Space : O(n)
	int fib_dp(ll n) {
		int mod = 1e9+7;
		if(n==0 || n==1) {
			return n;
		}
		vector<ll> dp(n+1, 0);
		dp[0] = 0, dp[1] = 1;
		for(ll i=2; i<=n; i++) {
			dp[i] = ((dp[i-1]%mod) + (dp[i-2]%mod)) % mod;
		}
		return (dp[n]%mod);
	}

	// Memoization
	// Time : O(n)
	// Space : O(n) + O(n) .. Recursion stack
	ll fib_mem_help(ll n, vector<ll>& dp) {
	    int mod = 1e9+7;
		if(n==0 || n==1) {
			return n;
		}
		if(dp[n] != -1) {
			return dp[n] % mod;
		}
		dp[n] = ((fib_mem_help(n-1, dp)%mod) + (fib_mem_help(n-2, dp)%mod)) % mod;
		return dp[n];
	}

	ll fib_mem(ll n) {
		vector<ll> dp(n+1, -1);
		return fib_mem_help(n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Auxiliary recursion stack
	ll fib_rec(ll n) {
		if(n==0 || n==1) {
			return n;
		}
		return (fib_rec(n-1) + fib_rec(n-2));
	}

  public:
    ll nthFibonacci(ll n){
        // code here
        // ll ans1 = fib_rec(n);
        // ll ans2 = fib_mem(n);
        // ll ans3 = fib_dp(n);
        ll ans4 = fib_dp_space(n);
        ll mod = 1e9 + 7;
        return (ans4 % mod);
    }
};

int main() {
	Solution solve;
	ll n;
	cin >> n;
	ll ans = solve.nthFibonacci(n);
	cout << ans << "\n";
	return 0;
}