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
int k;
ll dp[100005][2],ans=0;
void dfs(int a,int p,vv<pll>adj[]){
    dp[a][0]=dp[a][1]=0;
    priority_queue<ll>q;
    priority_queue<pll>qq;
    map<ll,ll>wt;
    for(auto i:adj[a]){
        if(i.ff==p)
            continue;
        dfs(i.ff,a,adj);
        q.push(i.ss+dp[i.ff][1]);
        qq.push({i.ss+dp[i.ff][1],i.ff});
        wt[i.ff]=i.ss;
    }
    ll c=0,z=0;
    while(q.size()&&c<k-1){
        dp[a][1]+=q.top();
        q.pop();
        c++;
    }
    c=0;
    if(q.size())
        z=q.top();
    while(qq.size()){
        auto x=qq.top();
        qq.pop();
        c++;
        ll curr=dp[a][1];
        if(c<=k-1){
            curr-=x.ff;
            curr+=z;
        }
        curr+=dp[x.ss][0]+wt[x.ss];
        dp[a][0]=max(dp[a][0],curr);
    }
    ans=max({ans,dp[a][0],dp[a][1]});
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
        int n;
        cin>>n>>k;
        vv<pll>adj[n];
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        memset(dp,0,sizeof(dp));
        dfs(0,-1,adj);
        cout<<ans<<'\n';
    }
}