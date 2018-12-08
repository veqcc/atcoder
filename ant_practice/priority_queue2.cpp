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

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        q.push(l);
    }

    int ans = 0;
    while (q.size() > 1) {
        int f = q.top();
        q.pop();
        int s = q.top();
        q.pop();

        ans += f + s;
        q.push(f + s);
    }

    cout << ans << "\n";
    return 0;
}