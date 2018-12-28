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

    ll x, y;
    cin >> x >> y;

    if (abs(x-y) <= 1LL) {
        cout << "Brown\n";
    } else {
        cout << "Alice\n";
    }

    return 0;
}