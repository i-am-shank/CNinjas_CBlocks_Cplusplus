#include <bits/stdc++.h>
using namespace std;

struct Job {
	int id;
	int dead;
	int profit;
};

typedef pair<int,int> pp;

class Solution {
	static bool sortByProfit(pp j1, pp j2) {
		if(j1.first == j2.first) {
			// Prioritise recent deadline
			return (j1.second < j2.second);
		}
		// Prioritise more-profit
		return (j1.first > j2.first);
	}

public:
	// Time : O(nlogn)
	// Space : O(n)
    vector<int> JobScheduling(vector<Job>& arr, int n)  { 
        vector<pp> jobs(n);
        for(int i=0; i<n; i++) {
        	int dead=arr[i].dead, profit=arr[i].profit;
        	jobs[i] = make_pair(profit, dead);
        }
        sort(jobs.begin(), jobs.end(), sortByProfit);
        vector<int> deadlines(101, 0); // Mark 1-which is occupied
        int totalProfit = 0, count = 0;
        for(int i=0; i<n; i++) {
        	int pi=jobs[i].first, di=jobs[i].second;
        	bool possible = false;
        	for(int i=di; i>=1; i--) {
        		if(deadlines[i] == 0) {
        			// Unoccupied deadline.. before current's
        			deadlines[i] = 1;
        			possible = true;
        			break;
        		}
        	}
        	if(possible == true) {
        		count++;
        		totalProfit += pi;
        	}
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(totalProfit);
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<Job> arr(n);
	for(int i=0; i<n; i++) {
		int currid, currdead, currprofit;
		cin >> currid >> currdead >> currprofit;
		Job ele;
		ele.id = currid;
		ele.dead = currdead;
		ele.profit = currprofit;
		arr[i] = ele;
	}
	Solution solve;
	vector<int> ans = solve.JobScheduling(arr, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}