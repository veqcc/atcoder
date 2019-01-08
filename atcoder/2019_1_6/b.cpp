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
const int INF = 1 << 30;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int cost[n];
    fill(cost, cost+n, INF);
    cost[0] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 1; j <= k; j++) {
            if (i+j < n) {
                cost[i+j] = min(cost[i+j], cost[i] + abs(h[i] - h[i+j]));
            }
        }
    }

    cout << cost[n-1] << "\n";
    return 0;
}