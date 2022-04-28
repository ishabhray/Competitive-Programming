#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll, ll>
#define vv vector
#define all(v) (v).begin(), (v).end()
#define MAXN 300005
int MOD = 998244353;
ll power(ll a, ll b)
{ //a^b
    ll res = 1;
    a = a % MOD;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
            b--;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll fermat_inv(ll y) { return power(y, MOD - 2); }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll min(ll a, ll b) { return (a > b) ? b : a; }
ll max(ll a, ll b) { return (a > b) ? a : b; }
bool dfs(int a,int p,int x,int dp[],vi adj[]){
    for(int i:adj[a]){
        if(i==p) continue;
        if(!dfs(i,a,x,dp,adj)) return false;
    }
    if(p!=-1){
        if(dp[a]%x) dp[a]++;
        else dp[p]++;
    }
    return (dp[a]%x==0);
}
bool solve(vi adj[],int n,int p){
    int dp[n]={0};
    return dfs(0,-1,p,dp,adj);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te = 1;
    cin >> te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    ll m[100005] = {0}, prime[100005] = {0};
    vi primes;
    m[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        if (!prime[i])
        {
            primes.pb(i);
            m[i] = -1;
        }
        for (int j = 0; j < primes.size() && primes[j] * i <= 100000; j++)
        {
            prime[i * primes[j]] = 1;
            m[i * primes[j]] = m[i] * m[primes[j]];
            if (i % primes[j] == 0)
            {
                m[i * primes[j]] = 0;
                break;
            }
        }
    }
    while (te--)
    {
        int n;
        cin>>n;
        vi adj[n];
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll ans[n+1]={0};
        ans[1]=power(2,n-1);
        for(int i=2;i<n;i++){
            if((n-1)%i) continue;
            ans[i]=solve(adj,n,i);
        }
        for(int i=1;i<=n;i++){
            if(ans[i]) for(int j=2;i*j<=n;j++) (ans[i]+=m[j]*ans[j*i]+MOD)%=MOD;
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}