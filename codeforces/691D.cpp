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

int a[1000001],ans[1000001];

void dfs(int i,vi adj[],int vis[],vi &v,vi &u)
{
    if(vis[i])
        return;
    vis[i]=1;
    v.pb(i);
    u.pb(a[i]);
    for(int j:adj[i])
        dfs(j,adj,vis,v,u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        vi adj[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int vis[n+1]={0};
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            vi v,u;
            dfs(i,adj,vis,v,u);
            sort(all(v));
            sort(all(u),greater<int>());
            for(int i=0;i<v.size();i++)
                ans[v[i]]=u[i];
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
    }
}