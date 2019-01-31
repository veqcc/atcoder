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

    int n, k;
    cin >> n >> k;

    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string S;
    cin >> S;

    char s = 'A';
    ll ans = 0LL;
    priority_queue <ll, vector<ll>, greater<ll> > q;
    for (int i = 0; i < n; i++) {
        if (S[i] == s) {
            q.push(a[i]);
            if (q.size() > k) {
                q.pop();
            }
        } else {
            s = S[i];
            while (q.size()) {
                ans += q.top();
                q.pop();
            }
            q.push(a[i]);
        }
    }

    while (q.size()) {
        ans += q.top();
        q.pop();
    }

    cout << ans << "\n";
    return 0;
}