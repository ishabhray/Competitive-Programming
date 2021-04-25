#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000009

ll dp[1000005],dp1[1000005];  
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    /*dp[0]=dp[1]=0;
    dp[2]=dp[3]=1;
    for(ll i=4;i<1000005;i++){
        dp[i]=(dp[i-2]+dp[i-3])%MOD;
    }*/
    dp1[0]=1;
    for(int i=0;i<1000000;i++){
        dp1[i+2]=(dp1[i+2]+dp1[i])%MOD;
        dp1[i+3]=(dp1[i+3]+dp1[i])%MOD;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        //cout<<dp[n]<<"\n";
        cout<<dp1[n]<<"\n";
    }
}