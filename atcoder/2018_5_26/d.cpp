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

    int N;
    cin >> N;
    ll A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll sm = A[0];
    ll ans = N;
    int l = 0, r = 1;
    while (r < N) {
        if ((sm^A[r]) == sm+A[r]) {
            sm += A[r];
            ans += r - l;
            r++;
        } else {
            sm -= A[l];
            l++;
        }
    }

    cout << ans << "\n";
    return 0;
}