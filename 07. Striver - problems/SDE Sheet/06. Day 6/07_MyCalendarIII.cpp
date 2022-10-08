#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree {
	map<int, int> freq;

public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        freq[start]++;
        freq[end]--;
        int maxCount=0, count=0;
        for(auto it=freq.begin(); it!=freq.end(); it++) {
        	count += (it->second);
        	maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

int main() {
	MyCalendarThree* obj = new MyCalendarThree();
	int n1 = obj->book(10, 20);
	int n2 = obj->book(50, 60);
	int n3 = obj->book(10, 40);
	int n4 = obj->book(5, 15);
	int n5 = obj->book(5, 10);
	int n6 = obj->book(25, 55);
	cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<" "<<n6<<"\n";
	return 0;
}