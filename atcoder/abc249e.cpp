#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()
#define MAXN 300005

vv<vl> dp(3005,vl(3005,0)),pre(3005,vl(3005,0));
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        ll MOD;
        cin>>n>>MOD;
        dp[0][0]=pre[0][0]=1;
        for(int i=1;i<=n;i++){
            pre[i][0]+=pre[i-1][0];
            for(int j=2;j<=n;j++){
                if(j<=5){
                    if(j==2&&i<10) (dp[i][j]+=1)%=MOD;
                    if(j==3&&i>=10&&i<100) (dp[i][j]+=1)%=MOD;
                    if(j==4&&i>=100&&i<1000) (dp[i][j]+=1)%=MOD;
                    if(j==5&&i>=1000&&i<10000) (dp[i][j]+=1)%=MOD;
                }
                (dp[i][j]+=25ll*pre[i-1][j-2])%=MOD;
                if(i>=10) (dp[i][j]+=MOD-25ll*pre[i-10][j-2]%MOD)%=MOD;
                if(j>=3&&i>=10) (dp[i][j]+=25ll*pre[i-10][j-3]%MOD)%=MOD;
                if(j>=3&&i>=100) (dp[i][j]+=MOD-25ll*pre[i-100][j-3]%MOD)%=MOD;
                if(j>=4&&i>=100) (dp[i][j]+=25ll*pre[i-100][j-4]%MOD)%=MOD;
                if(j>=4&&i>=1000) (dp[i][j]+=MOD-25ll*pre[i-1000][j-4]%MOD)%=MOD;
                if(j>=5&&i>=1000) (dp[i][j]+=25ll*pre[i-1000][j-5]%MOD)%=MOD;
                pre[i][j]=(dp[i][j]+pre[i-1][j])%MOD;
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++) cout<<pre[i][j]<<' ';
        //     cout<<'\n';
        // }
        ll ans=0;
        for(int i=1;i<n;i++) (ans+=dp[n][i])%=MOD;
        cout<<ans<<'\n';
    }
}