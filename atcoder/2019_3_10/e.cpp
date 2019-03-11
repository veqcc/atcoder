#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

vector<int> manacher(vector <int> &str) {
    vector<int> newstr(2 * str.size() - 1);
    for (int i = 0; i < newstr.size(); i++) {
        if (i % 2 == 0) {
            newstr[i] = str[i / 2];
        } else {
            newstr[i] = '.'; // means spaces between characters
        }
    }
    vector<int> cnt(newstr.size());
    int i = 0, j = 0;
    while (i < newstr.size()) {
        while (i - j >= 0 && i + j < newstr.size() && newstr[i - j] == newstr[i + j]) j++;
        cnt[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < newstr.size() && k + cnt[i - k] < j) {
            cnt[i + k] = cnt[i - k];
            k++;
        }
        i += k; j -= k;
    }
    for (int i = 0; i < cnt.size(); i++) {
        if (i % 2 == 1) {
            cnt[i] = 2 * ceil(1.0 * (cnt[i] - 1) / 2);
        } else {
            int side = ceil(1.0 * cnt[i] / 2) - 1;
            cnt[i] = side * 2 + 1;
        }
    }
    return move(cnt);
}

int m, n;
string a[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> a[i];

    vector <int> yoko(m), tate(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) if (a[i][j] == '1') {
            yoko[i]++; tate[j]++;
        }
    }

    auto yoko_pal = manacher(yoko);
    auto tate_pal = manacher(tate);
    int y = 0, t = 0;

    for (int i = 1; i < m; i++) {
        if (yoko_pal[i-1] >= i && yoko_pal[2 * i + (m - i) - 1] >= m - i) y++;
    }

    for (int i = 1; i < n; i++) {
        if (tate_pal[i-1] >= i && tate_pal[2 * i + (n - i) - 1] >= n - i) t++;
    }

    cout << y * t << "\n";
    return 0;
}
