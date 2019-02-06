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

const int MAX_N = 100005;
const int B = 1000;

int n, m;
int A[MAX_N];
int I[MAX_N], J[MAX_N], K[MAX_N];

int nums[MAX_N];
vector <int> bucket[MAX_N/B];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        nums[i] = A[i];
        bucket[i / B].push_back(A[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> I[i] >> J[i] >> K[i];
        I[i]--; J[i]--;
    }

    sort(nums, nums+n);
    for (int i = 0; i < n/B; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    for (int i = 0; i < m; i++) {
        int l = I[i];
        int r = J[i] + 1;
        int k = K[i];

        int lb = -1;
        int ub = n-1;

        while (ub - lb > 1) {
            int md = (lb + ub) / 2;
            int x = nums[md];
            int tl = l;
            int tr = r;
            int c = 0;

            while (tl < tr && tl % B != 0) {
                if (A[tl] <= x) {
                    c++;
                }
                tl++;
            }

            while (tl < tr && tr % B != 0) {
                tr--;
                if (A[tr] <= x) {
                    c++;
                }
            }

            while (tl < tr) {
                int b = tl / B;
                c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
                tl += B;
            }

            if (c >= k) {
                ub = md;
            } else {
                lb = md;
            }
        }
        cout << nums[ub] << "\n";
    }

    return 0;
}