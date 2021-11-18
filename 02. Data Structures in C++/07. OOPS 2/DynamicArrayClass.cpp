#include <iostream>
using namespace std;


class DynamicArray {
    private:

    int *data;
    int nextIndex;
    int capacity;

    public:

    DynamicArray() {    // constructor
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray (DynamicArray const &d) {    // copy constructor
        //   Shallow copy
        //this->data = d.data;
        //   Deep copy
        this->data = new int[d.capacity];
        for (int i=0; i<nextIndex; i++) {
            this->data[i] = data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void operator = (DynamicArray const &d) {
        this->data = new int[d.capacity];
        for (int i=0; i<nextIndex; i++) {
            this->data[i] = data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(int element) {
        if (nextIndex == capacity) {
            int *newData = new int [2*capacity];
            for (int i=0; i<capacity; i++) {
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
            capacity = 2*capacity;
        }
        data[nextIndex++] = element;
    }

    int get(int index) {
        if (index < nextIndex) {
            return data[index];
        }
        else {
            return -1;
        }
    }

    void add(int index, int element) {
        if (index < nextIndex) {
            data[index] = element;
        }
        else if (index == nextIndex) {
            add(element);
        }
        else {
            return;
        }
    }

    void print() {
        for (int i=0; i<nextIndex; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};