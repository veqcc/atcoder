#include <functional>
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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <P> vec(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec[i] = {min(a, b), max(a, b)};
    }

    sort(vec.begin(), vec.end());

    int ans = n;
    for (int i = 1; i < n; i++) {
        if (vec[i].first == vec[i - 1].first) {
            if (vec[i].second == vec[i - 1].second) {
                ans--;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}