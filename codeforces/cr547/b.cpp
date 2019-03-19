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

    int n;
    cin >> n;

    vector <int> vec(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        vec[i+n] = vec[i];
    }

    int mx = 0;
    int tmp = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (vec[i] == 1) {
            tmp++;
            mx = max(mx, tmp);
        } else {
            tmp = 0;
        }
    }

    cout << mx << "\n";
    return 0;
}