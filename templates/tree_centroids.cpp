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

int main() {
    return 0;
}