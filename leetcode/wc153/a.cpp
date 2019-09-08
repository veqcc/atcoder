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
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += distance[i];

        int ans = 0;
        for (int i = start; i != destination; i = (i + 1) % n) {
            ans += distance[i];
        }

        return min(ans, sum - ans);
    }
};

int main() {
    int n;
    cin >> n;

    vector <int> dis(n);
    for (int i = 0; i < n; i++) cin >> dis[i];

    int s, d;
    cin >> s >> d;

    Solution solution;

    cout << solution.distanceBetweenBusStops(dis, s, d) << "\n";
    return 0;
}