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

    int n, m;
    cin >> n >> m;

    int ac = 0;
    vector <bool> aced(n, false);
    vector <int> wa_count(n, 0);

    for (int i = 0; i < m; i++) {
        int p;
        string s;
        cin >> p >> s;
        p--;

        if (!aced[p]) {
            if (s == "WA") {
                wa_count[p]++;
            } else {
                ac++;
                aced[p] = true;
            }
        }
    }

    int wa = 0;
    for (int i = 0; i < n; i++) {
        if (aced[i]) {
            wa += wa_count[i];
        }
    }

    cout << ac << ' ' << wa << "\n";
    return 0;
}