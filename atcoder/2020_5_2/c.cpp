#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector <int> a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    auto dfs = [&](auto dfs, vector<int> vec, int k) -> int {
        int ret = 0;
        if (k < n) {
            for (int i = vec[k]; i <= m; i++) {
                vec[k + 1] = i;
                ret = max(ret, dfs(dfs, vec, k + 1));
            }
        } else {
            for (int i = 0; i < q; i++) {
                if (vec[b[i]] - vec[a[i]] == c[i]) ret += d[i];
            }
        }
        return ret;
    };

    vector<int> vec(n + 1, 1);
    cout << dfs(dfs, vec, 0) << "\n";
    return 0;
}