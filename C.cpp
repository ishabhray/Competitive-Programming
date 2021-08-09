#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

bool check(int x,int y,int s){
    while(s){
        if(s%10!=x&&s%10!=y) return 0;
        s/=10;
    }
    return 1;
}
ll dp[10000][1005];
ll solve(ll rem,ll len){
    if(rem<0) return 0;
    if(rem==0){
        return 1;
    }
    if(len==0) return 0;
    if(dp[rem][len]!=-1) return dp[rem][len];
    dp[rem][len]=0;
    for(int i=0;i<10;i++) (dp[rem][len]+=solve(rem-i,len-1))%=MOD;
    return dp[rem][len];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y,n;
    cin>>x>>y>>n;
    ll ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=9*n;i++){
        if(!check(x,y,i)) continue;
        for(int j=1;j<=9;j++){
            (ans+=solve(i-j,n-1))%=MOD;
        }
    }
    cout<<ans<<'\n';
}