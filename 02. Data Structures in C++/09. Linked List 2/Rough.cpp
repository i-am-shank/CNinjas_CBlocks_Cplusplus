#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void printAllPossibleCodes(int num,int n,string output) {
    if(num==0 || n==0) {
        cout<<output<<endl;
        return;
    }
    int n1=num/(int)(pow(10,n-1)+0.5);
    char c1='a'+n1-1;
    printAllPossibleCodes(num%(int)(pow(10,n-1)+0.5),n-1,output+c1);
    if(c1!='\0') {
        int n2=num/(int)(pow(10,n-2)+0.5);
        if(n2>=10 && n2<=26) {
            char c2='a'+n2-1;
            printAllPossibleCodes(num%(int)(pow(10,n-2)+0.5),n-2,output+c2);
            return;
        }
    }
    return;
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    int num=0;
    for(int i=0;input[i]!='\0';i++) {
        num=(num*10)+(input[i]-'0');
    }
    int count=0;
    while(num!=0) {
        num=num/10;
        count++;
    }
    string output;
    printAllPossibleCodes(num,count,output);
    return;
}

int main() {
    string input;
    cin>>input;

    printAllPossibleCodes(input);

    return 0;
}