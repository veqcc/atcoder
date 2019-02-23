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
    cout.tie(0);

    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << -1 << "\n";
        return 0;
    }

    if (s[0] != '1') {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '3') {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << s.size() - 1 << "\n";
    return 0;
}