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
vector<vector<ll>>dp(5001,vector<ll>(5001,LLONG_MIN));
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
        int n,m;
        cin>>n>>m;
        ll x[n],y[n+1]={0};
        for(ll &i:x) cin>>i;
        for(int i=0;i<m;i++){
            ll c,z;
            cin>>c>>z;
            y[c]=z;
        }
        dp[0][0]=0;
        dp[0][1]=x[0]+y[1];
        for(int i=0;i+1<n;i++){
            for(int j=0;j<=n;j++){
                dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+x[i+1]+y[j+1]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        ll ans=0;
        for(int i=0;i<=n;i++) ans=max(ans,dp[n-1][i]);
        cout<<ans<<'\n';
    }
}