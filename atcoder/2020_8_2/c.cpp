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

    int i = 1, cur = 7;
    for (; i <= k; i++) {
        if (cur % k == 0) {
            cout << i << endl;
            return 0;
        }
        cur = (cur * 10 + 7) % k;
    }

    cout << -1 << endl;
    return 0;
}