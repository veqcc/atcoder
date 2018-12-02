#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=1000;

int N, R;
int X[MAX_N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> R;

    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    sort(X, X+N);

    int ans = 0;
    int i = 0;
    while (i < N) {
        int s = X[i++];
        while (i < N && X[i] <= s + R) i++;
        int p = X[i-1];
        while (i < N && X[i] <= p + R) i++;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}