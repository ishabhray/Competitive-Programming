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

void dfs(int i,vi adj[],int vis[],stack<int>&s,int ty[])
{
    if(vis[i]||ty[i]==2)
        return;
    vis[i]=1;
    for(int j:adj[i])
        dfs(j,adj,vis,s,ty);
    s.push(i);
}
int dfs1(int i,vi adj[],int vis[],int ty[])
{
    vis[i]=1;
    if(ty[i]==1)
        return 1;
    if(ty[i]==2)
        return -1;
    if(adj[i].empty()||vis[adj[i][0]])
        return -1;
    int y=dfs1(adj[i][0],adj,vis,ty);
    if(y==-1)
        return -1;
    else
        return 1+y;
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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        int ty[n+1];
        for(int i=1;i<=n;i++)
            cin>>ty[i];
        vi adj[n+1];
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            adj[x].pb(i);
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size()>1){
                ty[i]=2;
            }
        }
        int vis[n+1]={0};
        stack<int>s;
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            dfs(i,adj,vis,s,ty);
        }
        memset(vis,0,sizeof(vis));
        int ans=0,pos;
        while(!s.empty()){
            int x=s.top();
            s.pop();
            if(vis[x])
                continue;
            int y=dfs1(x,adj,vis,ty);
            if(y>ans)
                ans=y,pos=x;
        }
        cout<<ans<<'\n';
        while(ans--){
            cout<<pos<<' ';
            if(!adj[pos].empty())
            pos=adj[pos][0];
        }
    }
}