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
ll dfs(int a,int vis[],vi adj[]){
    ll ans=1;
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i]) continue;
        ans+=dfs(i,vis,adj);
    }
    return ans;
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
        int a[n];
        for(auto &i:a) cin>>i;
        vi adj[200005];
        for(int i=0;i<n/2;i++){
            if(a[i]!=a[n-1-i]){
                adj[a[i]].pb(a[n-1-i]);
                adj[a[n-1-i]].pb(a[i]);
            }
        }
        int vis[200005]={0};
        ll ans=0;
        for(int i=1;i<=200000;i++){
            if(!vis[i]) ans+=dfs(i,vis,adj)-1;
        }
        cout<<ans<<'\n';
    }
}