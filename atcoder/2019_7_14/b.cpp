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
typedef pair <int, int> P;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> edge[100005];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    if (m % 2 == 1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> size(n);
    vector<int> sum(n, 0);
    vector<bool> visited(n, false);

    priority_queue <P, vector<P>, greater<P>> q;

    int mn = 1 << 30;
    for (int i = 0; i < n; i++) {
        size[i] = edge[i].size();
        mn = min(mn, size[i]);
    }

    for (int i = 0; i < n; i++) {
        if (size[i] == mn) {
            q.push(P(size[i], i));
        }
    }

    while (q.size()) {
        P p = q.top();
        q.pop();

        int cur = p.second;
        if (visited[cur]) continue;
        visited[cur] = true;

        int mx = -1;
        int mx_idx = -1;

        if (sum[cur] % 2 == 1) {
            for (int ch : edge[cur]) {
                if (visited[ch]) continue;

                if (size[ch] > mx) {
                    mx = size[ch];
                    mx_idx = ch;
                }
            }
        }

        for (int ch : edge[cur]) {
            if (visited[ch]) continue;

            if (ch == mx_idx) {
                cout << cur + 1 << " " << ch + 1 << "\n";
            } else {
                cout << ch + 1 << " " << cur + 1 << "\n";
                sum[ch]++;
            }

            size[ch]--;
            q.push(P(size[ch], ch));
        }
    }

    return 0;
}