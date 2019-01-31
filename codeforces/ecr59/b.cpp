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
    ll k[n];
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> k[i] >> x[i];
        k[i]--;
    }

    for (int i = 0; i < n; i++) {
        cout << x[i] + 9 * k[i] << "\n";
    }

    return 0;
}