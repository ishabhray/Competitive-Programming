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

int n,l,timer;
vv<vv<ii>>adj(300005);
vv<vi>up,mn;
vi tin,tout,dist;

void dfs(int a,int p){
    tin[a]=timer++;
    up[a][0]=p;
    for(int i=1;i<=l;i++){
        up[a][i]=up[up[a][i-1]][i-1];
        mn[a][i]=min(mn[a][i-1],mn[up[a][i-1]][i-1]);
    }
    for(auto x:adj[a]){
        int i=x.ff,j=x.ss;
        if(i!=p){
            dist[i]=dist[a]+1;
            mn[i][0]=j;
            dfs(i,a);
        }
    }
    tout[a]=timer++;
}
bool is_ancestor(int u,int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int lca(int u,int v){
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=l;i>=0;i--)
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}
int find_dist(int u,int v){
    return dist[u]+dist[v]-2*dist[lca(u,v)];
}
int find(int a,int b){
    //cout<<a<<' '<<b<<'\n';
    int d=find_dist(a,b);
    int ans=INT_MAX;
    for(int i=l;i>=0;i--){
        if(d&(1<<i))
            ans=min(ans,mn[a][i]),a=up[a][i];
    }
    //cout<<d<<' '<<a<<' '<<ans<<'\n';
    return ans;
}
void preprocess(int root){
    tin.resize(n+1);
    tout.resize(n+1);
    dist.resize(n+1);
    timer=1;
    l=ceil(log2(n));
    up.assign(n+1,vi(l+1));
    mn.assign(n+1,vi(l+1,INT_MAX));
    dfs(root,root);
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
        int q;
        cin>>n>>q;
        for(int i=2;i<=n;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        preprocess(1);
        cin>>q;
        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            cout<<min(find(a,lca(a,b)),find(b,lca(a,b)))<<'\n';
        }
    }
}