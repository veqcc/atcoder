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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    vector<vector<int>> a(3);
    for (int i = 0; i < 3; i++) {
        int p;
        cin >> p;
        a[i].resize(p, 0);
        n += p;
    }

    vector <int> vec(n - 1);
    for (int i = 1; i < n; i++) vec[i - 1] = i;

    int ans = 0;
    do {
        bool ok = true;
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                if (i == 0 && j == 0) continue;
                a[i][j] = vec[idx++];
                if (i > 0 && a[i][j] < a[i - 1][j]) ok = false;
                if (j > 0 && a[i][j] < a[i][j - 1]) ok = false;
            }
        }
        if (ok) ans++;
    } while (next_permutation(vec.begin(), vec.end()));

    cout << ans << "\n";
    return 0;
}