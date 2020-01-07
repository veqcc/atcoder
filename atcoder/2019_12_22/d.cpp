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

    int n;
    cin >> n;

    int cur = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == cur) cur++;
    }

    if (cur == 1) {
        cout << -1 << '\n';
    } else {
        cout << n - cur + 1 << '\n';
    }

    return 0;
}