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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <P> num(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int l = 0, r = 0;
        stack <int> st;
        for (char c : s) {
            if (c == ')') {
                if (st.empty()) {
                    l++;
                } else {
                    st.pop();
                }
            } else {
                st.push(1);
            }
        }
        r = st.size();

        num[i] = {r - l, l};
    }

    sort(num.begin(), num.end(), greater<P>());

    int right = 0;
    for (int i = 0; i < n; i++) {
        int l = num[i].second;
        int r = num[i].first + l;
        if (l == 0) right += r;
    }

    for (int i = 0; i < n; i++) {
        int l = num[i].second;
        int r = num[i].first + l;
        if (r && l) {
            if (right < l) {
                cout << "No" << endl;
                return 0;
            } else {
                right = right - l + r;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int l = num[i].second;
        int r = num[i].first + l;
        if (r == 0) right -= l;
    }

    cout << (right == 0 ? "Yes" : "No") << endl;
    return 0;
}