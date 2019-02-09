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
    int d[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d, d+n, greater<int>());

    for (int i = 0; i < n; i++) {
        if (d[i] == d[i+1] || d[0] % d[i] != 0) {
            cout << d[0] << " " << d[i] << "\n";
            return 0;
        }
    }
}