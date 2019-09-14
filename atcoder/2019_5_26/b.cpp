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
typedef pair <string, int> P;
typedef pair <P, int> PP;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <PP> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first.first >> vec[i].first.second;
        vec[i].second = i + 1;
    }

    sort(vec.begin(), vec.end(), [](const PP &x, const PP &y) {
        if (x.first.first == y.first.first) {
            return x.first.second > y.first.second;
        } else {
            return x.first.first < y.first.first;
        }
    });

    for (auto p : vec) cout << p.second << '\n';
    return 0;
}