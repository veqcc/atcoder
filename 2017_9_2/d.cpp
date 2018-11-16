#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int ans = 0;
    int i = 0;
    while (i < n) {
        if (p[i] == i+1) {
            i++;
            int tmp = 1;
            while (i < n && p[i] == i+1) {
                i++;
                tmp++;
            }
            ans += (tmp+1)/2;
        }
        i++;
    }

    cout << ans << endl;
    return 0;
}