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
const int MAX_N = 5005;
const ll MOD = 1000000007LL;

vector<int> Centroid(const vector<vector<int>> &edge) {
    int n = edge.size();
    vector<int> centroids;
    vector<int> sz(n);
    function<void(int, int)> dfs = [&](int cur, int par) {
        sz[cur] = 1;
        bool is_centroid = true;
        for (int ch : edge[cur]) {
            if (ch == par) continue;
            dfs(ch, cur);
            sz[cur] += sz[ch];
            if (sz[ch] > n / 2) is_centroid = false;
        }
        if (n - sz[cur] > n / 2) is_centroid = false;
        if (is_centroid) centroids.push_back(cur);
    };
    dfs(0, -1);
    return centroids;
}

ll inv[MAX_N], fac[MAX_N], fiv[MAX_N];

void COMinit() {
    inv[1] = fac[1] = fiv[1] = inv[0] = fac[0] = fiv[0] = 1;
    for (ll i = 2; i < MAX_N; i++) {
        fac[i] = fac[i - 1] * i % MOD; // n!
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
    }
}

ll com(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * fiv[k] % MOD * fiv[n-k] % MOD;
}

vector <int> sz(5005);
int dfs(vector<vector<int>> &edge, int cur, int par) {
    int sum = 1;
    for (int ch : edge[cur]) {
        if (ch == par) continue;
        sum += dfs(edge, ch, cur);
    }
    sz[cur] = sum;
    return sum;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector <vector<int>> edge(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    COMinit();

    vector<int> centroids = Centroid(edge);

    if (centroids.size() == 2) {
        cout << fac[n / 2] * fac[n / 2] % MOD << "\n";
        return 0;
    }

    int center = centroids[0];
    dfs(edge, center, -1);

    vector<int> children(1, 0);
    for (int v : edge[center]) children.push_back(sz[v]);

    sort(children.begin(), children.end());
    int ch = children.size();

    ll dp[ch][n];
    fill(dp[0], dp[ch], 0LL);
    // dp[i][j] : i番目の部分木において、j個が自分の部分木に戻る場合の数

    dp[0][0] = 1;
    int sum = 0;
    for (int i = 1; i < ch; i++) {
        int cur_sz = children[i];

        for (ll j = 0; j <= cur_sz; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[i][k + j] += dp[i - 1][k] * com(cur_sz, j) % MOD * com(cur_sz, j) % MOD * fac[j] % MOD;
                dp[i][k + j] %= MOD;
            }
        }

        sum += cur_sz;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll sgn = i % 2 == 0 ? 1 : -1;
        ll tmp = fac[n - i] * dp[ch-1][i] % MOD;
        tmp = (sgn * tmp + MOD) % MOD;
        ans = (ans + tmp) % MOD;
    }

    cout << ans << '\n';
    return 0;
}