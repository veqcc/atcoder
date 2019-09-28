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

    int h, w, a, b;
    cin >> h >> w >> a >> b;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j < a && i < b) {
                cout << 1;
            } else if (j >= a && i >= b) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}