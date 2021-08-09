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
vv<vi>adj;
vi vis,ans,cyc;
void dfs(int a){
    vis[a]=1;
    cyc[a]=1;
    ans[a]=1;
    for(int i:adj[a]){
        if(vis[i]){
            if(!cyc[i]&&ans[i]!=-1) ans[i]=2;
            else ans[i]=-1;
        }
        else dfs(i);
    }
    cyc[a]=0;
}
void dfs1(int a,int b){
    vis[a]=1;
    ans[a]=b;
    for(int i:adj[a]){
        if(vis[i]||ans[i]==-1) continue;
        dfs1(i,b);
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        adj.clear();
        adj.resize(n);
        vis.assign(n,0);
        cyc.assign(n,0);
        ans.assign(n,0);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
        }
        dfs(0);
        vis.assign(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]||ans[i]!=-1) continue;
            dfs1(i,ans[i]);
        }
        vis.assign(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]||ans[i]!=2) continue;
            dfs1(i,ans[i]);
        }
        for(int i:ans) cout<<i<<' ';
        cout<<'\n';
    }
}