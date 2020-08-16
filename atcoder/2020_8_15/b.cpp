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
    int n;
    cin >> n;

    vector<int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (l[i] == l[j]) continue;
            for (int k = j + 1; k < n; k++) {
                if (l[k] == l[i] || l[k] == l[j]) continue;
                if (l[i] + l[j] > l[k] && abs(l[i] - l[j]) < l[k]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}