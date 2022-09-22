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
ll sqrt(ll a){
    ll l=1,r=3e9,ans;
    while(l<=r){
        ll mid=(l+r)/2;
        if(mid*mid<=a)
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    return ans;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    ll z=55000;
    ll dp[z]={0},pre1[z]={0},pre2[z]={0};
    dp[1]=1;
    pre1[1]=1;
    for(ll i=2;i<z;i++){
        ll x=sqrt(i),y=sqrt(x);
        dp[i]=x*pre1[y]-pre2[y];
        pre1[i]=pre1[i-1]+dp[i];
        pre2[i]=pre2[i-1]+dp[i]*(i*i-1);
    }
    // for(ll i=2;i<z;i++){
    //     for(ll j=1;j*j<=i;j++) dp[i]+=dp[j];
    // }
    // for(int i=0;i<100;i++) cout<<pre1[z-1-i]<<'\n';
    while(te--){
        ll x;
        cin>>x;
        ll ans=0;
        ll z=sqrt(x),y=sqrt(z);
        ans=z*pre1[y]-pre2[y];
        // for(ll i=1;i*i*i*i<=x;i++) ans+=dp[i]*(z-i*i+1);
        cout<<ans<<'\n';
    }
}
