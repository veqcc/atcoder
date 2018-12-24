#include<iostream>
using namespace std;
long gcd(long a,long b){return b?gcd(b,a%b):a;}
long n,m;
string s,t;
int main()
{
    cin>>n>>m>>s>>t;
    long U=gcd(n,m);
    for(int j=0;j<U;j++)
    {
        if(s[n/U*j]!=t[m/U*j])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<n*m/U<<endl;
}