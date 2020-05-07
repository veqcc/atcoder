#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair <int, int> P;

int main() {
    int n;
    cin >> n;

    vector<P> order(n - 1);
    vector<vector<int>> edge(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        order[i] = {a, b};
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<P> q;
    q.push({0, -1});

    map<P, int> mp;
    int k = 1;
    while (!q.empty()) {
        P p = q.front();
        q.pop();

        int cur = p.first;
        int par = p.second;

        int idx = 1;
        for (int ch : edge[cur]) {
            if (ch == par) continue;
            if (idx == mp[{cur, par}]) idx++;
            k = max(k, idx);
            mp[{cur, ch}] = idx;
            mp[{ch, cur}] = idx++;
            q.push({ch, cur});
        }
    }

    cout << k << '\n';
    for (int i = 0; i < n - 1; i++) {
        cout << mp[order[i]] << '\n';
    }

    return 0;
}