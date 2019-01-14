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
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll need = 0LL;
    ll give = 0LL;
    int need_count = 0;
    vector <ll> givers;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            need_count++;
            need += b[i] - a[i];
        } else {
            give += a[i] - b[i];
            givers.push_back(a[i] - b[i]);
        }
    }

    if (need > give) {
        cout << -1 << endl;
    } else {
        sort(givers.begin(), givers.end(), greater<ll>());
        int p = 0;
        while (need > 0) {
            need -= givers[p];
            p++;
            need_count++;
        }
        cout << need_count << "\n";
    }

    return 0;
}