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

    int n, k, c;
    cin >> n >> k >> c;

    string s;
    cin >> s;

    vector <bool> ans(n, false); // 働かなくてもいい日はtrue
    vector <int> work;
    int prev = -c-1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            if (prev + c < i && work.size() < k) {
                work.push_back(i);
                prev = i;
            } else {
                ans[i] = true;
            }
        }
    }

    int idx = k - 1;
    prev = n + c + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'x') continue;
        if (i > work[idx]) {
            if (i + c < prev) {
                ans[work[idx]] = true;
                prev = i;
                idx--;
            }
        } else if (i == work[idx]) {
            idx--;
            prev = i;
        }

        if (idx == -1) break;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'o' && ans[i] == false) {
            cout << i + 1 << '\n';
        }
    }

    return 0;
}