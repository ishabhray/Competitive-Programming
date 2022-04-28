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
int p[2][1005];
int sz[2][1005];
int get(int i,int a){
    return p[i][a]=((p[i][a]==a)? a:get(i,p[i][a]));
}
void uni(int i,int a,int b){
    if(a==b) return;
    a=get(i,a);
    b=get(i,b);
    if(sz[i][a]>sz[i][b]) swap(a,b);
    p[i][a]=p[i][b];
    sz[i][b]+=sz[i][a];
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
        int n,m1,m2;
        cin>>n>>m1>>m2;
        for(int i=0;i<n;i++) p[0][i]=p[1][i]=i,sz[0][i]=sz[1][i]=1;
        for(int i=0;i<m1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            uni(0,u,v);
        }
        for(int i=0;i<m2;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            uni(1,u,v);
        }
        vv<ii>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(get(0,i)==get(0,j)||get(1,i)==get(1,j)) continue;
                uni(0,i,j);
                uni(1,i,j);
                ans.pb({i+1,j+1});
            }
        }
        cout<<ans.size()<<'\n';
        for(auto i:ans) cout<<i.ff<<' '<<i.ss<<'\n';
    }
}