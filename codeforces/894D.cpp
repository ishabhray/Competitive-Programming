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
vi dist[1000005];
vl pre[1000005];
void dfs(int a,int p,vv<ii>adj[]){
    dist[a].pb(0);
    for(auto i:adj[a]){
        if(i.ff==p)
            continue;
        dfs(i.ff,p,adj);
        for(int j:dist[i.ff])
            dist[a].pb(i.ss+j);
    }
    sort(all(dist[a]));
    pre[a].pb(0);
    for(ll i:dist[a]){
        pre[a].pb(pre[a].back()+i);
    }
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
        vv<ii> adj[n+1];
        ii p[n+1];
        p[1]={0,0};
        for(int i=1;i<n;i++){
            int w;
            cin>>w;
            adj[(i+1)/2].pb({i+1,w});
            p[i+1]={(i+1)/2,w};
        }
        dfs(1,0,adj);
        for(int i=0;i<m;i++){
            ll st,d;
            cin>>st>>d;
            ll c=upper_bound(all(dist[st]),d)-dist[st].begin(),ans=c*d-pre[st][c],up=p[st].ff,w=p[st].ss;
            d-=w;
            // cout<<ans<<' '<<d<<'\n';
            while(up&&d>0){
                ll x=upper_bound(all(dist[up]),d)-dist[up].begin(),y=upper_bound(all(dist[st]),d-w)-dist[st].begin();
                // cout<<st<<' '<<up<<' '<<d<<' '<<w<<' '<<x<<' '<<y<<'\n';
                ans+=(x-y)*d-pre[up][x]+pre[st][y]+w*y;
                c+=x-y;
                st=up,w=p[up].ss;
                up=p[up].ff;
                d-=w;
            }
            cout<<ans<<'\n';
        }
    }
}