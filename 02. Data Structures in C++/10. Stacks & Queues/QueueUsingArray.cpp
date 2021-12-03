#include <iostream>
using namespace std;

template <typename T>
class Queue {
    private:

    T* arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:

    Queue() {
        arr = new T[4];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 4;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T data) {
        if(size == capacity) {
            T* newData = new T [2*capacity];
            capacity = 2*capacity;
            int j=0;
            for(int i=firstIndex; i<capacity; i++) {
                newData[j++] = arr[i];
            }
            for(int i=0; i<firstIndex; i++) {
                newData[j++] = arr[i];
            }
            delete []arr;
            arr = newData;
            firstIndex = 0;
            nextIndex = capacity;
        }
        arr[nextIndex] = data;
        nextIndex = (nextIndex+1) % capacity;
        size++;
        if(firstIndex == -1) {
            firstIndex = 0;
        }
        return;
    }

    T dequeue() {
        if(size == 0) {
            cout <<"Queue is Empty !" << endl;
            return 0;
        }
        T ans = arr[firstIndex];
        firstIndex = (firstIndex+1) % capacity;
        size--;
        if(size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    T front() {
        if(size == 0) {
            cout <<"Queue is Empty !" << endl;
            return 0;
        }
        T ans = arr[firstIndex];
        return ans;
    }
};


int main() {
    Queue <int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}