#include <iostream>
#include <set>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &A) {
	set<int> s;
	for(int i=0; i<A.size(); i++) {
		s.insert(A.at(i));
	}
	int i = 0;
	set<int> :: iterator it;
	for(it=s.begin(); it!=s.end(); it++) {
		A.at(i) = *it;
		i++;
	}
	return s.size();
}

int main() {
	int n;
	cin >> n;
	vector<int> input;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		input.push_back(ele);
	}
	int size = removeDuplicates(input);
	for(int i=0; i<size; i++) {
		cout << input.at(i) << " ";
	}
	cout << endl;
	return 0;
}