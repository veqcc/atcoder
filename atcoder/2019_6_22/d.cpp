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
        vec[i] = P(b, a);
    }

    sort(vec.begin(), vec.end());

    bool f = true;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += vec[i].second;
        if (tmp > vec[i].first) {
            f = false;
            break;
        }
    }

    cout << (f ? "Yes" : "No") << "\n";
    return 0;
}