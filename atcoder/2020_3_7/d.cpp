#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    bool flag = true;
    vector <char> str[2];

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            flag ^= 1;
        } else {
            int f;
            char c;
            cin >> f >> c;
            str[flag ^ (f % 2)].push_back(c);
        }
    }

    if (flag) {
        for (int i = str[0].size() - 1; i >= 0; i--) cout << str[0][i];
        cout << s;
        for (char c : str[1]) cout << c;
    } else {
        for (int i = str[1].size() - 1; i >= 0; i--) cout << str[1][i];
        reverse(s.begin(), s.end());
        cout << s;
        for (char c : str[0]) cout << c;
    }

    cout << '\n';
    return 0;
}