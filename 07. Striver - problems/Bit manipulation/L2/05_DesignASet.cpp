/*
Functionalities :-
	1. Add(x)
	2. Remove(x)
	3. Print all elements
  ->  Required complexities :- (for add() & remove())
		Time : O(1)   ,   Space : O(1)
  ->  Constraints :-
		0 <= x <= 60
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Space : O(1)
class ourSet {
public:
	ll nums = 0;  // 64 bits (8 bytes)

	// Time : O(1)
	// Space : O(1)
	void add(ll x) {
		ll mask = (ll)(1 << x);
		nums = (nums | mask); // Set xth bit
		return;
	}

	// Time : O(1)
	// Space : O(1)
	void remove(ll x) {
		ll mask = ~(ll)(1 << x);
		nums = (nums & mask);
		return;
	}

	// Time : O(n)
	// Space : O(1)
	void print() {
		ll temp = nums;
		for(int i=0; i<61; i++) {
			int currBit = (1 & temp);
			temp = (temp >> 1);
			if(currBit == 1) {
				cout << i << " ";
			}
		}
		cout << endl;
		return;
	}
};

int main() {
	ourSet s;
	s.add(5);
	s.add(1);
	s.add(5);
	s.add(3);
	s.remove(1);
	s.print();
	return 0;
}