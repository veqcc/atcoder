#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int N, C, s, t, c, mx, v[35][100005];

int main() {
    cin >> N >> C;
    while (N--) {
        cin >> s >> t >> c;
        for (int i = s; i <= t; i++) {
            v[c][i] = 1;
        }
    }

    for (int i = 1; i <= 100000; i++) {
        s = 0;
        for (int j = 1; j <= C; j++) {
            s += v[j][i];
        }
        mx = max(mx, s);
    }

    cout << mx << endl;
    return 0;
}