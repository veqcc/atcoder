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

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n], sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    sort(a, a+n);

    int mx = 0;
    int mn = a[0];
    for (int i = 1; i < n; i++) {
        vector <int> vec = divisor(a[i]);
        for (int j = 0; j < vec.size(); j++) {
            int diff = (mn + a[i]) - (mn * vec[j]) - (a[i] / vec[j]);
            mx = max(mx, diff);
        }
    }

    cout << sm - mx << "\n";
    return 0;
}