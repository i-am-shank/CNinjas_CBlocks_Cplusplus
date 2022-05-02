// Multiplicative Inverse :-
//   A.B  =  1      =>       B is multiplicative inverse of A.
// Similarly :-
//   (A.B) % m  =  1       =>       B is multiplicative modulo inverse of A & m.

//  Now,  (A.B - 1) % m  =  0
//     => (A.B - 1)  =  mq     ,     where q = a positive integer
//     => (A.B - mq)  =  1
//     => (A.B + mQ)  =  1     =>     Solution exists only when,     gcd(A , m) = 1

//  A(B) + m(Q) = gcd(A, m)      ...   Solve for B and Q.    =>    B is the answer



#include <bits/stdc++.h>
using namespace std;

class Triplet{
public:
	int x;
	int y;
	int gcd;
};

Triplet extendedEuclid(int a, int b) {    //  ax + by = gcd(a,b)
	if(b == 0) {    //     =>  ax = gcd(a,0)      =>     x = 1, y = 0, gcd = a
		Triplet ans;
		ans.x = 1;
		ans.y = 0;
		ans.gcd = a;
		return ans;
	}
	Triplet ans;
	Triplet smallAns = extendedEuclid(b, a%b);   //  ax + by = gcd(a,b) = gcd(b, a%b) = bx + (a%b)y
       //  ax + by = bx + (a - b*(a/b))y     =>     (x)a + (y)b  =  (y)a + (x-(a/b)y)b
	ans.x = smallAns.y;     // LHS => ans   ..   RHS => smallAns
	ans.y = smallAns.x - ((a/b)*smallAns.y);
	ans.gcd = smallAns.gcd;
	return ans;
}

int mmInverse(int a, int b) {
	Triplet solution = extendedEuclid(a, b);    // Just get co-efficient of a in LHS  ..  i.e x
	return solution.x;
}

int main() {
	int a, m;    // Input a & m so, gcd(a,m) = 1  (condition for multiplicative modulo inverse)
	cin >> a >> m;    // A(B) + m(Q) = gcd(A, m)  ..  Solve for B & Q.  =>  B is answer
	int ans = mmInverse(a, m);
	cout << ans << endl;
	return 0;
}