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
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int len = A.size();
        int ret = 0;

        map <int, int> mp[2];
        int c[2], l[2];
        c[0] = c[1] = l[0] = l[1] = 0;

        for (int r = 0; r < len; r++) {
            int x = A[r];

            for (int j = 0; j < 2; j++) {
                if (mp[j][x] == 0) c[j]++;
                mp[j][x]++;

                while (c[j] > K - j) {
                    int y = A[l[j]];
                    l[j]++;
                    mp[j][y]--;
                    if (mp[j][y] == 0) c[j]--;
                }
            }

            ret += l[1] - l[0];
        }

        return ret;
    }
};

int main() {
    Solution so;
    int k;
    cin >> k;
    vector <int> A = {1,2,1,3,4};
    cout << so.subarraysWithKDistinct(A,k) << "\n";
    return 0;
}