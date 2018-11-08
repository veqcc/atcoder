#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int M=1e9+7, dp[1<<25], x[26], input;
vector <int> vec;

int main() {
    for (int i = 0; i < 25; i++) {
        cin >> input;
        if (input == 0) {
            vec.push_back(i);
        } else {
            x[input] = i+1;
        }
    }

    dp[0] = 1;
    for (int i = 0; i < (1<<25); i++) {
        if (!dp[i]) continue;
        int b = __builtin_popcount(i) + 1;
        if (x[b]) { // 数値bが初期値として埋め込まれていないなら
            int r=x[b]-1, X=r/5, Y=r%5;
            if (!((i>>r)&1)) {
                if(X>0 && X<4 && ((i>>(r-5))^(i>>(r+5)))&1) continue;
                if(Y>0 && Y<4 && ((i>>(r-1))^(i>>(r+1)))&1) continue;
                dp[i|(1<<r)] = (dp[i|(1<<r)] + dp[i]) % M;
            } else {
                for (int j = 0; j < vec.size(); j++) {
                    int r=vec[j], X=vec[j]/5, Y=vec[j]%5;
                    if (!((i>>r)&1)) {
                        if(X>0 && X<4 && ((i>>(r-5))^(i>>(r+5)))&1) continue;
                        if(Y>0 && Y<4 && ((i>>(r-1))^(i>>(r+1)))&1) continue;
                        dp[i|(1<<r)] = (dp[i|(1<<r)] + dp[i]) % M;
                    }
                }
            }
        }
    }

    cout << dp[(1<<25)-1] << endl;
    return 0;
}