#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
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

void dfs(int i,vi adj[],int vis[],ll p[],ll h[],ll cap[],ll hp[],bool &b){
    if(vis[i]||!b)
        return;
    vis[i]=1;
    cap[i]=p[i];
    ll x=0;
    for(auto a:adj[i]){
        if(vis[a])
            continue;
        dfs(a,adj,vis,p,h,cap,hp,b);
        if(!b)
            return;
        cap[i]+=cap[a];
        x+=hp[a];
    }
    if((cap[i]+h[i])%2||cap[i]+h[i]<0||h[i]>cap[i])
        b=false;
    hp[i]=(cap[i]+h[i])/2;
    if(x>hp[i])
        b=false;
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
    while(t--){
        int n,m;
        cin>>n>>m;
        ll p[n+1];
        for(int i=1;i<=n;i++)
            cin>>p[i];
        ll h[n+1];
        for(int i=1;i<=n;i++)
            cin>>h[i];
        vi adj[n+1];
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ll cap[n+1]={0};
        int vis[n+1]={0};
        ll hp[n+1]={0};
        bool b=true;
        dfs(1,adj,vis,p,h,cap,hp,b);
        
        if(b)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}