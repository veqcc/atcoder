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

    int N;
    string s;
    cin >> N >> s;

    int fst[4] = {1, 1, -1, -1};
    int scd[4] = {1, -1, 1, -1};

    for (int cnt = 0; cnt < 4; cnt++) {
        int ans[N];
        ans[0] = fst[cnt];
        ans[1] = scd[cnt];

        for (int i = 1; i < N-1; i++) {
            if (s[i] == 'o') {
                ans[i+1] = ans[i-1] * ans[i];
            } else {
                ans[i+1] = - ans[i-1] * ans[i];
            }
        }

        bool possible = true;
        if (s[N-1] == 'o') {
            if (ans[N-2] != ans[0] * ans[N-1]) {
                possible = false;
            }
        } else {
            if (ans[N-2] != - ans[0] * ans[N-1]) {
                possible = false;
            }
        }

        if (s[0] == 'o') {
            if (ans[N-1] != ans[1] * ans[0]) {
                possible = false;
            }
        } else {
            if (ans[N-1] != - ans[1] * ans[0]) {
                possible = false;
            }
        }

        if (possible) {
            for (int i = 0; i < N; i++) {
                if (ans[i] == 1) {
                    cout << 'S';
                } else {
                    cout << 'W';
                }
            }
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}