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
int l1(int a,int p,vi adj[]){
    for(int j:adj[a]){
        if(j==p)
            continue;
        return l1(j,a,adj);
    }
    return a;
}
int l2(int a,int p,vi adj[]){
    for(auto i=adj[a].rbegin();i!=adj[a].rend();i++){
        int j=*i;
        if(j==p)
            continue;
        return l1(j,a,adj);
    }
    return a;
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
        vi adj[n+1];
        int edges[n-1][3];
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb(v);
            adj[v].pb(u);
            edges[i][0]=u;
            edges[i][1]=v;
            edges[i][2]=w;
        }
        bool ans=true;
        for(auto i:edges){
            if(adj[i[0]].size()==2||adj[i[1]].size()==2){
                ans=false;
                break;
            }
        }
        if(!ans)
            cout<<"NO";
        else{
            ii leaf[n+1];
            cout<<"YES\n";
            vv<vi>ans;
            for(auto i:edges){
                int x=l1(i[0],i[1],adj),y=l2(i[0],i[1],adj);
                int x1=l1(i[1],i[0],adj),y1=l2(i[1],i[0],adj);
                ans.pb({x,x1,i[2]/2});
                ans.pb({y,y1,i[2]/2});
                if(x!=y)
                    ans.pb({x,y,-i[2]/2});
                if(x1!=y1)
                    ans.pb({x1,y1,-i[2]/2});
            }
            cout<<ans.size()<<'\n';
            for(auto i:ans)
                cout<<i[0]<<' '<<i[1]<<' '<<i[2]<<'\n';
        }
    }
}