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
typedef pair<ll, int> P;

const ll mod = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <ll> A, B;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end(), greater<ll>());

    for (int i = 0; i < m; i++) {
        ll b;
        cin >> b;
        B.push_back(b);
    }
    sort(B.begin(), B.end(), greater<ll>());

    int a = 0, b = 0;
    ll ret = 1;
    for (int k = n * m; k > 0; k--) {
        //cout << A[a] << " " << B[b] << " " << ret << endl;
        if (a < n && b < m && A[a] == k && B[b] == k) {
            a++; b++;
        } else if (a < n && A[a] == k) {
            ret = ret * b % mod;
            a++;
        } else if (b < m && B[b] == k) {
            ret = ret * a % mod;
            b++;
        } else {
            ret = ret * (a * b - (n * m) + k) % mod;
        }
    }

    cout << ret << "\n";
    return 0;
}