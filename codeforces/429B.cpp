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
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n,m;
        cin>>n>>m;
        ll a[n+2][m+2],dp1[n+2][m+2],dp2[n+2][m+2],dp3[n+2][m+2],dp4[n+2][m+2];
        memset(a,0,sizeof(a));
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp1));
        memset(dp3,0,sizeof(dp1));
        memset(dp4,0,sizeof(dp1));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)
                dp2[i][j]=max(dp2[i-1][j],dp2[i][j+1])+a[i][j];
        for(int i=n;i>=1;i--)
            for(int j=1;j<=m;j++)
                dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+a[i][j];
        for(int i=n;i>=1;i--)
            for(int j=m;j>=1;j--)
                dp4[i][j]=max(dp4[i+1][j],dp4[i][j+1])+a[i][j];
            ll ans=0;
        for(int i=2;i<=n-1;i++){
            for(int j=2;j<=m-1;j++){
                ans=max({ans,dp1[i-1][j]+dp4[i+1][j]+dp3[i][j-1]+dp2[i][j+1],dp1[i][j-1]+dp4[i][j+1]+dp2[i-1][j]+dp3[i+1][j]});
            }
        }
        cout<<ans;
    }
}