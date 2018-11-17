#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int n, m, ta, tb, l;
int a[100005][2005];

int main() {
    cin >> n >> m;
    fill(a[0], a[0]+100005*2005, 0);
    for (int i = 0; i < m; i++) {
        cin >> ta >> tb >> l;
        a[ta-1][l]++;
        a[tb-1][l]++;
    }

    int ans = 0;
    for (int i = 0; i < 100005; i++) {
        for (int j = 1000; j < 1270; j++) {
            ans += a[i][j] * a[i][2540-j];
        }
        ans += a[i][1270] * (a[i][1270] - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}