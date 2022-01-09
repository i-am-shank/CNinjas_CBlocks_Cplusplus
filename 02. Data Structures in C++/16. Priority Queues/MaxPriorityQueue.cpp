#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;

    public:
    PriorityQueue() {

    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex-1) / 2;
        while(childIndex > 0) {
            if(pq[parentIndex] < pq[childIndex]) {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex-1) / 2;
        }
    }

    int getMax() {
        if(pq.size() == 0) {
            return 0;
        }
        return pq[0];
    }

    int removeMax() {
        if(pq.size() == 0) {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq[pq.size()-1] = ans;
        pq.pop_back();
        int parentIndex = 0;
        int childIndex1 = (2*parentIndex) + 1;
        int childIndex2 = (2*parentIndex) + 2;
        while(childIndex1 < pq.size()) {
            int maxIndex = parentIndex;
            if(pq[childIndex1] > pq[parentIndex]) {
                maxIndex = childIndex1;
            }
            if(childIndex2 < pq.size() && pq[childIndex2] > pq[maxIndex]) {
                maxIndex = childIndex2;
            }
            if(maxIndex == parentIndex) {
                break;
            }
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            parentIndex = maxIndex;
            childIndex1 = (2*parentIndex) + 1;
            childIndex2 = (2*parentIndex) + 2;
        }
        return ans;
    }

    int getSize() {
        return pq.size();
    }

    bool isEmpty() {
        return pq.size()==0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1:   // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:   // getMax
                cout << pq.getMax() << endl;
                break;
            case 3:   // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4:   // isEmpty
                cout << (pq.isEmpty() ? "True" : "False") << endl;
                break;
            case 5:   // getSize
                cout << pq.getSize() << endl;
                break;
            default:
                return 0;
        }
        cin >> choice;
    }
}