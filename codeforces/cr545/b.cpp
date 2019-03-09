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
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    vector <int> vec[4];
    for (int i = 0; i < n; i++) {
        if (s1[i] == '0' && s2[i] == '0') vec[0].push_back(i+1);
        if (s1[i] == '1' && s2[i] == '0') vec[1].push_back(i+1);
        if (s1[i] == '0' && s2[i] == '1') vec[2].push_back(i+1);
        if (s1[i] == '1' && s2[i] == '1') vec[3].push_back(i+1);
    }

    int a = vec[0].size();
    int b = vec[1].size();
    int c = vec[2].size();
    int d = vec[3].size();

    int na = -1, nb = -1, nc = -1, nd = -1;
    for (int k = 0; k <= n/2; k++) { // k人いる
        for (int i = 0; i <= d; i++) { // (1,1)をチーム1にi人入れる
            int b_count = k - i; // チーム1に必要なbの人数
            if (b_count > b || b_count < 0) continue;

            int c_count = k - (d - i); // チーム2に必要なcの人数
            if (c_count > c || c_count < 0) continue;

            int team1 = k + (c - c_count);
            if (team1 > n/2) continue;

            int team2 = k + (b - b_count);
            if (team2 > n/2) continue;

            na = n/2 - team1;
            nb = b_count;
            nc = c - c_count;
            nd = i;
        }
    }

    if (na == -1) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < na; i++) cout << vec[0][i] << " ";
    for (int i = 0; i < nb; i++) cout << vec[1][i] << " ";
    for (int i = 0; i < nc; i++) cout << vec[2][i] << " ";
    for (int i = 0; i < nd; i++) cout << vec[3][i] << " ";

    cout << "\n";
    return 0;
}