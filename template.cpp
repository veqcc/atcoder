#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << endl;
    return 0;
}


// dfsの雛形
void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == true && visited[i] == false) {
            dfs(i);
        }
    }
}