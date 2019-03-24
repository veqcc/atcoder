#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    string s;
    cin >> n >> q >> s;

    vector <int> sm(n, 0);
    for (int i = 1; i < n; i++) {
        sm[i] = sm[i-1];
        if (s[i-1] == 'A' && s[i] == 'C') {
            sm[i]++;
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << sm[r] - sm[l] << '\n';
    }

    return 0;
}