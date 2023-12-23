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
vi adj[200005];
int tin[200005],tout[200005],vis[200005],t,l,r,nxt;
ll sz[200005],ans[200005];
void dfs(int a,int p){
    sz[a]++;
    tin[a]=t++;
    for(int i:adj[a]){
        if(i==p) continue;
        dfs(i,a);
        sz[a]+=sz[i];
    }
    tout[a]=t++;
}
void prop(int a, int dst){
    vis[a]=1;
    if(a==dst) return;
    for(int i:adj[a]){
        if(tin[dst]<tin[i]||tin[dst]>tout[i]||vis[i]) continue;
        if(a==0) nxt=i;
        prop(i,dst);
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n;
        cin>>n;
        for(int i=0;i<=n+1;i++){
            adj[i].clear();
            sz[i]=vis[i]=tin[i]=tout[i]=ans[i]=0;
        }
        t=l=r=nxt=0;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0,0);
        vis[0]=1;
        ans[0]=n*(n-1)/2;
        ll pre=1;
        for(ll i:adj[0]) ans[1]+=pre*sz[i],pre+=sz[i];
        for(int i=1;i<n;i++){
            while(!vis[i]){
                if(l==0){
                    if(tin[i]>=tin[r]&&tin[i]<=tout[r]) prop(r,i),r=i;
                    else if(tin[i]<tin[nxt]||tin[i]>tout[nxt]) prop(l,i),l=i;
                    else break;
                }
                else if(tin[i]>=tin[r]&&tin[i]<=tout[r]) prop(r,i),r=i;
                else if(tin[i]>=tin[l]&&tin[i]<=tout[l]) prop(l,i),l=i;
                else break;
            }
            if(!vis[i]) break;
            // cout<<l<<' '<<r<<' '<<nxt<<'\n';
            if(l==0) ans[i+1]=sz[r]*(n-sz[nxt]);
            else ans[i+1]=sz[l]*sz[r];
        }
        // for(int i=0;i<=n;i++) cout<<ans[i]<<' ';
        // cout<<'\n';
        for(int i=0;i<=n;i++) cout<<ans[i]-ans[i+1]<<' ';
        cout<<'\n';
    }
}