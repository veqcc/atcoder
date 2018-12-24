#include<bits/stdc++.h>
#include <math.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
const ll N=1e5+5,mod=1e9+7;
ll n,w,ans,inv[N],fac;
ll sqr(int x){return x*x%mod;}
ll pow(int a,int n){return n?sqr(pow(a,n/2))*(n&1?a:1)%mod:1;}

int main(){
    cin >> n;
    inv[1] = 1;
    rep (i,2,n) inv[i] = pow(i, mod-2);
    rep (i,1,n) inv[i] = (inv[i] + inv[i-1]) % mod;
    fac=1;
    rep (i,1,n) {
        cin >> w;
        ans = (ans+(inv[i]+inv[n-i+1]-1) % mod * w % mod) % mod;
        fac = fac * i % mod;
    }
    cout << ans * fac % mod << endl;
    return 0;
}