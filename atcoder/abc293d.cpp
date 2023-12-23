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
int dfs(int a,int p,vi adj[],int vis[]){
    vis[a]=1;
    for(auto i:adj[a]){
        if(i==p) continue;
        if(vis[i]==0){
            if(dfs(i,a,adj,vis))
                return 1;
        }
        else if(vis[i]==1)
            return 1;
    }
    vis[a]=2;
    return 0;
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
        int n,m;
        cin>>n>>m;
        n*=2;
        vi adj[n];
        int vis[n]={0};
        int xx=0,yy=0;
        for(int i=0;i<n;i+=2) adj[i].pb(i+1),adj[i+1].pb(i);
        for(int i=0;i<m;i++){
            int u,v;
            char x,y;
            cin>>u>>x>>v>>y;
            if(u==v){
                xx++;
                yy++;
                vis[u*2-2]=vis[u*2-1]=1;
            }
            u--,v--;
            u*=2,v*=2;
            if(x=='R') u++;
            if(y=='R') v++;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            xx+=dfs(i,i,adj,vis);
            yy++;
            // for(int i=0;i<n;i++) cout<<vis[i]<<' ';
            // cout<<'\n'<<x<<' '<<y<<'\n';
        }
        cout<<xx<<' '<<yy-xx<<'\n';
    }
}
