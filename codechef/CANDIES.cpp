#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

ll MOD=1e9+7;

ll min(ll a,ll b)
{
    return (a<b)?a:b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    a[0]=0;
    ll dp[n+1][k+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        ll pre[k+1];
        pre[0]=dp[i-1][0];
        dp[i][0]=pre[0];
        for(int j=1;j<=k;j++){
            pre[j]=(dp[i-1][j]+pre[j-1])%MOD;
            if(j<=a[i])
                dp[i][j]=pre[j];
            else
                dp[i][j]=(pre[j]-pre[j-a[i]-1]+MOD)%MOD;
        }
    }
    
    //for(int i=0;i<=n;i++){
    //    for(int j=0;j<=k;j++)
    //        cout<<dp[i][j]<<' ';
    //    cout<<'\n';
    //}
    cout<<dp[n][k];
}