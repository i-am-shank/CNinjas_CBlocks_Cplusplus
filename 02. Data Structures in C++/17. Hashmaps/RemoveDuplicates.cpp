#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Time Complexity = O(N)
// Space Complexity = O(N)

vector<int> RemoveDuplicates(int* arr, int size) {
    vector<int> v;
    unordered_map <int, bool> ourmap;
    for(int i=0; i<size; i++) {
        if(ourmap.count(arr[i]) > 0) {
            continue;
        }
        pair <int, bool> p(arr[i], true);
        ourmap.insert(p);
        v.push_back(arr[i]);
    }
    return v;
}

int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    vector<int> v = RemoveDuplicates(arr, size);
    for(int i=0; i<v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    return 0;
}