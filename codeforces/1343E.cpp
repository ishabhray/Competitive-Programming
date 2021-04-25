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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        ll n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;
        ll cost[m];
        for(ll i=0;i<m;i++)
            cin>>cost[i];
        sort(cost,cost+m);
        vi adj[n+1];
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll dista[n+1],distb[n+1],distc[n+1];
        memset(dista,-1,sizeof(dista));
        memset(distb,-1,sizeof(distb));
        memset(distc,-1,sizeof(distc));
        dista[a]=0,distb[b]=0,distc[c]=0;
        queue<ll>q;
        q.push(a);
        while(!q.empty()){
            ll x=q.front();
            q.pop();
            for(ll i:adj[x]){
                if(dista[i]==-1){
                    dista[i]=dista[x]+1;
                    q.push(i);
                }
            }
        }
        q.push(b);
        while(!q.empty()){
            ll x=q.front();
            q.pop();
            for(ll i:adj[x]){
                if(distb[i]==-1){
                    distb[i]=distb[x]+1;
                    q.push(i);
                }
            }
        }
        q.push(c);
        while(!q.empty()){
            ll x=q.front();
            q.pop();
            for(ll i:adj[x]){
                if(distc[i]==-1){
                    distc[i]=distc[x]+1;
                    q.push(i);
                }
            }
        }
        ll pref[m+1]={0};
        for(ll i=1;i<=m;i++)
            pref[i]=pref[i-1]+cost[i-1];
        ll ans=LLONG_MAX;
        for(int i=1;i<=n;i++){
            if(dista[i]+distb[i]+distc[i]>m)
                continue;
            ans=min(ans,pref[distb[i]]+pref[dista[i]+distb[i]+distc[i]]);
        }
        cout<<ans<<'\n';
    }
}