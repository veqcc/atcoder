#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int L[2*N];
    for (int i = 0; i < 2*N; i++) {
        cin >> L[i];
    }

    sort(L, L+2*N);

    int ans = 0;
    for (int i = 0; i < 2*N; i+=2) {
        ans += L[i];
    }

    cout << ans << "\n";
    return 0;
}