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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=0;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(int p=2;p<1000001;p++)
        if(prime[p])
            primes.pb(p);
}
ll fact[1000010];
ll finv[1000010];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return 0;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
    }
}
void dfs(int i,int pr,vi adj[],ll p[],ll sz[],ll ans[],ll a[],set<pll>s[]){
    sz[i]=1;
    ans[i]=a[i];
    p[i]=pr;
    for(auto j:adj[i]){
        if(j!=pr){
            dfs(j,i,adj,p,sz,ans,a,s);
            s[i].insert({-sz[j],j});
            sz[i]+=sz[j];
            ans[i]+=ans[j];
        }
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
        ll a[n+1],p[n+1]={0},sz[n+1]={0},ans[n+1]={0};
        for(ll i=1;i<=n;i++) cin>>a[i];
        vi adj[n+1];
        for(int i=0;i+1<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        set<pll>s[n+1];
        dfs(1,0,adj,p,sz,ans,a,s);
        for(int i=0;i<m;i++){
            int t,x;
            cin>>t>>x;
            if(t==1){
                cout<<ans[x]<<'\n';
                continue;
            }
            if(s[x].empty()) continue;
            ll y=sz[x],z=ans[x];
            ll son=s[x].begin()->ss;
            s[x].erase(s[x].begin());
            s[p[x]].erase({-sz[x],x});
            sz[x]-=sz[son];
            ans[x]-=ans[son];
            p[son]=p[x];
            p[x]=son;
            sz[son]=y;
            ans[son]=z;
            s[p[son]].insert({-sz[son],son});
            s[son].insert({-sz[x],x});
        }
    }
}