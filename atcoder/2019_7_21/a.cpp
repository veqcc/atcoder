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

    ll S;
    cin >> S;

    ll x1 = 1000000000;
    cout << 0 << " " << 0 << " " << x1 << " ";

    ll y1 = (S + x1 - 1) / x1;
    cout << x1 * y1 - S << " " << 1 << " " << y1 << '\n';

    return 0;
}