#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=100000;

int N, S[MAX_N], T[MAX_N];
pair<int, int> itv[MAX_N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    for (int i = 0; i < N; i++) {
        itv[i] = make_pair(T[i], S[i]);
    }

    sort(itv, itv+N);

    int ans = 0;
    int t = 0;
    for (int i = 0; i < N; i++) {
        if (t < itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }

    cout << ans << "\n";
    return 0;
}