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
    int k;
    cin >> k;

    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(1);
    while (--k) {
        ll v = q.top();
        q.pop();

        if (v < 9) q.push(v + 1);

        ll rem = v % 10;
        if (rem > 0) q.push(v * 10 + rem - 1);
        q.push(v * 10 + rem);
        if (rem < 9) q.push(v * 10 + rem + 1);
    }

    cout << q.top() << endl;
    return 0;
}