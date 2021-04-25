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
vv<vi>adj(300005),up;
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
        cin>>n;
        for(int i=2;i<=n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cin>>q;
        preprocess(1);
        for(int i=0;i<q;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(find_dist(a,b)<=c){
                cout<<b<<'\n';
                continue;
            }
            if(find_dist(lca(a,b),a)<=c){
                c=find_dist(a,b)-c;
                int t=a;
                a=b;
                b=lca(t,b);
            }
            else
                b=lca(a,b);
            if(find_dist(a,b)<=c){
                cout<<b<<'\n';
                continue;
            }
            cerr<<a<<' '<<b<<' '<<c<<'\n';
            int ans=a;
            while(find_dist(up[ans][0],a)<=c){
                for(int i=l;i>=0;i--){
                    if(find_dist(up[ans][i],a)<=c)
                        ans=up[ans][i];
                }
            }
            cout<<ans<<'\n';
        }
    }
}