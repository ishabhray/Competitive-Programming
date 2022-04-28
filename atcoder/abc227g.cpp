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
int MOD=998244353;
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
ll cnt[1000005];
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
    SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n,k;
        cin>>n>>k;
        vl x,y;
        for(ll i=1;i<=k;i++){
            x.pb(i);
            y.pb(n-k+i);
        }
        for(ll i:primes){
            for(ll j=i;j<=k;j+=i){
                while(x[j-1]%i==0) cnt[i]--,x[j-1]/=i;
            }
            for(ll j=(n-k+i)/i*i;j<=n;j+=i){
                while(y[j-(n-k+1)]%i==0) cnt[i]++,y[j-(n-k+1)]/=i;
            }
        }
        ll ans=1;
        for(int i=1;i<=1e6;i++) (ans*=(cnt[i]+1))%=MOD;
        for(ll i:y) if(i>1) (ans*=2)%=MOD;
        cout<<ans<<'\n';
    }
}