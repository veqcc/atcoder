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

int main() {
    int n, a;
    cin >> n >> a;

    multiset <int, greater<int>> st;
    st.insert(a);
    for (int i = 1; i < n; i++) {
        cin >> a;
        auto itr = st.upper_bound(a);
        if (itr != st.end()) st.erase(itr);
        st.insert(a);
    }

    cout << st.size() << "\n";
    return 0;
}