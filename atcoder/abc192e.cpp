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
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        map<pll,vv<pll>>z;
        vl adj[n+1];
        for(int i=0;i<m;i++){
            ll u,v,t,k;
            cin>>u>>v>>t>>k;
            adj[u].pb(v);
            adj[v].pb(u);
            z[{u,v}].pb({k,t});
            z[{v,u}].pb({k,t});
        }
        set<pll>q;
        q.insert({0ll,x});
        ll vis[n+1];
        for(int i=0;i<=n;i++)
            vis[i]=1e18;
        vis[x]=0;
        while(q.size()){
            auto a=*q.begin();
            q.erase(q.begin());
            ll curr=a.ss,t=a.ff;
            //cout<<curr<<' '<<t<<'\n';
            if(curr==y)
                break;
            for(int i:adj[curr]){
                ll dest=1e18;
                for(auto j:z[{curr,i}]){
                    ll ti=j.ff,l=j.ss;
                    dest=min(dest,t+(ti-t%ti)%ti+l);
                }
                if(vis[i]<=dest)
                    continue;
                else{
                    if(vis[i]!=1e18)
                        q.erase(q.find({vis[i],i}));
                    vis[i]=dest;
                    q.insert({dest,i});
                }
            }
        }
        if(vis[y]==1e18)
            cout<<-1;
        else
            cout<<vis[y];
    }
}