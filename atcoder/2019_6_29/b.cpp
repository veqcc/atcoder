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

    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if (p[i] > p[i+1] && p[i+1] > p[i+2]) ans++;
        if (p[i] < p[i+1] && p[i+1] < p[i+2]) ans++;
    }

    cout << ans << "\n";
    return 0;
}