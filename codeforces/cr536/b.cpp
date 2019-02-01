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

    int n, m;
    cin >> n >> m;

    ll count[n], cost[n];
    vector < pair<ll, int> > vec;
    for (int i = 0; i < n; i++) {
        cin >> count[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        vec.push_back(make_pair(cost[i], i));
    }

    sort(vec.begin(), vec.end());
    int cur = 0;

    int t[m];
    ll d[m];
    for (int i = 0; i < m; i++) {
        cin >> t[i] >> d[i];
        t[i]--;
    }

    for (int i = 0; i < m; i++) {
        if (count[t[i]] >= d[i]) {
            cout << cost[t[i]] * d[i] << "\n";
            count[t[i]] -= d[i];
        } else {
            ll ret = count[t[i]] * cost[t[i]];
            ll remain = d[i] - count[t[i]];
            count[t[i]] = 0;

            while (remain) {
                if (cur == n) {
                    ret = 0;
                    break;
                }

                int j = vec[cur].second;
                if (count[j] >= remain) {
                    ret += remain * vec[cur].first;
                    count[j] -= remain;
                    break;
                } else {
                    ret += count[j] * vec[cur].first;
                    remain -= count[j];
                    count[j] = 0;
                    cur++;
                }
            }
            cout << ret << "\n";
        }
    }

    return 0;
}