#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << endl;
    return 0;
}

// dfs
void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == true && visited[i] == false) {
            dfs(i);
        }
    }
}

// gcd
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// lcm
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}
