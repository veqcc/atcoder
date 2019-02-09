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

    vector <int> A, odd;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
        if (i % 2 == 0) {
            odd.push_back(a);
        }
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < odd.size(); i++) {
        int pos = lower_bound(A.begin(), A.end(), odd[i]) - A.begin();
        if (pos % 2 == 1) ans++;
    }

    cout << ans << "\n";
    return 0;
}