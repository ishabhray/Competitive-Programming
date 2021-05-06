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
int MOD=1e9+7;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

ll dp[5005][5005],mx=0;
ll solve(int l,int r,ll a[],ll b[]){
    if(l>=r)
    dp[l][r]=0;
    else if(dp[l][r]==-1)
    dp[l][r]=a[l]*b[r]+a[r]*b[l]-a[l]*b[l]-a[r]*b[r]+solve(l+1,r-1,a,b);
    mx=max(mx,dp[l][r]);
    return dp[l][r];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        ll a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        ll ans=0;
        for(int i=0;i<n;i++)
            ans+=a[i]*b[i];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                solve(i,j,a,b);
        }
        solve(0,n-1,a,b);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        cout<<ans+mx<<'\n';
    }
}