#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll M = 1000000007;
ll fac[100005];

int main() {
    int n, m;
    cin >> n >> m;

    fac[1]=fac[0]=1;
    for (ll i = 2; i < 100005; i++) {
        fac[i] = fac[i-1] * i % M;
    }

    if (abs(n-m) > 1) {
        cout << 0 << endl;
    } else if (n == m) {
        cout << fac[n] * fac[m] % M * 2 % M << endl;
    } else {
        cout << fac[n] * fac[m] % M << endl;
    }

    return 0;
}