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

    string s;
    cin >> s;

    int n = s.size();
    int z = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            z++;
        } else {
            o++;
        }
    }

    cout << min(z, o) * 2 << "\n";
    return 0;
}