#include <iostream>
using namespace std;

template <typename T>
class Stack {
    private:

    int* data;
    int nextIndex;
    int capacity;

    public:

    Stack() {
        data = new T [4];
        nextIndex = 0;
        capacity = 4;
    }

    int getSize() {
        return nextIndex;
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void push(T element) {
        if(nextIndex == capacity) {
            T *newData = new T [2*capacity];
            capacity = 2*capacity;
            for(int i=0; i<capacity; i++) {
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
        return;
    }

    T top() {
        if(isEmpty()) {
            cout << "Stack is Empty !" << endl;
            return 0;
        }
        return data[nextIndex-1];
    }

    T pop() {
        if(isEmpty()) {
            cout << "Stack is Empty !" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
};


int main() {
    Stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}