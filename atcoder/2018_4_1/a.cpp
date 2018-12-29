#include <algorithm>
#include <iostream>
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

    string s;
    cin >> s;

    if (s.size() < 26) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.find(c) == -1) {
                cout << s << c << endl;
                return 0;
            }
        }
    } else {
        bool up[25];
        fill(up, up+25, true);
        bool all_up = true;
        for (int i = 0; i < 25; i++) {
            if (s[i] < s[i+1]) {
                up[i] = false;
                all_up = false;
            }
        }

        if (all_up) {
            cout << -1 << endl;
            return 0;
        } else {
            for (int i = 24; i >= 0; i--) {
                if (!up[i]) {
                    for (int j = 25; j > i; j--) {
                        if (s[i] < s[j]) {
                            cout << s.substr(0, i) << s[j] << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}