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

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, K;
    cin >> n >> K;

    int sum = 0;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    vector<int> div = divisor(sum);
    sort(div.begin(), div.end(), greater<int>());

    for (int d : div) {
        vector<int> vec(n);
        for (int i = 0; i < n; i++) vec[i] = A[i] % d;
        sort(vec.begin(), vec.end());

        vector<int> l(n);
        for (int i = 0; i < n; i++) {
            l[i] = vec[i];
            if (i) l[i] += l[i - 1];
        }

        vector<int> r(n);
        for (int i = n - 1; i >= 0; i--) {
            r[i] = d - vec[i];
            if (i < n - 1) r[i] += r[i + 1];
        }

        bool f = false;
        if (l[n - 1] == 0) f = true;
        for (int i = 0; i < n - 1; i++) {
            if (l[i] == r[i + 1] && l[i] <= K) {
                f = true;
                break;
            }
        }

        if (f) {
            cout << d << "\n";
            break;
        }
    }

    return 0;
}