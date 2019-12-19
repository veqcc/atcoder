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
typedef pair <int, ll> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <ll> sm(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        u--; v--;
        sm[u] += d;
        sm[v] -= d;
    }

    vector <P> plus, minus;
    for (int i = 0; i < n; i++) {
        if (sm[i] > 0) {
            plus.push_back(P(i, sm[i]));
        } else if (sm[i] < 0) {
            minus.push_back(P(i, -sm[i]));
        }
    }

    int count = 0, p_idx = 0, m_idx = 0;
    vector <vector<P>> ans(n);
    while (true) {
        if (p_idx == plus.size()) {
            break;
        }

        count++;
        int p_node = plus[p_idx].first;
        int m_node = minus[m_idx].first;
        ll p_val = plus[p_idx].second;
        ll m_val = minus[m_idx].second;
        if (p_val < m_val) {
            ans[m_node].push_back(P(p_node, p_val));
            minus[m_idx].second -= p_val;
            p_idx++;
        } else if (p_val > m_val) {
            ans[m_node].push_back(P(p_node, m_val));
            plus[p_idx].second -= m_val;
            m_idx++;
        } else {
            ans[m_node].push_back(P(p_node, p_val));
            p_idx++;
            m_idx++;
        }
    }

    cout << count << "\n";
    for (int i = 0; i < n; i++) {
        for (P p : ans[i]) {
            cout << p.first + 1 << ' ' << i + 1 << ' ' << p.second << '\n';
        }
    }

    return 0;
}