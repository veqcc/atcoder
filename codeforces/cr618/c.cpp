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

struct S {
    ll sum;
    int num;
    double mean;
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack <S> q;
    for (int i = 0; i < n; i++) {
        q.push(S{a[i], 1, (double)a[i]});

        while (q.size() > 1) {
            S s1 = q.top();
            q.pop();

            S s2 = q.top();
            q.pop();

            if (s1.mean < s2.mean) {
                ll sum = s1.sum + s2.sum;
                int num = s1.num + s2.num;
                q.push(S{sum, num, (double)sum / (double)num});
            } else {
                q.push(s2);
                q.push(s1);
                break;
            }
        }
    }

    vector <S> ans;
    while (q.size()) {
        S s = q.top();
        q.pop();
        ans.push_back(s);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        for (int j = 0; j < ans[i].num; j++) {
            cout << fixed << setprecision(12) << ans[i].mean << ' ';
        }
    }

    cout << "\n";
    return 0;
}