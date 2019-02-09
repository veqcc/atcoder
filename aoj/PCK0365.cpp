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

int n, bit[1 << 17];

// iが与えられた時に、a[1]+a[2]+...+a[i]を計算する
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i; // 最後の1ビット
    }
    return s;
}

// iとxが与えられた時に、a[i]にxを足す
void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;
    cin >> s >> k;
    n = s.size();

    queue <int> q[26];
    for (int i = 0; i < n; i++) {
        q[s[i] - 'a'].push(i);
        add(i+1, 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (!q[j].size()) continue;

            int pos = q[j].front();
            int count = sum(pos);
            if (count <= k) {
                q[j].pop();
                k -= count;
                add(pos+1, -1);
                cout << s[pos];
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (bit[i+1]) {
            cout << s[i];
        }
    }

    cout << endl;
    return 0;
}