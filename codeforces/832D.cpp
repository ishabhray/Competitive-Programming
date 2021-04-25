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
vv<vi>adj,up;
vi tin,tout,dist;

void dfs(int a,int p){
    tin[a]=timer++;
    up[a][0]=p;
    for(int i=1;i<=l;i++)
        up[a][i]=up[up[a][i-1]][i-1];
    for(int i:adj[a]){
        if(i!=p){
            dist[i]=dist[a]+1;
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
void preprocess(int root){
    tin.resize(n+1);
    tout.resize(n+1);
    dist.resize(n+1);
    timer=1;
    l=ceil(log2(n));
    up.assign(n+1,vi(l+1));
    dfs(root,root);
}
int fun(int a[3]){
    int s=a[0],t=a[1],f=a[2];
    int x=lca(s,f),y=lca(t,f);
    if(x==y)
        return find_dist(lca(s,t),f);
    if(dist[x]>=dist[y])
        return find_dist(x,f);
    else
        return find_dist(y,f);
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
        adj.resize(n+1);
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            adj[i].pb(x);
            adj[x].pb(i);
        }
        preprocess(1);
        for(int i=0;i<q;i++){
            int ans=0;
            int a[3];
            cin>>a[0]>>a[1]>>a[2];
            sort(a,a+3);
            do{
                ans=max(ans,fun(a));
            }while(next_permutation(a,a+3));
            cout<<ans+1<<'\n';
        }
    }
}