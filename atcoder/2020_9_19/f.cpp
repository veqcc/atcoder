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
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) a[i] = b[i] = N;

    ll black = ll(N - 2) * (N - 2);

    int H = N, W = N;

    while (Q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            if (x < W) {
                for (int i = x; i < W; ++i) {
                    b[i] = H;
                }
                W = x;
            }
            black -= b[x] - 2;

        } else {
            if (x < H) {
                for (int i = x; i < H; ++i) {
                    a[i] = W;
                }
                H = x;
            }
            black -= a[x] - 2;
        }
    }
    cout << black << endl;

    return 0;
}