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

stack<int>s;
void dfs1(vi adj[],int vis[],int i)
{
    if(vis[i])
        return;
    vis[i]=1;
    for(int j:adj[i])
        dfs1(adj,vis,j);
    s.push(i);
}
vi v;
void dfs2(vi adj[],int vis[],int i)
{
    if(vis[i])
        return;
    vis[i]=1;
    v.pb(i);
    for(int j:adj[i])
        dfs2(adj,vis,j);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        vi adj[n+1],adjt[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adjt[v].pb(u);
        }
        int vis[n+1]={0};
        while(!s.empty())
            s.pop();
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            dfs1(adj,vis,i);
        }
        vv<vi >scc;
        memset(vis,0,sizeof(vis));
        while(!s.empty()){
            int i=s.top();
            s.pop();
            if(vis[i])
                continue;
            dfs2(adjt,vis,i);
            scc.pb(v);
            v.clear();
        }
        for(auto a:scc){
            for(int i:a)
                cout<<i<<' ';
            cout<<'\n';
        }
    }
}