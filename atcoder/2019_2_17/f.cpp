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
    int p;
    cin >> p;

    ll x = 1789997546303LL;
    for (int i = 0; i < 1000 - p; i++) {
        if (x % 2 == 1) {
            x = x * 3 + 1;
        } else {
            x /= 2;
        }
    }

    cout << x << "\n";
    return 0;
}