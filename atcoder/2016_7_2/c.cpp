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

    vector <P> vec;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        vec.push_back(P(a, i));
    }

    sort(vec.begin(), vec.end(), greater<P>());

    for (P p : vec) {
        cout << p.second << "\n";
    }

    return 0;
}