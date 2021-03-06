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
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int sz = s.size();
        if (sz > 10) {
            cout << s[0] << sz - 2 << s[sz-1] << "\n";
        } else {
            cout << s << "\n";
        }
    }

    return 0;
}