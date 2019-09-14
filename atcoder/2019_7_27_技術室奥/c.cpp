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

    ll n;
    string x;
    cin >> n >> x;

    for (ll i = 2; i < 11; i++) {
        ll cur = 0;
        for (char c : x) {
            cur = cur * i + c - '0';
        }

        if (cur == n) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}