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
vv<ii> adj[200005];
ll d[200005];
pll dp[200005];
void dfs(int a,int p){
    for(auto i:adj[a]){
        if(i.ff==p) continue;
        dfs(i.ff,a);
        if(i.ss+max(dp[i.ff].ff,d[i.ff])>dp[a].ff) dp[a]={i.ss+max(dp[i.ff].ff,d[i.ff]),i.ff};
    }
}
void dfs1(int a,int p){
    vv<ii> v;
    for(auto i:adj[a]){
        v.pb({dp[i.ff].ff+i.ss,i.ff});
        v.pb({d[i.ff]+i.ss,i.ff});
    }
    sort(all(v));
    for(auto i:adj[a]){
        if(i.ff==p) continue;
        if(d[a]+i.ss>dp[i.ff].ff) dp[i.ff]={d[a]+i.ss,a};
        if(dp[a].ss!=i.ff&&dp[a].ff+i.ss>dp[i.ff].ff) dp[i.ff]={dp[a].ff+i.ss,a};
        else if(dp[a].ss==i.ff){
            int j=(int)v.size()-1;
        }
    }
    for(auto i:adj[a]){
        if(i.ff==p) continue;
        dfs(i.ff,a);
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        for(int i=1;i<=n;i++) cin>>d[i];
        dfs(1,0);
        for(int i=1;i<=n;i++) cout<<dp[i].ff<<' '<<dp[i].ss<<'\n';
    }
}