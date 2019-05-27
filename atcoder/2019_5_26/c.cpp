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

    int n, m;
    cin >> n >> m;

    vector < vector <int> > vec(m, vector <int>());
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s;
            cin >> s;
            s--;
            vec[i].push_back(s);
        }
    }

    vector <int> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        bool f = true;

        for (int j = 0; j < m; j++) {
            int sz = vec[j].size();

            int cnt = 0;
            for (int k = 0; k < sz; k++) {
                int s = vec[j][k];
                if (i & (1 << s)) {
                    cnt++;
                }
            }

            if (cnt % 2 != p[j]) f = false;
        }

        if (f) ans++;
    }

    cout << ans << "\n";
    return 0;
}