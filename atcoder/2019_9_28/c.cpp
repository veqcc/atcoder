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
        cin >> vec[i].first;
        vec[i].second = i + 1;
    }

    sort(vec.begin(), vec.end());

    for (P p : vec) {
        cout << p.second << ' ';
    }

    cout << "\n";
    return 0;
}