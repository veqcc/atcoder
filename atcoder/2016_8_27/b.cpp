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
    int len = s.length();

    int rparen = 0;
    int ans = 0;
    bool found_right = false;
    for (int i = len-1; i >= 0; i--) {
        if (s[i] == ')') {
            rparen++;
        } else {
            if (rparen == 0) {
                rparen++;
                if (!found_right) {
                    ans += i;
                    found_right = true;
                }
                ans++;
            } else {
                rparen--;
            }
        }
    }

    if (!found_right) {
        int remain = rparen;
        for (int i = 0; i < len; i++) {
            if (s[i] == ')') {
                remain -= 2;
                if (remain == 0) {
                    ans += i;
                }
            }
        }
    }

    cout << ans + rparen / 2 << "\n";
    return 0;
}