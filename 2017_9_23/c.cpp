#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    int count[26];
    fill(count, count+26, 0);
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            count[(int)(s[j] - 'a')]++;
        }
    }

    int one=0, two=0;
    for (int i = 0; i < 26; i++) {
        int d = count[i] % 4;
        if (d == 1 || d == 3) one++;
        if (d == 2 || d == 3) two++;
    }

    string ans = "No";
    if (one == (H%2) * (W%2)) {
        if (two <= (W/2)*(H%2) + (H/2)*(W%2)) {
            ans = "Yes";
        }
    }

    cout << ans << "\n";
    return 0;
}
