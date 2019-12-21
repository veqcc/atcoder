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
using namespace std;
typedef pair <int, int> P;

bool visited[500005];
void dfs(vector<vector<int>> &edge, int cur) {
    visited[cur] = true;
    for (int ch : edge[cur]) {
        if (!visited[ch]) {
            dfs(edge, ch);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <P> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
        segments[i].first--;
        segments[i].second--;
    }

    sort(segments.begin(), segments.end());
    vector <int> mp(2 * n);
    for (int i = 0; i < n; i++) {
        mp[segments[i].second] = i;
    }

    vector <vector<int>> edge(n, vector<int>());
    int count = 0;
    set <int> st;
    for (int i = 0; i < n; i++) {
        int l = segments[i].first;
        int r = segments[i].second;
        auto l_itr = st.lower_bound(l);
        auto r_itr = st.lower_bound(r);
        for (auto itr = l_itr; itr != r_itr; itr++) {
            int j = mp[*itr];
            edge[i].push_back(j);
            edge[j].push_back(i);
            count++;
            if (count >= n) {
                cout << "NO\n";
                return 0;
            }
        }
        st.insert(r);
    }

    if (count != n - 1) {
        cout << "NO\n";
        return 0;
    }

    fill(visited, visited + n, false);
    dfs(edge, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}