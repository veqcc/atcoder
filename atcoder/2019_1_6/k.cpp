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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    bool dp[k+1];
    fill(dp, dp+k+1, false);
    for (int i = a[0]; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && !dp[i - a[j]]) {
                dp[i] = true;
            }
        }
    }

    if (dp[k]) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }

    return 0;
}