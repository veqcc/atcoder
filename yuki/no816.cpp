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

bool check(ll a, ll b, ll c) {
    if ((a + b) % c != 0) return false;
    if ((b + c) % a != 0) return false;
    if ((c + a) % b != 0) return false;
    return true;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);

    if (a - b != b && check(a, b, a - b)) {
        cout << a - b << "\n";
        return 0;
    }

    if (check(a, b, a + b)) {
        cout << a + b << "\n";
        return 0;
    }

    cout << -1 << "\n";
    return 0;
}