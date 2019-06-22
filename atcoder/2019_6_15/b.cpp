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

    int x[n], y[n];
    vector <P> pq;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        for (int j = 0; j < i; j++) {
            int p = x[i] - x[j];
            int q = y[i] - y[j];
            pq.push_back(P(p, q));
            pq.push_back(P(-p, -q));
        }
    }

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    int ans = 1 << 30;
    for (P tmp : pq) {
        int p = tmp.first;
        int q = tmp.second;

        int c = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[j] == x[i] - p && y[j] == y[i] - q) {
                    c--;
                }
            }
        }

        ans = min(ans, c);
    }

    cout << ans << '\n';
    return 0;
}