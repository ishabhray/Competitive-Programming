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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        preprocess(1);
        int q;
        cin>>q;
        while(q--){
            int k;
            cin>>k;
            vi v(k);
            for(int i=0;i<k;i++) cin>>v[i];
            if(k==1){
                cout<<"YES\n";
                continue;
            }
            sort(all(v), [&](int a, int b){return dist[a] > dist[b];});
            bool ans=true;
            int x=v[0],y=-1;
            for(int i=1;i<k;i++){
                if(lca(v[i],x)!=v[i]){
                    y=v[i];
                    break;
                }
            }
            if(y!=-1){
                int l=lca(x,y);
                for(int i=0;i<k;i++){
                    if(!((lca(x,v[i])==v[i]||lca(y,v[i])==v[i])&&(lca(v[i],l)==l))){
                        ans=false;
                        break;
                    }
                }
            }
            if(ans) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}