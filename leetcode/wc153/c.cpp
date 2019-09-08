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

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        bool all_minus = true;
        int mx = -(1 << 30);
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                all_minus = false;
            }
            mx = max(mx, arr[i]);
        }

        if (all_minus) {
            return mx;
        }

        vector <int> left(n);
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1] + arr[i - 1], 0);
        }

        vector <int> right(n);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1] + arr[i + 1], 0);
        }

        mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(left[i] + right[i], mx);
            mx = max(left[i] + right[i] + arr[i], mx);
        }

        return mx;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution s;
    cout << s.maximumSum(arr) << "\n";
    return 0;
}