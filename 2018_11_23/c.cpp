#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll M = 1000000007;

int main() {
    int n;
    cin >> n;
    ll ten[n+1];
    fill(ten, ten+n+1, 1);
    ten[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            ten[i] = ten[i] * i % M;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + ((ten[i] + M - ten[i-1]) * ten[n/i]) % M) % M;
    }

    cout << ans << endl;
    return 0;
}