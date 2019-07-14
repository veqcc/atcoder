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
typedef pair <int, int> P;
const ll MOD = 1000000007LL;

int n, q;
vector <int> edge[2005];
vector <int> sz(2005);
vector <int> centroids;
vector <int> ngs;

void dfs(int cur, int par) {
    sz[cur] = 1;
    bool is_centroid = true;
    for (int ch : edge[cur]) {
        if (ch == par) continue;
        bool f = true;
        for (int ng : ngs) if (ch == ng) f = false;
        if (!f) continue;

        dfs(ch, cur);
        sz[cur] += sz[ch];
        if (sz[ch] > n / 2) is_centroid = false;
    }
    if (n - sz[cur] > n / 2) is_centroid = false;
    if (is_centroid) centroids.push_back(cur);
}

vector<int> Centroid(int cur, int par) {
    centroids.clear();
    dfs(cur, par);
    return centroids;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int cur = 1;
    while (true) {
        vector <int> centroids = Centroid(cur, 0);

        cur = centroids[0];
        dfs(cur, 0);

        int q1, q2;
        if (centroids.size() == 2) {
            q1 = cur;
            q2 = centroids[1];
        } else {
            vector <P> vec;
            for (int ch : edge[cur]) {
                bool f = true;
                for (int ng : ngs) if (ch == ng) f = false;
                if (!f) continue;
                vec.push_back(P(sz[ch], ch));
            }

            sort(vec.begin(), vec.end(), greater<P>());
            q1 = vec[0].second;
            q2 = vec[1].second;
        }

        cout << "? " << q1 << " " << q2 << endl;
        cout << flush;

        int ans;
        cin >> ans;

        if (centroids.size() == 2) {
            if (ans == q1) {
                ngs.push_back(q2);
                n -= sz[q2];
            } else {
                cur = q2;
                ngs.push_back(q1);
                n = sz[q2];
            }
        } else {
            if (ans == 0) {
                ngs.push_back(q1);
                ngs.push_back(q2);
                n = n - sz[q1] - sz[q2];
            } else {
                ngs.push_back(cur);
                cur = ans;
                n = sz[cur];
            }
        }

        if (n == 1) {
            cout << "! " << cur << endl;
            cout << flush;
            break;
        }
    }

    return 0;
}