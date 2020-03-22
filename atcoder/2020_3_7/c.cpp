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

    int a, b;
    cin >> a >> b;

    for (int i = 1; i < 100000; i++) {
        if (i * 108 / 100 == i + a && i * 11 / 10 == i + b) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}