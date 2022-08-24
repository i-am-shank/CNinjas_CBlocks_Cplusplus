#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(map<char,set<char>>& adjList, char c, map<char,bool>& visited, map<char,bool>& visited2) {
		visited[c] = true;
		visited2[c] = true;
		for(auto it: adjList[c]) {
			if(!visited[it]) {
				bool smallAns = dfs(adjList, it, visited, visited2);
				if(smallAns == true) {
					return true;
				}
			}
			else {
				if(visited2[it] == true) {
					// Part of same path, visited in another way
					// cyclic graph
					return true;
				}
			}
		}
		visited2[c] = false;
		return false;
	}

	bool isCyclic(map<char,set<char>>& adjList, int n, vector<char> characters) {
		map<char,bool> visited;
		map<char,bool> visited2;
        for(int i=0; i<n; i++) {
        	visited[characters[i]] = false; // check if visited
        	visited2[characters[i]] = false; // check if same path
        }
        for(int i=0; i<n; i++) {
        	if(visited[characters[i]] == false) {
        		bool smallAns = dfs(adjList, characters[i], visited, visited2);
        		if(smallAns == true) {
        			return true; // If 1-cycle found, cyclic
        		}
        	}
        }
        return false; // No cycle found
	}

	string topoSort(map<char,set<char>>& adjList, int n, vector<char>& characters) {
		map<char,int> inDegree;
		for(int i=0; i<n; i++) {
			for(auto it: adjList[characters[i]]) {
				inDegree[it]++; // i  -->  it
			}
		}
		queue<char> q;
		for(auto it: inDegree) {
			if(it.second == 0) {
				q.push(it.first);
			}
		}
		string ans="";
		while(!q.empty()) {
			char front = q.front();
			q.pop();
			ans += front;
			for(auto it: adjList[front]) {
				inDegree[it]--;
				if(inDegree[it] == 0) {
					q.push(it);
				}
			}
		}
		return ans;
	}

public:
    string alienOrder(vector<string> &words) {
        string ans = "";
        map<char,set<char>> adjList;
        int n = words.size();
        set<char> charSet;
        vector<char> characters;
        for(int i=0; i<n-1; i++) {
        	for(int j=i+1; j<n; j++) {
        		string s1 = words[i];
        		string s2 = words[j];
        		int x=0, y=0;
        		while(x<s1.size() && y<s2.size()) {
        			if(s1[x] != s2[y]) {
        				// s1[x] < s2[y]  ..  s1[x] --> s2[y]
        				adjList[s1[x]].insert(s2[y]);
        				if(charSet.find(s1[x]) == charSet.end()) {
        					characters.push_back(s1[x]);
        					charSet.insert(s1[x]);
        				}
        				if(charSet.find(s2[y]) == charSet.end()) {
        					characters.push_back(s2[y]);
        					charSet.insert(s2[y]);
        				}
        				break;
        			}
        			x++;
        			y++;
        		}
        	}
        }
        int num = characters.size();
        bool check = isCyclic(adjList, num, characters);
        if(check == true) {
        	return ans;
        }
        else {
        	ans = topoSort(adjList, num, characters);
        	return ans;
        }

        
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<string> words(n);
	for(int i=0; i<n; i++) {
		cin >> words[i];
	}
	string ans = solve.alienOrder(words);
	cout << ans << endl;
	return 0;
}