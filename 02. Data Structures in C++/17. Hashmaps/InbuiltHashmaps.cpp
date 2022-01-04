#include <iostream>
#include <map>  // Implemented using BST, all operations -- O(logN)
#include <unordered_map>  // Implemented using Hashtables, all operations -- O(N)
                          // Elements are stored in both maps as inbuilt pair class.
#include <vector>
#include <string>
using namespace std;

int main() {
    // -------- D E C L A R A T I O N --------
    unordered_map <string, int> ourmap;

    // -------- I N S E R T ---------
    pair<string, int> p("abc", 1);  // inbuilt pair class
    ourmap.insert(p);   // insert function
    ourmap["def"] = 1;  // can also insert this way.
    ourmap["abc"] = 2;  // If key present in map, edits the corresponding value of key
    
    // -------- S I Z E ---------
    cout << "Size : " << ourmap.size() << endl; // same .size() function in all STL

    // -------- F I N D ---------
    cout << ourmap.at("abc") << endl; //If key not present, gives error  ..  can't edit the value with this.
    cout << ourmap["ghi"] << endl; //If key not present, inserts 0 value and returns.
    
    // -------- C O U N T ---------
    if(ourmap.count("def") > 0) {  // Returns only 2 values, 0 and 1.
        cout << "Key (def) is present" << endl;
    }
    else {
        cout << "Key (def) is not present" << endl;
    }

    // -------- D E L E T E ---------
    ourmap.erase("def");  // Erase function.
    cout << "Size : " << ourmap.size() << endl;
    return 0;
}