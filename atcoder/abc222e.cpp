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
int MOD=998244353;
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
vi path;
bool dfs(int a,int p,int e,vi adj[]){
    path.pb(a);
    if(a==e) return true;
    for(int i:adj[a]){
        if(i==p) continue;
        if(dfs(i,a,e,adj)) return true;
    }
    path.pop_back();
    return false;
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
        int n,m,k;
        cin>>n>>m>>k;
        int a[m];
        for(int &i:a) cin>>i;
        vi adj[n+1];
        map<ii,int>mp;
        int c[n-1]={0};
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            mp[{u,v}]=mp[{v,u}]=i;
        }
        for(int i=1;i<m;i++){
            int st=a[i-1],e=a[i];
            path.clear();
            dfs(st,0,e,adj);
            for(int j=1;j<path.size();j++){
                c[mp[{path[j-1],path[j]}]]++;
            }
        }
        n--;
        vi dp(2e5+5,0);
        dp[1e5]=1;
        for(int i=0;i<n;i++){
            vi curr(2e5+5,0);
            for(int j=0;j<=2e5;j++){
                if(j+c[i]<=2e5) (curr[j+c[i]]+=dp[j])%=MOD;
                if(j-c[i]>=0) (curr[j-c[i]]+=dp[j])%=MOD;
            }
            swap(dp,curr);
        }
        cout<<dp[k+1e5]<<'\n';
    }
}