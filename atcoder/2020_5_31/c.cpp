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
    ll a;
    string b;
    cin >> a >> b;
    ll ans = 0;
    ans += a * (b[0] - '0') * 100;
    ans += a * (b[2] - '0') * 10;
    ans += a * (b[3] - '0');
    cout << ans / 100 << endl;
    return 0;
}