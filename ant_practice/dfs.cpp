#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const int MAX_N = 20;
int n, k;
int a[MAX_N];

bool dfs(int i, int sum) {
    if (i == n) return sum == k;
    if (dfs(i+1, sum)) return true;
    if (dfs(i+1, sum+a[i])) return true;
    return false;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ans = dfs(0, 0);

    if (ans) cout << "Yes";
    else cout << "No";

    return 0;
}