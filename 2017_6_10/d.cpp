#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int lc=0, rc=0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            lc++;
        } else {
            if (lc > 0) {
                lc--;
            } else {
                rc++;
            }
        }
    }

    for (int i = 0; i < rc; i++) {
        cout << "(";
    }
    cout << s;
    for (int i = 0; i < lc; i++) {
        cout << ")";
    }

    return 0;
}