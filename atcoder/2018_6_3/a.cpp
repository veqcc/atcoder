#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = n;
    for (int i = 1; i < n; i++) {
        int dig, sum=0, tmp_i=i, tmp_n=n-i;
        while (tmp_i) {
            dig = tmp_i % 10;
            sum += dig;
            tmp_i /= 10;
        }
        while (tmp_n) {
            dig = tmp_n % 10;
            sum += dig;
            tmp_n /= 10;
        }

        ans = min(ans, sum);
    }

    cout << ans << endl;
    return 0;
}