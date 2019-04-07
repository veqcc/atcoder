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

    int n;
    cin >> n;

    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] != c[0]) mx = max(mx, i);
        if (c[n-1] != c[i]) mx = max(mx, n - i - 1);
    }

    cout << mx << "\n";
    return 0;
}