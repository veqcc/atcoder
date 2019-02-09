#include <algorithm>
#include <iostream>
#include <iomanip>
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
    cout.tie(0);

    ll n, m, a;
    cin >> n >> m >> a;
    ll h = n % a == 0 ? n / a : n / a + 1;
    ll w = m % a == 0 ? m / a : m / a + 1;

    cout << h * w << "\n";
    return 0;
}