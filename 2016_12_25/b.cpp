#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    ll s[n], p[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        p[i] = max(s[i], 0LL);
        if (i > 0) {
            s[i] += s[i-1];
            p[i] += p[i-1];
        }
    }

    ll score = 0;
    for (int i = 0; i <= n-k; i++) {
        ll tmp = s[i+k-1];
        if (i > 0) {
            tmp -= s[i-1];
        }
        tmp = max(tmp, 0LL);

        if (i > 0) {
            tmp += p[i-1];
        }
        tmp += p[n-1];
        tmp -= p[i+k-1];

        score = max(score, tmp);
    }

    cout << score << "\n";
    return 0;
}