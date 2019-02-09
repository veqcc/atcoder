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
typedef pair<int, int> P;

int r, c, n;
int calc(int x, int y) {
    if (x == 0) {
        return y;
    } else if (x == r) {
        return r + 2 * c - y;
    } else if (y == 0) {
        return 2 * (r + c) - x;
    } else {
        return c + x;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c >> n;

    vector <P> vec;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if ((x1 % r == 0 || y1 % c == 0) && (x2 % r == 0 || y2 % c == 0)) {
            int l1 = calc(x1, y1);
            int l2 = calc(x2, y2);
            vec.push_back(P(min(l1, l2), i));
            vec.push_back(P(max(l1, l2), i));
        }
    }

    sort(vec.begin(), vec.end());

    stack <int> st;
    for (int i = 0; i < vec.size(); i++) {
        if (st.size() == 0) {
            st.push(vec[i].second);
        } else {
            if (vec[i].second == st.top()) {
                st.pop();
            } else {
                st.push(vec[i].second);
            }
        }
    }

    if (st.size() > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}