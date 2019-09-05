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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <P> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].first;
        d[i].second = 2 * i;
    }

    sort(d.begin(), d.end(), greater<P>());

    vector<vector<int>> edge(2 * n);
    vector <int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = d[i].second;

    for (int i = 0; i < n - 1; i++) {
        int idx1 = d[i].second;
        int idx2 = d[i + 1].second;
        int j = i + d[i].first - 1;
        if (j == idx.size() - 1) idx.push_back(idx1 + 1);

        edge[idx1].push_back(idx2);
        edge[idx2].push_back(idx1);

        int dist = idx[j];
        edge[idx1 + 1].push_back(dist);
        edge[dist].push_back(idx1 + 1);
    }

    int idx1 = d[n - 1].second;
    int dist = idx[n + d[n - 1].first - 2];
    edge[idx1 + 1].push_back(dist);
    edge[dist].push_back(idx1 + 1);

    for (int i = 0; i < 2 * n; i++) {
        for (int j : edge[i]) {
            if (i < j) {
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }

    return 0;
}