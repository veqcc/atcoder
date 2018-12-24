#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int count[100005];
    fill(count, count+100005, 0);
    int sgl = 0;
    int dbl = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (count[a] == 0) {
            count[a]++;
            sgl++;
        } else if (count[a] == 1) {
            count[a]++;
            sgl--;
            dbl++;
        } else if (count[a] == 2) {
            count[a]--;
            dbl--;
            sgl++;
        }
    }

    if (dbl % 2 == 1) {
        sgl--;
    }

    cout << sgl + dbl << "\n";
    return 0;
}