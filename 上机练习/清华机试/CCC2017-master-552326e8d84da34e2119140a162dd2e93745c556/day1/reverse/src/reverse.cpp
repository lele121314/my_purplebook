#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
    getline(cin, s);
    reverse(s.begin(), s.end());
    string::iterator last = s.begin();
    for (string::iterator it=s.begin(); it!=s.end(); it++) {
        if (*it == ' ') {
            if (last < it) reverse(last, it);
            last = it+1;
        }
    }
    if (last < s.end()) reverse(last, s.end());
    
    cout << s << endl;
}
