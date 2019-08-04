#include <vector>
using namespace std;

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


// verified
//   https://github.com/veqcc/atcoder/blob/a48a72336eb4f33cf8d34d9f6c10df9d4858c7e1/atcoder/2017_12_16/f.cpp
//   https://github.com/veqcc/atcoder/blob/26a8b8a7a535b9d4c2b0ad068310cfb8b4487ede/atcoder/2018_1_13/e.cpp
//   https://github.com/veqcc/atcoder/blob/d60abbdc12fdfaeffe6241c983dafc558d4fba38/atcoder/2017_7_23/d.cpp

int main() {
    return 0;
}