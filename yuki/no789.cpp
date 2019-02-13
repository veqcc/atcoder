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

const int MAX_N = 1 << 19;
ll bit[MAX_N + 1];

// iが与えられた時に、a[1]+a[2]+...+a[i]を計算する
ll sum(int i) {
    ll s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i; // 最後の1ビット
    }
    return s;
}

// iとxが与えられた時に、a[i]にxを足す
void add(int i, int x) {
    while (i <= MAX_N) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n], x[n], y[n];
    set <int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> x[i] >> y[i];
        st.insert(x[i]);
        st.insert(y[i]);
    }

    map <int, int> mp;
    set <int> :: iterator itr;
    int count = 1;
    for (itr = st.begin(); itr != st.end(); ++itr){
        mp[*itr] = count;
        count++;
    }

    ll sm = 0LL;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            add(mp[x[i]], y[i]);
        } else {
            sm += (ll)(sum(mp[y[i]]) - sum(mp[x[i]] - 1));
        }
    }

    cout << sm << "\n";
    return 0;
}
