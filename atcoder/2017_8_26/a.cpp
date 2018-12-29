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

    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    ll one = min({4*q, 2*h, s});
    ll two = min(2*one, d);

    cout << n/2*two + (n%2)*one << "\n";
    return 0;
}