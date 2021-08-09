#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll dp[1005][1005][10];

int main(){
    // ll n,k;
    // cin>>n>>k;
    // ll a[n+1][3];
    // for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin>>a[i][j];
    // memset(dp,0,sizeof(dp));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=k;j++){
    //         for(int mask=0;mask<8;mask++){
    //             dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][mask]);
    //             dp[i+1][j+1][3]=max(dp[i+1][j+1][3],dp[i][j][mask]+a[i+1][1]+a[i+1][2]);
    //             dp[i+1][j+1][6]=max(dp[i+1][j+1][6],dp[i][j][mask]+a[i+1][0]+a[i+1][1]);
    //             if(i+2<=n){
    //                 dp[i+2][j+1][4]=max(dp[i+2][j+1][4],dp[i][j][mask]+a[i+1][0]+a[i+2][0]);
    //                 dp[i+2][j+1][2]=max(dp[i+2][j+1][2],dp[i][j][mask]+a[i+1][1]+a[i+2][1]);
    //                 dp[i+2][j+1][1]=max(dp[i+2][j+1][1],dp[i][j][mask]+a[i+1][2]+a[i+2][2]);
    //                 dp[i+2][j+2][4]=max(dp[i+2][j+2][4],dp[i][j][mask]+a[i+1][0]+a[i+2][0]+a[i+1][1]+a[i+1][2]);
    //                 dp[i+2][j+2][1]=max(dp[i+2][j+2][1],dp[i][j][mask]+a[i+1][2]+a[i+2][2]+a[i+1][1]+a[i+1][0]);
    //                 dp[i+2][j+3][7]=max(dp[i+2][j+3][7],dp[i][j][mask]+a[i+1][0]+a[i+1][1]+a[i+1][2]+a[i+2][0]+a[i+2][1]+a[i+2][2]);
    //             }
    //         }
    //     }
    // }
    // ll ans=0;
    // for(int i=0;i<=k;i++) for(int j=0;j<8;j++) ans=max(ans,dp[n][i][j]);
    // cout<<ans<<'\n';
    cout<<sizeof(void)<<'\n';
}