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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string x;
    cin >> x;

    int count = x.size();
    stack <int> st;

    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 'S') {
            st.push(0);
        } else if (x[i] == 'T') {
            if (st.size() > 0) {
                st.pop();
                count -= 2;
            }
        }
    }

    cout << count << "\n";
    return 0;
}