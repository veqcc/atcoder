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

    ll H, W, N;
    cin >> H >> W >> N;
    vector < pair<int,int> > vec;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (a+j>0 && a+j<H-1 && b+k>0 && b+k<W-1) {
                    vec.push_back(make_pair(a+j, b+k));
                }
            }
        }
    }

    sort(vec.begin(), vec.end());

    ll ans[10];
    fill(ans, ans+10, 0LL);
    int c = 0;
    while (c < vec.size()) {
        int count = 1;
        int x = vec[c].first;
        int y = vec[c].second;
        c++;

        while (vec[c].first == x && vec[c].second == y) {
            count++;
            c++;
            if (c == vec.size()) break;
        }

        ans[count]++;
    }

    ans[0] = 1LL * (H-2) * (W-2);
    for (int i = 1; i < 10; i++) {
        ans[0] -= ans[i];
    }

    for (int i = 0; i < 10; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}