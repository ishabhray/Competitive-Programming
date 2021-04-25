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
bool prime[100001];
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
    for(int p=2;p<100001;p++)
        if(prime[p])
            primes.pb(p);
}
ll fact[100001];
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

int b[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    SieveOfEratosthenes(100000);
    //factorial(100000);
    while(t--){
        int n;
        cin>>n;
        int a[n],mn=INT_MAX,mx=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }
        for(int i=0;i<=1000000;i++)
            b[i]=1;
        for(int p:primes){
            int i=mn/p*p;
            while(i<mn||i<=p) i+=p;
            //cout<<p<<' '<<i<<'\n';
            for(;i<=mx;i+=p)
                b[i-mn]=0;
        }
        if(mn==1)
            b[0]=0;
        ll ans=0,cnt=0;
        
        for(int i=0;i<n;i++){
            if(b[a[i]-mn])
                cnt++,ans=max(ans,cnt);
            else
                cnt=0;
        }
        cout<<ans<<'\n';
    }
}