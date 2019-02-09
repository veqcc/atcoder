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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    string ans, cmp1 = "RGB", cmp2 = "RBG";
    int count = n;
    for (int i = 0; i < 3; i++) {
        string ret1 = s, ret2 = s;
        int c1 = 0, c2 = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] != cmp1[(j + i) % 3]) c1++;
            ret1[j] = cmp1[(j + i) % 3];

            if (s[j] != cmp2[(j + i) % 3]) c2++;
            ret2[j] = cmp2[(j + i) % 3];
        }

        if (c1 < count) {
            ans = ret1;
            count = c1;
        }

        if (c2 < count) {
            ans = ret2;
            count = c2;
        }
    }

    cout << count << "\n" << ans << "\n";
    return 0;
}