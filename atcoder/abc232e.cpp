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
ll dp[1000005][4];
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
        ll h,w,k;
        cin>>h>>w>>k;
        ll x,y,x1,y1;
        cin>>x>>y>>x1>>y1;
        
        dp[0][0]=1;
        dp[0][1]=dp[0][2]=dp[0][3]=0;
        for(int i=1;i<=k;i++){
            dp[i][0]=((h-1)*dp[i-1][1]%MOD+(w-1)*dp[i-1][2]%MOD)%MOD;
            dp[i][1]=((h-2)*dp[i-1][1]%MOD+(w-1)*dp[i-1][3]%MOD+dp[i-1][0])%MOD;
            dp[i][2]=((w-2)*dp[i-1][2]%MOD+(h-1)*dp[i-1][3]%MOD+dp[i-1][0])%MOD;
            dp[i][3]=(dp[i-1][1]+dp[i-1][2]+(h+w-4)*dp[i-1][3]%MOD)%MOD;
        }
        ll ans=0;
        if(x1==x&&y1==y) ans=dp[k][0];
        else if(x1==x) ans=dp[k][2];
        else if(y1==y) ans=dp[k][1];
        else ans=dp[k][3];
        cout<<ans<<'\n';
    }
}