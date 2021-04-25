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
ll fact[100005];
ll finv[100005];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
    }
}
string s;
int cnt,parity[n+1],exc[n+1],req[n+1];
void dfs(int i,vi adj[],int vis[],int j)
{
    if(vis[i])
        return;
    vis[i]=1;
    parity[i]=j;
    if(!j)
        cnt++;
    for(int k:adj[i])
        dfs(k,adj,vis,!j);
}

int dfs1(int i,vi adj,int vis,int k)
{
    if(vis[i])
        return;
    vis[i]=1;
    for(int j:adj[i]){
        if(vis[j])
            continue;
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

    int t=1;
    cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n;
        cin>>n;
        vi adj[n+1];
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cin>>s;
        cnt=0;
        int cntr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                cntr++;
        }
        int vis[n+1]={0};
        dfs(1,adj,vis,0);
        if(cntr!=cnt&&cntr!=n-cnt){
            cout<<"-1\n";
            continue;
        }
        else if(cntr==cnt&&cntr==n-cnt){
            memset(vis,0,sizeof(vis));
            ll ans=dfs1(1,adj,vis,0);
            memset(vis,0,sizeof(vis));
            ans=min(ans,dfs1(1,adj,vis,1));
            cout<<ans<<'\n';
        }
        else if(cntr==cnt){
            memset(vis,0,sizeof(vis));
            cout<<dfs1(1,adj,vis,0);
        }
        else{
            memset(vis,0,sizeof(vis));
            cout<<dfs1(1,adj,vis,1);
        }
    }
}