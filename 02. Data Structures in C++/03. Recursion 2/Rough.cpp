#include <iostream>
using namespace std;

int main() {
    int input[100], length;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    for( int i = 0; i < length; i++) { 
        cout << input[i] << " ";
    }
    cout << endl;
}