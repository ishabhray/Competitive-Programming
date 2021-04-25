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

int p[300005],r[300005],mn[300005],mx[300005],sz[300005];
int get(int a)
{
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b)
{
    a=get(a);
    b=get(b);
    mn[b]=min(mn[b],mn[a]);
    mx[b]=max(mx[b],mx[a]);
    mn[a]=mn[b];
    mx[a]=mx[b];
    if(a!=b)
        sz[a]+=sz[b],sz[b]=sz[a];
    if(r[a]==r[b])
        r[a]++;
    if(r[a]>r[b])
        p[b]=a;
    else
        p[a]=b;
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
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=300000;i++)
            p[i]=i,mn[i]=i,mx[i]=i,r[i]=0,sz[i]=1;
        while(m--){
            string s;
            int u,v;
            cin>>s;
            if(s=="get"){
                cin>>u;
                u=get(u);
                cout<<mn[u]<<' '<<mx[u]<<' '<<sz[u]<<'\n';
            }
            else{
                cin>>u>>v;
                uni(u,v);
            }
        }
    }
}