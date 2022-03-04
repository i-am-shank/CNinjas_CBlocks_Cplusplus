#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Student{
public:
	string name;
	int roll;
	int marks;
};

bool compare(Student* s1, Student* s2) {
	if(s1->marks != s2->marks) {
		return s1->marks > s2->marks;
	}
	return s1->roll < s2->roll;
}

int main() {
	int n;
	cin >> n;
	Student** arr = new Student* [n];
	for(int i=0; i<n; i++) {
		arr[i] = new Student();
	}
	for(int i=0; i<n; i++) {  // Single line input taken  ..  n times.
		cin >> arr[i]->name;
		int m1, m2, m3;
		cin >> m1 >> m2 >> m3;
		arr[i]->marks = (m1+m2+m3);
		arr[i]->roll = (i+1);
	}
	sort(arr, arr+n, compare);
	for(int i=0; i<n; i++) {
		cout << (i+1) << " " << arr[i]->name << endl;
	}
	/*for(int i=0; i<n; i++) {
		delete []arr[i];
	}
	delete []arr;*/
	return 0;
}