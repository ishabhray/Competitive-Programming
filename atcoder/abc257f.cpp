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
void find_dist(int st,int dist[],vi adj[],int n){
    for(int i=0;i<=n;i++) dist[i]=1e8;
    dist[st]=0;
    queue<int>q;
    q.push(st);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
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
        vi adj[n+1];
        vi s;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            if(u) adj[u].pb(v),adj[v].pb(u);
            else s.pb(v);
        }
        int dist1[n+1],distN[n+1];
        find_dist(1,dist1,adj,n);
        find_dist(n,distN,adj,n);
        int mn1=1e8,mnN=1e8;
        for(int i:s){
            mn1=min(mn1,dist1[i]);
            mnN=min(mnN,distN[i]);
        }
        for(int i=1;i<=n;i++){
            int ans=dist1[n];
            ans=min(ans,mn1+mnN+2);
            ans=min(ans,mn1+distN[i]+1);
            ans=min(ans,mnN+dist1[i]+1);
            if(ans>=1e8) ans=-1;
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
}