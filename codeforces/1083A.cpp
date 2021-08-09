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
ll w[300005],dp[300005],ans;
vv<pll>adj[300005];
void dfs(int a,int p){
    dp[a]=w[a];
    priority_queue<ll>q;
    for(auto i:adj[a]){
        if(i.ff==p)
            continue;
        dfs(i.ff,a);
        q.push(dp[i.ff]-i.ss);
    }
    if(q.size())
        dp[a]=max(dp[a],w[a]+q.top());
    if(q.size()>1){
        ll x=q.top();
        q.pop();
        ans=max(ans,x+q.top()+w[a]);
    }
    ans=max(ans,dp[a]);
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
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>w[i];
        for(int i=1;i<n;i++){
            int u,v,c;
            cin>>u>>v>>c;
            adj[u].pb({v,c});
            adj[v].pb({u,c});
        }
        dfs(1,0);
        cout<<ans<<'\n';
    }
}