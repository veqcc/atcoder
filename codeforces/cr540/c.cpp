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
    int n;
    cin >> n;
    map <int, int> mp;
    int a[n*n];
    for (int i = 0; i < n * n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans[n][n];
    map <int, int> :: iterator itr;
    if (n % 2 == 0) {
        bool f = true;
        for (itr = mp.begin(); itr != mp.end(); ++itr) {
            if (itr->second % 4 != 0) f = false;
        }

        if (f) {
            cout << "YES\n";

            sort(a, a+n*n);
            int pos = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i < n / 2) {
                        if (j < n / 2) {
                            ans[i][j] = a[pos];
                            cout << a[pos] << " ";
                            pos += 4;
                        } else {
                            ans[i][j] = ans[i][n - j - 1];
                            cout << ans[i][n - j - 1] << " ";
                        }
                    } else {
                        cout << ans[n - i - 1][j] << " ";
                    }
                }
                cout << "\n";
            }
        } else {
            cout << "NO\n";
        }
    } else {
        vector <int> one, two, four;

        for (itr = mp.begin(); itr != mp.end(); ++itr) {
            int x = itr->first;
            int y = itr->second;
            for (int i = 0; i < y / 4; i++) four.push_back(x);
            if (y % 4 == 1) {
                one.push_back(x);
            } else if (y % 4 == 2) {
                two.push_back(x);
            } else if (y % 4 == 3) {
                one.push_back(x);
                two.push_back(x);
            }
        }

        if (one.size() != 1) {
            cout << "NO\n";
            return 0;
        }
        ans[n/2][n/2] = one[0];

        if ((two.size() % 2 == 1) || (two.size() > n-1)) {
            cout << "NO\n";
            return 0;
        }

        int pos = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                ans[i][j] = four[pos];
                pos++;
            }
        }

        for (int i = pos; i < four.size(); i++) {
            two.push_back(four[i]);
            two.push_back(four[i]);
        }


        int idx = 0;
        for (int i = 0; i < n/2; i++) {
            ans[n/2][i] = two[idx];
            idx++;

            ans[i][n/2] = two[idx];
            idx++;
        }

        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= n/2) {
                    if (j <= n/2) {
                        cout << ans[i][j] << " ";
                    } else {
                        ans[i][j] = ans[i][n - j - 1];
                        cout << ans[i][n - j - 1] << " ";
                    }
                } else {
                    cout << ans[n - i - 1][j] << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}