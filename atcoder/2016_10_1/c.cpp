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
    int mx=0, count[N];
    fill(count, count+N, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        count[a]++;
        mx = max(mx, a);
    }

    bool ans = true;
    if (mx % 2 == 0) {
        if (count[mx/2] != 1) ans = false;
        for (int i = 0; i < mx; i++) {
            if (i < mx/2 && count[i] > 0) ans = false;
            if (i > mx/2 && count[i] < 2) ans = false;
        }
    } else {
        if (count[(mx+1)/2] != 2) ans = false;
        for (int i = 0; i < mx; i++) {
            if (i < (mx+1)/2 && count[i] > 0) ans = false;
            if (i > (mx+1)/2 && count[i] < 2) ans = false;
        }
    }

    if (ans) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }

    return 0;
}