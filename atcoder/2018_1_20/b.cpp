#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <cstring>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    stack <char> st;
    int pos = 0;
    string now = "";
    while (pos < s.length()) {
        if (s[pos] == '(') {
            now = st.top();
            cout << s[pos++];
        } else if (s[pos] == ')') {
            st.pop();
            if (st.size() > 0) now = st.top();
            cout << s[pos++];
        } else if (strchr("+*-/", s[pos]) != NULL) {
            st.push(s[pos++]);
        } else if (s[pos] == ',') {
            cout << now;
            pos++;
        } else if (isdigit(s[pos])) {
            int bg = pos;
            while (pos < s.length() && isdigit(s[pos])) {
                pos++;
            }
            int ed = pos - 1;
            cout << s.substr(bg, ed-bg+1);
        } else {
            break;
        }
    }

    return 0;
}