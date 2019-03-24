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

    string s;
    cin >> s;

    int mx = 0;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'T' || s[i] == 'C' || s[i] == 'G') {
            tmp++;
            mx = max(mx, tmp);
        } else {
            tmp = 0;
        }
    }

    cout << mx << "\n";
    return 0;
}