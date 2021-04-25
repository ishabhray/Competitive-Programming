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
int MOD=1e8;
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

int dp[105][105][12][12];

int solve(int n1,int n2,int c1,int c2,int k1,int k2)
{
    //cout<<n1<<' '<<n2<<' '<<c1<<' '<<c2<<'\n';
    if(dp[n1][n2][c1][c2]!=-1)
        return dp[n1][n2][c1][c2];
    if(!n1&&!n2)
        return dp[n1][n2][c1][c2]=1;
    dp[n1][n2][c1][c2]=0;
    if(n1!=0&&c1<k1)
        dp[n1][n2][c1][c2]+=solve(n1-1,n2,c1+1,0,k1,k2),dp[n1][n2][c1][c2]%=MOD;
    if(n2!=0&&c2<k2)
        dp[n1][n2][c1][c2]+=solve(n1,n2-1,0,c2+1,k1,k2),dp[n1][n2][c1][c2]%=MOD;
    return dp[n1][n2][c1][c2];
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
        int n1,n2,k1,k2;
        cin>>n1>>n2>>k1>>k2;
        memset(dp,-1,sizeof(dp));
        cout<<solve(n1,n2,0,0,k1,k2);
    }
}