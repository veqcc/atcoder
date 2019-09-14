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

    int n;
    cin >> n;

    vector <ll> A(n+1), B(n);
    for (int i = 0; i <= n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    ll sum = 0LL;
    ll rem = 0LL;

    for (int i = 0; i < n; i++) {
        sum += min(rem, A[i]);
        A[i] = max(0LL, A[i] - rem);

        sum += min(A[i], B[i]);
        rem = max(0LL, B[i] - A[i]);
    }

    sum += min(rem, A[n]);
    cout << sum << "\n";
    return 0;
}