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

    queue <ll> q;
    for (ll i = 1; i < 10; i++) q.push(i);

    while (--k) {
        ll p = q.front();
        q.pop();

        if (p % 10 != 0) q.push(p * 10 + p % 10 - 1);
        q.push(p * 10 + p % 10);
        if (p % 10 != 9) q.push(p * 10 + p % 10 + 1);
    }

    cout << q.front() << "\n";
    return 0;
}