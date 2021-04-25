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

vi adj[200005];
ll dist[200005],subtreesum[200005],a[200005];
ll ans=0,sum=0;

void dfs(int i,int p){
    subtreesum[i]+=a[i];
    for(int j:adj[i]){
        if(j==p)
            continue;
        dfs(j,i);
        subtreesum[i]+=subtreesum[j];
        dist[i]+=dist[j];
    }
    dist[i]+=subtreesum[i]-a[i];
}
void calc(int i,int p){
    ans=max(ans,dist[i]);
    for(int j:adj[i]){
        if(j==p)
            continue;
        dist[j]+=dist[i]-dist[j]-subtreesum[j]+sum-subtreesum[j];
        //cout<<j<<' '<<dist[j]<<'\n';
        calc(j,i);
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
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i+1];
            sum+=a[i+1];
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,-1);
        calc(1,-1);
        //for(int i=1;i<=n;i++)
          //  cout<<subtreesum[i]<<' '<<dist[i]<<'\n';
        cout<<ans<<'\n';
    }
}