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
typedef pair <string, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map <string, vector <int> > mp;
    map <P, int> idx;
    for (int i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;
        idx[P(s, p)] = i + 1;
        mp[s].push_back(p);
    }

    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        sort(itr->second.begin(), itr->second.end(), greater<int>());
        for (int i = 0; i < itr->second.size(); i++) {
            P p = P(itr->first, itr->second[i]);
            cout << idx[p] << '\n';
        }
    }

    return 0;
}