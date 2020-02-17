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

class OppositeParity {
public:
    vector <int> rearrange(vector <int> A) {
        int n = A.size();
        vector <int> even, odd;
        for (int i = 0; i < n; i++) {
            if (A[i] % 2 == 0) {
                even.push_back(A[i]);
            } else {
                odd.push_back(A[i]);
            }
        }

        vector <int> ans;
        if (even.size() != odd.size()) {
            return ans;
        }

        int e_idx = 0, o_idx = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] % 2 == 0) {
                ans.push_back(odd[o_idx++]);
            } else {
                ans.push_back(even[e_idx++]);
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}