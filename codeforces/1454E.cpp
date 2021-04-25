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
ll MOD=5e18;
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
ll fact[100010];
ll finv[100010];
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
set<int> cyc;
ll ans=0;
bool dfs(int a,int p,vi adj[],int vis[],stack<int> &s){
    vis[a]=1;
    s.push(a);
    bool f=false;
    for(int i:adj[a]){
        if(i==p)
            continue;
        if(vis[i]){
            cyc.insert(i);
            while(s.top()!=i){
                cyc.insert(s.top());
                s.pop();
            }
            return true;
        }
        f|=dfs(i,a,adj,vis,s);
        if(f)
            return true;
    }
    if(f)
        return f;
    s.pop();
    return false;
}
ll dfs1(int a,vi adj[],int vis[]){
    ll x=1;
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i]||cyc.find(i)!=cyc.end())
            continue;
        x+=dfs1(i,adj,vis);
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        vi adj[n+1];
        cyc.clear();
        ans=0;
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int vis[n+1]={0};
        stack<int>st;
        dfs(1,-1,adj,vis,st);
        memset(vis,0,sizeof(vis));
        ll cyclen=(ll)cyc.size();
        ans=cyclen*(cyclen-1);
        for(int i:cyc){
            ll x=dfs1(i,adj,vis);
            x--;
            //cout<<x<<' ';
            ans+=x*(2*cyclen-1)+x*(x-1)/2+x*(n-cyclen-x);
        }
        cout<<ans<<'\n';
    }
}