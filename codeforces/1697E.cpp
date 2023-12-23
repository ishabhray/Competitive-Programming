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
void dfs(int a,vi adj[],set<int>&v){
    v.insert(a);
    for(int i:adj[a]){
        if(v.count(i)) continue;
        dfs(i,adj,v);
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
    factorial(105);
    while(te--){
        int n;
        cin>>n;
        ii a[n];
        for(ii &i:a) cin>>i.ff>>i.ss;
        vi adj[n];
        for(int i=0;i<n;i++){
            vi v;
            int mn=1e9;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                int d=abs(a[i].ff-a[j].ff)+abs(a[i].ss-a[j].ss);
                if(d<mn){
                    mn=d;
                    v.clear();
                    v.pb(j);
                }
                else if(d==mn){
                    v.pb(j);
                }
            }
            for(int j:v) adj[i].pb(j);
        }
        int vis[n]={0};
        vi v;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            set<int>curr;
            dfs(i,adj,curr);
            bool f=true;
            for(int i:curr){
                for(int j:curr){
                    if(i==j) continue;
                    if(find(all(adj[i]),j)==adj[i].end()){
                        f=false;
                        break;
                    }
                }
            }
            if(f){
                v.pb(curr.size());
                for(int i:curr) vis[i]=1;
            }
            else{
                v.pb(1);
                vis[i]=1;
            }
        }
        sort(all(v));
        int m=n;
        n=v.size();
        ll dp[n][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][1]++;
        if(v[0]>1) dp[0][v[0]]++;
        for(int i=1;i<n;i++){
            for(int j=1;j<=m;j++){
                (dp[i][j]+=dp[i-1][j-1])%=MOD;
                if(v[i]>1&&j>=v[i]) (dp[i][j]+=dp[i-1][j-v[i]])%=MOD;
            }
        }
        ll ans=0;
        // for(int i:v) cout<<i<<' ';
        // cout<<'\n';
        // for(int i=0;i<n;i++){
        //     for(int j=1;j<=m;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        for(int j=1;j<=m;j++) (ans+=ncr(m,j)*fact[j]%MOD*dp[n-1][j]%MOD)%=MOD;
        cout<<ans<<'\n';
    }
}