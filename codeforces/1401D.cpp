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
ll fact[1001];
void factorial(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=fact[r]*fact[n-r]%MOD;
        return fact[n]*fermat_inv(x)%MOD;
    }
}

void dfs(int i,vi adj[],bool vis[],ll cnt[]){
    if(vis[i])
        return;
    vis[i]=1;
    for(int j:adj[i]){
        if(vis[j])
            continue;
        dfs(j,adj,vis,cnt);
        cnt[i]+=cnt[j];
    }
    cnt[i]++;
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
    //factorial(1000);
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
        int m;
        cin>>m;
        vl p(m);
        for(int i=0;i<m;i++)
            cin>>p[i];
        sort(p.begin(),p.end());
        while(m>n-1){
            ll x=p.back();
            p.erase(p.end()-1);
            m--;
            p[m-1]*=x;
            p[m-1]%=MOD;
        }
        bool vis[n+1]={0};
        ll cnt[n+1]={0};
        dfs(1,adj,vis,cnt);
        
        priority_queue<ll>q;
        for(int i=1;i<=n;i++)
            q.push(cnt[i]*(n-cnt[i]));
        ll ans=0;
        while(!q.empty()){
            if(m)
                ans+=q.top()*p[--m],ans%=MOD;
            else
                ans+=q.top(),ans%=MOD;
            q.pop();
        }
        cout<<ans<<'\n';
    }
}