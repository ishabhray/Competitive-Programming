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
void dfs(int a,vi adj[],int vis[]){
    vis[a]=1;
    for(int i:adj[a]){
        if(!vis[i])
            dfs(i,adj,vis);
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
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        vv<pair<ii,int>>e;
        vi adj[n];
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            e.pb({{u,v},w});
            adj[v].pb(u);
        }
        ll d[n],d1[n];
        for(int i=0;i<n;i++)
            d[i]=-1e18;
        d[0]=0;
        for(int i=0;i<n-1;i++){
            for(auto j:e){
                int u=j.ff.ff,v=j.ff.ss,w=j.ss;
                if(d[u]==-1e18)
                    continue;
                if(d[v]<d[u]+w)
                    d[v]=d[u]+w;
            }
        }
        int vis[n]={0};
        dfs(n-1,adj,vis);
        for(int i=0;i<n;i++)
            d1[i]=d[i];
        for(auto j:e){
            int u=j.ff.ff,v=j.ff.ss,w=j.ss;
            if(d[u]==-1e18)
                continue;
            if(d[v]<d[u]+w)
                d[v]=d[u]+w;
        }
        bool f=false;
        for(int i=0;i<n;i++){
            if(vis[i]&&d[i]>d1[i]){
                f=true;
                break;
            }
        }
        if(f)
            cout<<-1;
        else
            cout<<d[n-1];
    }
}