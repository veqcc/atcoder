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

    ll n, a;
    cin >> n;

    ll mn = 1LL << 60;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        mn = min(mn, a);
    }

    cout << 5 + (n - 1) / mn << "\n";
    return 0;
}