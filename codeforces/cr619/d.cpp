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
typedef pair <int, string> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if (4 * n * m - 2 * n - 2 * m < k) {
        cout << "NO" << '\n';
        return 0;
    }

    vector <P> ans;
    int cur = 0;

    if (m == 1) {
        for (int i = 0; i < n - 1; i++) {
            if (cur == k) break;
            ans.push_back({1, "D"});
            cur++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (cur == k) break;
            ans.push_back({1, "U"});
            cur++;
        }
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for (P p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
        return 0;
    } else if (n == 1) {
        for (int i = 0; i < m - 1; i++) {
            if (cur == k) break;
            ans.push_back({1, "R"});
            cur++;
        }
        for (int i = 0; i < m - 1; i++) {
            if (cur == k) break;
            ans.push_back({1, "L"});
            cur++;
        }
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for (P p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
        return 0;
    }

    int phase;
    while (cur < (n - 1) * (4 * m - 3)) {
        if (cur + 3 * (m - 1) <= k) {
            ans.push_back({m - 1, "RDU"});
            cur += 3 * (m - 1);
        } else {
            phase = 1;
            break;
        }

        if (cur + m - 1 <= k) {
            ans.push_back({m - 1, "L"});
            cur += m - 1;
        } else {
            phase = 2;
            break;
        }

        if (cur + 1 <= k) {
            ans.push_back({1, "D"});
            cur += 1;
        } else {
            phase = 3;
            break;
        }
    }

    if (cur == (n - 1) * (4 * m - 3)) {
        for (int i = 0; i < m - 1; i++) {
            if (cur == k) break;
            ans.push_back({1, "R"});
            cur++;
        }

        for (int i = 0; i < m - 1; i++) {
            if (cur == k) break;
            ans.push_back({1, "L"});
            cur++;
        }

        for (int i = 0; i < n - 1; i++) {
            if (cur == k) break;
            ans.push_back({1, "U"});
            cur++;
        }
    } else {
        if (phase == 1) {
            for (int i = 0; i < m - 1; i++) {
                if (cur == k) break;
                ans.push_back({1, "R"});
                cur++;

                if (cur == k) break;
                ans.push_back({1, "D"});
                cur++;

                if (cur == k) break;
                ans.push_back({1, "U"});
                cur++;
            }
        } else if (phase == 2) {
            for (int i = 0; i < m - 1; i++) {
                if (cur == k) break;
                ans.push_back({1, "L"});
                cur++;
            }
        }
    }

    cout << "YES" << '\n';
    cout << ans.size() << '\n';

    for (P p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}