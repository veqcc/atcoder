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

    int x, y, z, K;
    cin >> x >> y >> z >> K;

    ll A[x], B[y], C[z];
    for (int i = 0; i < x; i++) cin >> A[i];
    for (int i = 0; i < y; i++) cin >> B[i];
    for (int i = 0; i < z; i++) cin >> C[i];

    sort(A, A+x, greater<ll>());
    sort(B, B+y, greater<ll>());
    sort(C, C+z, greater<ll>());

    priority_queue <ll, vector <ll>, greater<ll> > q;
    for (ll a : A) {
        for (ll b : B) {
            for (ll c : C) {
                ll sm = a + b + c;

                if (q.size() < K) {
                    q.push(sm);
                } else {
                    if (sm <= q.top()) {
                        break;
                    } else {
                        q.pop();
                        q.push(sm);
                    }
                }
            }
        }
    }

    int i = K-1;
    vector <ll> ans(K);
    while (q.size()) {
        ans[i--] = q.top();
        q.pop();
    }

    for (ll ret : ans) cout << ret << "\n";
    return 0;
}