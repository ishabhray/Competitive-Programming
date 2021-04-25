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
#define MAXN 200005
int n,l,timer;
vv<vi>adj(300005);
vi tin,tout,dist;

void dfs(int a,int p){
    tin[a]=++timer;
    for(int i:adj[a]){
        if(i!=p){
            dist[i]=dist[a]+1;
            dfs(i,a);
        }
    }
    tout[a]=timer;
}

void preprocess(int root){
    tin.resize(n+1);
    tout.resize(n+1);
    dist.resize(n+1);
    timer=0;
    dfs(root,root);
}
ll t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}
void update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
        t[v]=new_val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=t[2*v]+t[2*v+1];
    }
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
        int v[n+1];
        for(int i=0;i<n;i++)
            cin>>v[i+1];
        for(int i=2;i<=n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        preprocess(1);
        int a[timer+1];
        for(int i=1;i<=n;i++)
            a[tin[i]]=v[i];
        build(a,1,1,timer);
        for(int i=0;i<q;i++){
            int ty;
            cin>>ty;
            if(ty==1){
                int x,y;
                cin>>x>>y;
                update(1,1,timer,tin[x],y);
            }
            else{
                int x;
                cin>>x;
                cout<<sum(1,1,timer,tin[x],tout[x])<<'\n';
            }
        }
    }
}