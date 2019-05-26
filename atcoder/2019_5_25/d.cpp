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
typedef pair <ll, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A.begin(), A.end(), greater<ll>());

    vector <P> BC(m);
    for (int i = 0; i < m; i++) {
        int b;
        ll c;
        cin >> b >> c;
        BC[i] = P(c, b);
    }

    sort(BC.begin(), BC.end(), greater<P>());

    ll ans = 0LL;
    int Aidx = 0;
    int Bidx = 0;
    for (int i = 0; i < n; i++) {
        if (Bidx >= m) {
            ans += A[Aidx];
            Aidx++;
        } else {
            if (A[Aidx] >= BC[Bidx].first) {
                ans += A[Aidx];
                Aidx++;
            } else {
                ans += BC[Bidx].first;
                BC[Bidx].second--;
                if (BC[Bidx].second == 0) Bidx++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}