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
void bfs(int a,int b,vi adj[],int &d1,int &dn,int n){
    int vis[n+1]={0};
    int dist[n+1];
    vis[b]=1;
    for(int i=0;i<=n;i++) dist[i]=1e9;
    queue<int>q;
    q.push(a);
    vis[a]=1;
    dist[a]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i:adj[u]){
            if(vis[i]) continue;
            vis[i]=1;
            dist[i]=dist[u]+1;
        }
    }
    if(dist[1]!=1e9) d1=dist[1];
    if(dist[n]!=1e9) dn=dist[n];
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
        ll ans=1e18;
        vv<vi>edges;
        vi adj[n+1];
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({u,v,w});
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i=0;i<m;i++){
            ll u=edges[i][0],v=edges[i][1],w=edges[i][2];
            ll curr=w;
            int dstu1=-1,dstv1=-1;
            int dstun=-1,dstvn=-1;
            bfs(u,v,adj,dstu1,dstun,n);
            bfs(v,u,adj,dstv1,dstvn,n);
        }
        cout<<ans<<'\n';
    }
}