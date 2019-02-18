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

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0;
        int count[n];
        fill(count, count+n, 0);
        for (int i = 0; i < n; i++) {
            if (i >= 1) count[i] = count[i-1];
            int c = i >= K ? count[i] - count[i - K] : count[i];

            if (i <= n - K) {
                if ((A[i] + c) % 2 == 0) {
                    count[i]++;
                    ans++;
                }
            } else {
                if ((A[i] + c) % 2 == 0) {
                    ans = -1;
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}