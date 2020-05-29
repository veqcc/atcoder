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
    int n, m;
    cin >> n;
    vector<int> boy(n);
    for (int i = 0; i < n; i++) cin >> boy[i];
    cin >> m;
    vector<int> girl(m);
    for (int i = 0; i < m; i++) cin >> girl[i];

    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());

    int ans = 0;
    int p1 = 0, p2 = 0;
    while (p1 < n && p2 < m) {
        if (abs(boy[p1] - girl[p2]) < 2) {
            p1++;
            p2++;
            ans++;
        } else if (boy[p1] > girl[p2]) {
            p2++;
        } else if (boy[p1] < girl[p2]) {
            p1++;
        }
    }

    cout << ans << endl;
    return 0;
}