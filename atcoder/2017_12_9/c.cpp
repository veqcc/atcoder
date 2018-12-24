#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <cstring>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
ll A, B;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int dfs(ll a, vector<ll> work) {
    if (a > B) {
        return 1;
    }

    ll ret = dfs(a+1, work);

    bool relatively_prime = true;
    for (int i = 0; i < work.size(); i++) {
        if (gcd(work[i], a) != 1) {
            relatively_prime = false;
        }
    }

    if (relatively_prime) {
        work.push_back(a);
        ret += dfs(a+1, work);
        work.pop_back();
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B;
    vector<ll> work;
    cout << dfs(A, work) << "\n";
    return 0;
}