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

    int mx = 0;
    int sm = 0;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        sm += l;
        mx = max(mx, l);
    }

    if (mx < sm - mx) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}