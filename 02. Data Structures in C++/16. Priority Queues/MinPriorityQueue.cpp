#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;

    public:
    PriorityQueue() {

    }

    bool isEmpty() {
        return pq.size()==0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if(isEmpty()) {
            return 0;
        }
        return pq[0];
    }

    // Time Complexity = O(logN)
    void insert(int element) {
        pq.push_back(element);
        // ----------------- UP - HEAPIFY -------------------
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex-1) / 2;
        while(childIndex > 0) {
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex-1) / 2;
        }
    }

    // Time Complexity = O(logN)
    int removeMin() {
        if(pq.size() == 0) {
            return 0;
        }
        int temp = pq[0];
        pq[0] = pq[pq.size()-1];
        pq[pq.size()-1] = temp;
        pq.pop_back();
        // ------------------ DOWN - HEAPIFY --------------------
        int parentIndex = 0;
        int childIndex1 = (2*parentIndex) + 1;
        int childIndex2 = (2*parentIndex) + 2;
        while(childIndex1 < pq.size()) {
            int minIndex = parentIndex;
            if(pq[parentIndex] > pq[childIndex1]) {
                minIndex = childIndex1;
            }
            if(childIndex2 < pq.size() && pq[childIndex2] < pq[minIndex]) {
                minIndex = childIndex2;
            }
            if(minIndex == parentIndex) {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            parentIndex = minIndex;
            childIndex1 = (2*parentIndex) + 1;
            childIndex2 = (2*parentIndex) + 2;
        }
        return temp;
    }
};

int main() {
    PriorityQueue p;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1:  // insert
                int element;
                cin >> element;
                p.insert(element);
                break;
            case 2:  // getMin
                cout << p.getMin() << endl;
                break;
            case 3:  // removeMin
                cout << p.removeMin() << endl;
                break;
            case 4:  // isEmpty
                cout << (p.isEmpty() ? "True" : "False") << endl;
                break;
            case 5:  // getSize
                cout << p.getSize() << endl;
                break;
            default:
                return 0;
        }
        cin >> choice;
    }
}