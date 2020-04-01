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

    int k;
    cin >> k;

    int cur = 1;
    while (cur <= k) cur *= 2;

    cout << 2 << ' ' << 3 << '\n';
    cout << cur + k << ' ' << k << ' ' << 0 << '\n';
    cout << cur << ' ' << cur + k << ' ' << k << '\n';

    return 0;
}