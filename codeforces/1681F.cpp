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
vv<ii>adj[500005];
vi sz(500005);
void dfs(int a,int p){
    sz[a]=1;
    for(auto i:adj[a]){
        if(i.ff==p) continue;
        dfs(i.ff,a);
        sz[a]+=sz[i.ff];
    }
}
map<ll,ll>s[500005];
ll ans=0;
void dfs1(int a,int p){
    int mx=0,idx=0,wt=0;
    for(auto i:adj[a]){
        if(i.ff==p) continue;
        dfs1(i.ff,a);
        if(s[i.ff].size()>=mx) mx=s[i.ff].size(),idx=i.ff,wt=i.ss;
    }
    // cout<<a<<' '<<idx<<'\n';
    if(idx){
        swap(s[a],s[idx]);
        ll sum=sz[idx]+1;
        ans+=sz[idx]-s[idx][wt];
        s[a][wt]=sz[idx];
        for(auto i:adj[a]){
            if(i.ff==p||i.ff==idx) continue;
            ans+=sum-1;
            ans+=sz[i.ff]*sum;
            s[i.ff][i.ss]=sz[i.ff];
            for(auto j:s[i.ff]){
                ans-=j.ss*s[a][j.ff];
                s[a][j.ff]+=j.ss;
            }
            sum+=sz[i.ff];
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
        int n;
        cin>>n;
        
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
        }
        dfs(1,0);
        dfs1(1,0);
        cout<<ans<<'\n';
    }
}