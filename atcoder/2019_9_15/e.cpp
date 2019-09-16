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

vector <int> ZAlgorithm(const string& S) {
    int N = S.size();
    vector<int> z(N);
    z[0] = -1;

    int l = 0, r = 0;
    for (int k = 1; k < N; k++) {
        if (k > r) {
            int i = 0;
            while (k + i < N && S[i] == S[k + i]) i++;
            l = k;
            r = k + i - 1;
            z[k] = i;
        } else if (z[k - l] < r - k + 1) {
            z[k] = z[k - l];
        } else if (z[k - l] >= r - k + 1) {
            int i = r - k + 1;
            while (k + i < N && S[i] == S[k + i]) i++;
            l = k;
            r = k + i - 1;
            z[k] = i;
        }
    }

    return z;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector <int> len = ZAlgorithm(s.substr(i, n - i));
        for (int j = 1; j < len.size(); j++) {
            ans = max(ans, min(j, len[j]));
        }
    }

    cout << ans << "\n";
    return 0;
}