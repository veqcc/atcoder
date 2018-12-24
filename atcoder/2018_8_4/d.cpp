#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int N, M;
bool loop[1005][1005];

int rev(int x) {
    int ret = 0;
    while (x > 0) {
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

bool dfs(int i, int j) {
    bool &ret = loop[i][j];
    if (ret) return ret;
    if (i == 0 || j == 0) return ret;

    ret = true;
    i < j ? i = rev(i) : j = rev(j);
    i < j ? j -= i : i -= j;
    if (!dfs(i, j)) ret = false;

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (dfs(i, j)) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}