// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

void minLengthWord(char input[], char minWord[]) {
    int min=INT_MAX, start, count, size=strlen(input), k;
    for (int i=0; i<size; i++) {
        count = 0, k=0, start=i;
        while (input[i] != ' '  &&  i<size-1) {
            i++;
            count++;
        }
        if(count < min) {
            min = count;
            for (int j=start; j<i; j++) {
                minWord[k++] = input[j];
            }
            minWord[k] = '\0';
        }
    }
    return;
}

int main() {
    int size = 1e6;
    char *input = new char [size];
    char *minWord = new char [size];
    cin.getline(input, size);
    minLengthWord(input, minWord);
    cout << minWord << endl;
    return 0;
}