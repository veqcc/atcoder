#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {

    int N;
    cin >> N;

    int i;
    vector <pair<int,int> > vec;
    for (i = 0; i < N; i++) {
        int wi, hi;
        cin >> wi >> hi;
        vec.push_back(make_pair(wi, -hi));
    }

    sort(vec.begin(),vec.end());

    int dp[N];
    fill(dp, dp+N, 100001);
    for (i = 0; i < N; i++) {
        *lower_bound(dp, dp+N, -vec[i].second) = -vec[i].second;
    }

    cout << lower_bound(dp, dp+N, 100001) - dp << endl;
    return 0;
}
