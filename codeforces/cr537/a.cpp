#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u') {
                continue;
            } else {
                cout << "No\n";
                return 0;
            }
        } else {
            if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u') {
                cout << "No\n";
                return 0;
            } else {
                continue;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}