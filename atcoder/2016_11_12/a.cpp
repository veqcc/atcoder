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

    int h, w;
    cin >> h >> w;

    bool possible = true;
    int mn = 0, mx = 0;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = w-1; j >= 0; j--) if (s[j] == '#') mn = j;
        if (mx != mn) possible = false;
        for (int j = mn; j < w; j++) if (s[j] == '#') mx = j;
    }

    cout << (possible ? "Possible" : "Impossible") << "\n";
    return 0;
}