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

    ll n,cap;
    cin>>n>>cap;
    ll w[n],v[n];
    for(ll i=0;i<n;i++)
        cin>>w[i]>>v[i];
    ll vmax=0;
    for(int i=0;i<n;i++)
        vmax+=v[i];
    ll dp[vmax+1][n];
    for(int i=0;i<=vmax;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=1e12+1;
    for(ll i=0;i<=vmax;i++){
        for(ll j=0;j<n;j++){
            if(i==0)
                dp[i][j]=0;
            else if(j==0){if(i==v[0])
                dp[i][j]=w[j];}
            else if(v[j]<=i)
                dp[i][j]=min(dp[i][j],w[j]+dp[i-v[j]][j-1]);
            if(j>0)
                dp[i][j]=min(dp[i][j-1],dp[i][j]);
        }
    }
    /*for(int i=0;i<=vmax;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }*/
    ll ans=0;
    for(int j=0;j<=vmax;j++)
        if(dp[j][n-1]<=cap)
            ans=j;
    cout<<ans;
}