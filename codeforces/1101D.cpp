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
bool prime[200001];
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
    for(int p=2;p<200001;p++)
        if(prime[p])
            primes.pb(p);
}
int a[200005];
ii leaf;
void dfs(int i,int par,vi adj[],int vis[],int dist[],int p,int d){
    dist[i]=d;
    if(dist[i]>leaf.ff)
        leaf={dist[i],i};
    vis[i]=p;
    for(int j:adj[i]){
        if(a[j]%p||j==par)
            continue;
        dfs(j,i,adj,vis,dist,p,d+1);
    }
}
int find_dia(int i,vi adj[],int vis[],int dist[],int p){
    leaf={0,0};
    dfs(i,-1,adj,vis,dist,p,1);
    int x=leaf.ss;
    leaf={0,0};
    dfs(x,-1,adj,vis,dist,p,1);
    return leaf.ff;
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
    SieveOfEratosthenes(200000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        vi idx[200005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            idx[a[i]].pb(i);
        }
        vi adj[n+1];
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int ans=0,vis[n+1]={0},dist[n+1]={0};
        for(int p:primes){
            vi v;
            for(int i=p;i<200005;i+=p){
                for(int j:idx[i]){
                    v.pb(j);
                }
            }
            for(int i:v){
                if(vis[i]!=p){
                    ans=max(ans,find_dia(i,adj,vis,dist,p));
                }
            }
        }
        cout<<ans;
    }
}