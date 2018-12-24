#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int n, c=0, ans=0, f[100005];
pair<int, int> x[100005], y[100005];
pair<int, pair<int, int> > a[200010];

int find(int x) {
    return f[x] != x ? f[x] = find(f[x]) : x;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> y[i].first;
        x[i].second = y[i].second = i;
        f[i] = i;
    }

    sort(x, x+n);
    sort(y, y+n);

    for (int i = 1; i < n; i++) {
        a[c++] = make_pair(x[i].first - x[i-1].first, make_pair(x[i].second, x[i-1].second));
        a[c++] = make_pair(y[i].first - y[i-1].first, make_pair(y[i].second, y[i-1].second));
    }

    sort(a, a+c);

    for (int i = 0; i < c; i++) {
        if (find(a[i].second.first) != find(a[i].second.second)) {
            f[find(a[i].second.first)] = find(a[i].second.second);
            ans += a[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}