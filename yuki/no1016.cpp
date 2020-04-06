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

    int T;
    cin >> T;
    vector <char> ans(T);

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool win = false;

        for (int i = 0; i < n - 2; i++) {
            string str = s.substr(i, 3);
            if (str == "ooo") win = true;
            if (str == "oo-") win = true;
            if (str == "-oo") win = true;
        }

        for (int i = 0; i < n - 3; i++) {
            string str = s.substr(i, 4);
            if (str == "--o-") win = true;
            if (str == "-o--") win = true;
        }

        for (int i = 0; i < n - 4; i++) {
            string str = s.substr(i, 5);
            if (str == "o--o-") win = true;
            if (str == "-o--o") win = true;
        }

        bool on = false;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (on) {
                if (s[i] == 'o') {
                    if (cur % 2 == 1) {
                        win = true;
                        break;
                    }
                } else if (s[i] == '-') {
                    cur++;
                } else {
                    on = false;
                }
            } else {
                if (s[i] == 'o') {
                    on = true;
                    cur = 0;
                }
            }
        }

        ans[t] = win ? 'O' : 'X';
    }

    for (char c : ans) cout << c << '\n';
    return 0;
}