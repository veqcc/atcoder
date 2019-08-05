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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector <int> ans(s.size(), 0);

    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            c++;
        } else {
            if (c) {
                if (c % 2 == 1) {
                    ans[i-1] += c/2 + 1;
                    ans[i] += c/2;
                } else {
                    ans[i-1] += c/2;
                    ans[i] += c/2;
                }
                c = 0;
            }
        }
    }

    c = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            c++;
        } else{
            if (c) {
                if (c % 2 == 1) {
                    ans[i+1] += c/2 + 1;
                    ans[i] += c/2;
                } else {
                    ans[i+1] += c/2;
                    ans[i] += c/2;
                }
                c = 0;
            }
        }
    }

    for (int a : ans) cout << a << " ";
    cout << "\n";
    return 0;
}