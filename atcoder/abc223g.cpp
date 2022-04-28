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
int n;
vi adj[200005];
int mat[200005],dp[200005];
void dfs(int a,int p){
    for(int i:adj[a]){
        if(i==p) continue;
        dfs(i,a);
        if(!mat[i]&&!mat[a]) mat[a]=i,mat[i]=a;
    }
}
void dfs1(int a,int p){
    if(!mat[a]) dp[a]=1;
    if(mat[a]!=p){
        bool b=false;
        for(int i:adj[a]){
            if(!mat[i]) b=true;
        }
        if(b) mat[mat[a]]=0;
    }
    for(int i:adj[a]){
        if(i==p) continue;
        dfs1(i,a);
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
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);
        dfs1(1,0);
        int ans=0;
        for(int i=1;i<=n;i++) ans+=dp[i];
        cout<<ans<<'\n';
    }
}