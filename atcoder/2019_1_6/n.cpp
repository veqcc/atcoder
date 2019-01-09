#include <algorithm>
#include <iostream>
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

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ret = 0LL;

    for (int i = 0; i < n-1; i++) {
        ll mn = 1LL << 60;
        int mn_j = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] + a[j+1] < mn) {
                mn = a[j] + a[j+1];
                mn_j = j;
            }
        }

        ret += mn;
        a[mn_j] = mn;
        for (int j = mn_j+1; j < n - i - 1; j++) {
            a[j] = a[j+1];
        }
    }

    cout << ret << "\n";
    return 0;
}