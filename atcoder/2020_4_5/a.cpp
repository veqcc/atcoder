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

    int s, l, r;
    cin >> s >> l >> r;

    if (s < l) {
        cout << l << endl;
    } else if (s > r) {
        cout << r << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}