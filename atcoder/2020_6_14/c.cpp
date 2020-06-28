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
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int ans = 1000000;
    for (int i = 0; i <= 101; i++) {
        bool exist = false;
        for (int j = 0; j < n; j++) {
            if (i == p[j]) {
                exist = true;
                break;
            }
        }
        if (!exist && abs(x - i) < abs(x - ans)) {
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}