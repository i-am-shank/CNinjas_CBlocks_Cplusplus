// Linear Diophantine Equations
//     ax + by = c     ..   Integral solution only when  ... gcd(a, b) divides c
//     ax + by = gcd(a, b)     ..    Find solution

//  From Euclid's algorithm ,   ax + by = gcd(a,b) = gcd(b, a%b)
//     And ,   a % b  =  a - (b * [a/b])  ...  where [] is GIF (Greatest Integer Function)
//  Now ,   bx1 + (a%b)y1 = gcd(b, a%b)    ..     will also have integral solutions
//  => bx1 + (a%b)y1  =  gcd(b, a%b)  =  gcd(a, b)  =  ax + by
//  => bx1 + (a%b)y1  =  ax + by      =>     bx1 + (a - b*[a/b])y1  =  ax + by
//  =>  b(x1 - [a/b]y1)  +  a(y1)  =  a(x)  +  b(y)

//  Comparing co-efficients of a & b :
//  y  =  (x1 - [a/b]y1)       ,       x  =  (y1)


#include <bits/stdc++.h>
using namespace std;

class Triplet{
public:
	int x;
	int y;
	int gcd;
};

Triplet extendedEuclid(int a, int b) {
	if(b == 0) {   //  ax + by = gcd(a, b)  =>  ax = gcd(a, 0) = a   =>   ax = a
		Triplet ans;
		ans.gcd = a;  // As b = 0
		ans.x = 1;  
		ans.y = 0;
		return ans;
	}
	Triplet smallAns = extendedEuclid(b, a%b);
	Triplet ans;
	ans.gcd = smallAns.gcd;   //  gcd(a , b)  =  gcd(b , a%b)
	ans.x = smallAns.y;
	ans.y = smallAns.x - ((a/b) * smallAns.y);   //  Integer division automatically gives [a/b].
	return ans;
}

int calculate_gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return calculate_gcd(b, a%b);
}

int main() {
	int x, y;
	cin >> x >> y;
	int a = max(x, y);
	int b = min(x, y);
	int gcd_a_b = calculate_gcd(a, b);    // Our equation is   ax + by = gcd(a, b).
	cout << x << "x + " << y << "y = " << gcd_a_b << endl;    // Printing equation
	cout << "Solution : " << endl;
	Triplet solution = extendedEuclid(x, y);
	cout << "x = " << solution.x << " , y = " << solution.y << endl;
	return 0;
}