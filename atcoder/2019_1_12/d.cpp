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

int N, Q, A[100001];
ll S[100001], Sdiv[100001];
pair<int, int> X[100000];
ll ans[100000];

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
        Sdiv[i] = A[i];
        if (i - 2 > 0) Sdiv[i] += Sdiv[i - 2];
    }

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        X[i] = {x, i};
    }

    sort(X, X + Q);

    int y = 1;
    for (int q = 0; q < Q; q++) {
        int x = X[q].first;
        while (y <= N && A[y] < x) y++;
        while (y <= N) {
            // 高橋
            int upper = N - y + 1;
            // 青木
            int lower = y - (lower_bound(A, A + N + 1, max(1, 2 * x - A[y])) - A) + 1;
            if (upper > lower) {
                y++;
            } else {
                break;
            }
        }

        ll result = S[N] - S[y - 1];
        int t_first = N - (N - y + 1) * 2;
        if (t_first > 0) result += Sdiv[t_first];
        ans[X[q].second] = result;
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
