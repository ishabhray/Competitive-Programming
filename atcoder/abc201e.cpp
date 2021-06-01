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
ll dp[200005][60][2];
vv<pll>adj[200005];
ll ans=0;
void dfs(int a,int p){
    for(auto i:adj[a]){
        if(i.ff==p)
            continue;
        dfs(i.ff,a);
    }
    for(ll j=0;j<60;j++){
        for(auto x:adj[a]){
            ll wt=x.ss,i=x.ff;
            if(i==p)
                continue;
            // cout<<dp[a][j][0]<<' '<<dp[a][j][1]<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<'\n';
            if(wt&(1ll<<j)){
                (ans+=(1ll<<j)%MOD*(dp[i][j][0]*dp[a][j][0]%MOD+dp[i][j][1]*dp[a][j][1]%MOD)%MOD)%=MOD;
                dp[a][j][0]+=dp[i][j][1];
                dp[a][j][1]+=dp[i][j][0];
            }
            else{
                (ans+=(1ll<<j)%MOD*(dp[i][j][0]*dp[a][j][1]%MOD+dp[i][j][1]*dp[a][j][0]%MOD)%MOD)%=MOD;
                dp[a][j][0]+=dp[i][j][0];
                dp[a][j][1]+=dp[i][j][1];
            }
        }
        // cout<<j<<' '<<ans<<' ';
        dp[a][j][0]++;
        for(auto x:adj[a]){
            ll wt=x.ss,i=x.ff;
            if(wt&(1ll<<j))
                (ans+=(1ll<<j)%MOD*dp[i][j][0]%MOD)%=MOD;
            else
                (ans+=(1ll<<j)%MOD*dp[i][j][1]%MOD)%=MOD;
        }
        // cout<<ans<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        dfs(0,-1);
        cout<<ans<<'\n';
    }
}