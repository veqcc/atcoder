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

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if (k < a) {
        cout << k << endl;
    } else {
        k -= a;
        if (k < b) {
            cout << a << endl;
        } else {
            k -= b;
            cout << a - k << endl;
        }
    }

    return 0;
}