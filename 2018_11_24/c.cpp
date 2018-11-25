#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    while (q--) {
        int k;
        cin >> k;

        ll ans=0, d=0, m=0, dm=0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (s[i-k] == 'D') {
                    d--;
                    dm -= m;
                } else if (s[i-k] == 'M') {
                    m--;
                }
            }
            if (s[i] == 'D') {
                d++;
            } else if (s[i] == 'M') {
                m++;
                dm += d;
            } else if (s[i] == 'C') {
                ans += dm;
            }
        }
        cout << ans << endl;
    }

    return 0;
}