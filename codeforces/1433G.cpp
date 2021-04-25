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
        int n,m,k;
        cin>>n>>m>>k;
        vv<ii >adj[n+1];
        vv<ii >edges;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({u,v});
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        vv<ii >routes;
        for(int i=0;i<k;i++){
            int st,e;
            cin>>st>>e;
            routes.pb({st,e});
        }
        int dist[n+1][n+1];
        for(int i=1;i<=n;i++){
            int d[n+1];
            for(int j=0;j<=n;j++)
                d[j]=1e9;
            d[i]=0;
            priority_queue<ii >pq;
            pq.push({0,i});
            while(!pq.empty()){
                auto a=pq.top();
                pq.pop();
                for(auto j:adj[a.ss]){
                    if(d[j.ff]>-a.ff+j.ss){
                        d[j.ff]=-a.ff+j.ss;
                        pq.push({-d[j.ff],j.ff});
                    }
                }
            }
            for(int j=0;j<=n;j++)
                dist[i][j]=d[j];
        }
        ll ans=1e9;
        for(auto i:edges){
            ll s=0;
            for(auto j:routes){
                s+=min({dist[j.ff][j.ss],dist[j.ff][i.ff]+dist[j.ss][i.ss],dist[j.ff][i.ss]+dist[j.ss][i.ff]});
            }
            ans=min(ans,s);
        }
        cout<<ans;
    }
}