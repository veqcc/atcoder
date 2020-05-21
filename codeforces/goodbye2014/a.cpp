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

    int n, t;
    cin >> n >> t;

    int cur = 1;
    bool ans = false;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        if (i == cur) cur += a;
        if (cur == t) ans = true;
    }

    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}