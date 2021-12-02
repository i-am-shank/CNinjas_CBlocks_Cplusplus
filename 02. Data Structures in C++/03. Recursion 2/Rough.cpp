#include<iostream>
#include<string>
using namespace std;

void printAllPossibleCodes(string input,string output) {
    if(input[0]=='\0') {
        cout<<output<<endl;
        return;
    }
    if(input.size()==1) {
        int n=input[0]-'0';
        char c='a'+n-1;
        output=output+c;;
        cout<<output<<endl;
        return;
    }
    int n1=input[0]-'0';
    char c1='a'+n1-1;
    output=output+c1;
    printAllPossibleCodes(input.substr(1),output);
    int n2=((input[0]-'0')*10)+(input[1]-'0');
    if(n2<=26) {
        char c2='a'+n2-1;
        output[output.size()-1]=c2;
        printAllPossibleCodes(input.substr(2),output);
    }
    return;
}

int main() {
    string input;
    cin>>input;
    string output;
    printAllPossibleCodes(input,output);
    return 0;
}