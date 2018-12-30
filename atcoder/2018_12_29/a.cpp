#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    if (c <= b + a) {
        cout << b + c;
    } else {
        cout << 2LL * b + a + 1LL;
    }

    return 0;
}