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
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> vec;
    int a[n];
    int tmp = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            if (a[i] == a[i-1]) {
                tmp++;
            } else {
                vec.push_back(tmp);
                tmp = 1;
            }
        }
    }
    vec.push_back(tmp);

    int ans = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        ans = max(ans, min(vec[i], vec[i+1]));
    }

    cout << ans * 2 << "\n";
    return 0;
}