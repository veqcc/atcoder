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
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int front = 0, back = 1;
        int zero_cnt = A[0] == 0 ? 1 : 0;

        while (true) {
            if (zero_cnt <= K) {
                ans = max(ans, back - front);
                if (back >= A.size()) break;
                if (A[back++] == 0) zero_cnt++;
            } else {
                if (A[front++] == 0) zero_cnt--;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}