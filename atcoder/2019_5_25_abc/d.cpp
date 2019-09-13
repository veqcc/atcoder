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

    vector <P> vec(n + m);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
        vec[i].second = 1;
    }
    for (int i = n; i < n + m; i++) cin >> vec[i].second >> vec[i].first;

    sort(vec.begin(), vec.end(), greater<P>());

    int cur = n;
    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        if (vec[i].second < cur) {
            ans += vec[i].first * vec[i].second;
        } else {
            ans += vec[i].first * cur;
            break;
        }
        cur -= vec[i].second;
    }

    cout << ans << "\n";
    return 0;
}