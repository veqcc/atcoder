#include <algorithm>
#include <iostream>
#include <iomanip>
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

int n, k;
ll A, B, a[100005];

ll dfs(int left, int right) {
    ll count = upper_bound(a, a+k, right) - upper_bound(a, a+k, left);

    if (count == 0LL) {
        return A;
    } else {
        if (right - left == 1) {
            return B * count;
        }
        int mid = (right + left) / 2;
        return min(B * count * (right - left) ,dfs(left, mid) + dfs(mid, right));
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> A >> B;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    sort(a, a+k);

    cout << dfs(0, (1 << n)) << "\n";
    return 0;
}