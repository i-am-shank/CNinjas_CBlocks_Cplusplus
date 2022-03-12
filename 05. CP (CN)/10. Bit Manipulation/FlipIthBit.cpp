#include <bits/stdc++.h>
using namespace std;

int flipIthBit(int n, int i){
	int x = 1 << i;  // 2 ^ i.
	int ans = n ^ x;  // XOR with ith bit set as 1  ..  other all as 0.
	// 1 ^ 1 = 0 , 0 ^ 1 = 1   ...   1 ^ 0 = 1 , 0 ^ 0 = 0   (so reversing only ith bit)
	return ans;
}

int main() {
	int n, i; 
	cin >> n >> i;
	int ans = flipIthBit(n, i);
	cout << ans << endl;
	return 0;
}