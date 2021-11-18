// Time Complexity = O(NlogN)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

int partition(int input[], int size) {
    int count = 0;
    int a = input[0];
    for (int i=0; i<size; i++) {
        if (input[i] < a) {
            int temp = input[i];
            input[i] = input[count];
            input[count] = temp;
            count++;
        }
    }
    return count;
}

void quickSort(int input[], int size) {
    if (size < 2) {
        return;
    }
    int c = partition(input, size);
    quickSort(input, c);
    quickSort(input+c+1, size-c-1);
}

int main() {
    int size;
    cin >> size;
    int *input = new int [size];
    for (int i=0; i<size; i++) {
        cin >> input[i];
    }
    quickSort(input, size);
    for (int i=0; i<size; i++) {
        cout << input[i] << ' ';
    }
    delete []input;
    return 0;
}