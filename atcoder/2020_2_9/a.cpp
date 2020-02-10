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

    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;

    if (s == u) {
        cout << a - 1 << ' ' << b << '\n';
    } else {
        cout << a << ' ' << b - 1 << '\n';
    }

    return 0;
}