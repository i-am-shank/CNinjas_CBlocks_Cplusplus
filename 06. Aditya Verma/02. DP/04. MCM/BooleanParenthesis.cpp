// 'T' , 'F' , '|' , '&' , '^'


#include <iostream>
#include <string>
using namespace std;

int boolParenthesis(string s, int start, int end, bool flag) {
    if(start > end) {
        return 0;
    }
    if(start == end) {
        if(flag == true) {
            return s[start] == 'T';
        }
        else {
            return s[start] == 'F';
        }
    }
    int count = 0;
    for(int k=start+1; k<=end-1; k+=2) {
        int lTrue = boolParenthesis(s, start, k-1, true);
        int lFalse = boolParenthesis(s, start, k-1, false);
        int rTrue = boolParenthesis(s, k+1, end, true);
        int rFalse = boolParenthesis(s, k+1, end, false);
        if(flag == true) {
            if(s[k] == '&') {
                count  +=  (lTrue * rTrue);
            }
            else if(s[k] == '|') {
                count  +=  ((lTrue * rTrue) + (lTrue * rFalse) + (lFalse * rTrue));
            }
            else {    // '^'  ..XOR operator
                count  +=  ((lTrue * rFalse) + (lFalse * rTrue));
            }
        }
        else {    // "False"
            if(s[k] == '&') {
                count  +=  ((lFalse * rTrue) + (lTrue * rFalse) + (lFalse * rFalse));
            }
            else if(s[k] == '|') {
                count  +=  (lFalse * rFalse);
            }
            else {    // '^'  ..XOR operator
                count  +=  ((lTrue * rTrue) + (lFalse * rFalse));
            }
        }
    }
    return count;
}

int booleanParenthesis(string s, int start, int end) {
    bool flag = true;
    int ans = boolParenthesis(s, start, end, flag);
    return ans;
}

int boolParenthesis_mem(string s, int start, int end, bool flag, int** tarr, int** farr) {
    if(flag == true) {
        if(tarr[start][end] != -1) {
            return tarr[start][end];
        }
    }
    else {
        if(farr[start][end] != -1) {
            return farr[start][end];
        }
    }
    int count = 0;
    for(int k=start+1; k<=end-1; k++) {
        int lTrue, lFalse, rTrue, rFalse;
        if(tarr[start][k-1] != -1) {
            lTrue = tarr[start][k-1];
        }
        else {
            lTrue = boolParenthesis_mem(s, start, k-1, true, tarr, farr);
            tarr[start][k-1] = lTrue;
        }
        if(farr[start][k-1] != -1) {
            lFalse = farr[start][k-1];
        }
        else {
            lFalse = boolParenthesis_mem(s, start, k-1, false, tarr, farr);
            farr[start][k-1] = lFalse;
        }
        if(tarr[k+1][end] != -1) {
            rTrue = tarr[k+1][end];
        }
        else {
            rTrue = boolParenthesis_mem(s, k+1, end, true, tarr, farr);
            tarr[k+1][end] = rTrue;
        }
        if(farr[k+1][end] != -1) {
            rFalse = farr[k+1][end];
        }
        else {
            rFalse = boolParenthesis_mem(s, k+1, end, false, tarr, farr);
            farr[k+1][end] = rFalse;
        }

    // -----------    Calculation of Count   -------------

        if(flag == true) {
            if(s[k] == '&') {
                count  +=  (lTrue * rTrue);
            }
            else if(s[k] == '|') {
                count  +=  ((lTrue * rTrue) + (lTrue * rFalse) + (lFalse * rTrue));
            }
            else {    // '^'  ..XOR operator
                count  +=  ((lTrue * rFalse) + (lFalse * rTrue));
            }
        }
        else {    // "False"
            if(s[k] == '&') {
                count  +=  ((lFalse * rTrue) + (lTrue * rFalse) + (lFalse * rFalse));
            }
            else if(s[k] == '|') {
                count  +=  (lFalse * rFalse);
            }
            else {    // '^'  ..XOR operator
                count  +=  ((lTrue * rTrue) + (lFalse * rFalse));
            }
        }
    }
    if(flag == true) {
        tarr[start][end] = count;
    }
    else {
        farr[start][end] = count;
    }
    return count;
}

int booleanParenthesis_mem(string s, int start, int end) {
    int **tarr = new int*[end+2];
    int **farr = new int*[end+2];
    for(int i=0; i<end+2; i++) {
        tarr[i] = new int[end+2];
        farr[i] = new int[end+2];
        for(int j=0; j<end+2; j++) {
            tarr[i][j] = -1;
            farr[i][j] = -1;
            if(i > j) {
                tarr[i][j] = 0;
            }
            if(i == j) {
                if(s[i] == 'T') {
                    tarr[i][j] = 1;
                    farr[i][j] = 0;
                }
                else {
                    farr[i][j] = 1;
                    tarr[i][j] = 0;
                }
            }
        }
    }
    bool flag = true;
    int ans = boolParenthesis_mem(s, start, end, flag, tarr, farr);
    for(int i=0; i<end+2; i++) {
        delete []tarr[i];
        delete []farr[i];
    }
    delete []tarr;
    delete []farr;
    return ans;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int count = booleanParenthesis(s, 0, n-1);
    int count2 = booleanParenthesis_mem(s, 0, n-1);
    cout << count << endl;
    cout << count2 << endl;
    return 0;
}