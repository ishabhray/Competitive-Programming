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
        int n,h;
        cin>>n>>h;
        int x[n+1]={0};
        for(int i=1;i<=n;i++) cin>>x[i];
        int p[n]={0},f[n]={0};
        for(int i=1;i<n;i++)
            cin>>p[i]>>f[i];
        vv<vi>dp(h+1,vi(h+1,0));
        // for(int i=0;i<=h;i++){
        //     for(int j=0;j<=h;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        for(int k=1;k<n;k++){
            vv<vi>dp1(h+1,vi(h+1,1e9));
            int req=x[k]-x[k-1];
            for(int i=0;i<=h;i++){
                for(int j=0;j<=h;j++){
                    if(i+req<=h&&j-req>=0) dp1[i][j]=min(dp1[i][j],dp[i+req][j-req]);
                    if(req+max(0,i-f[k])<=h&&j-req>=0) dp1[i][j]=min(dp1[i][j],dp[req+max(0,i-f[k])][j-req]+p[k]);
                    if(i+req<=h&&min(h,j+f[k])-req>=0) dp1[i][j]=min(dp1[i][j],dp[i+req][min(h,j+f[k])-req]+p[k]);
                }
            }
            swap(dp,dp1);
            // cout<<k<<'\n';
            // for(int i=0;i<=h;i++){
            //     for(int j=0;j<=h;j++) cout<<dp[i][j]<<' ';
            //     cout<<'\n';
            // }
        }
        int z=x[n]-x[n-1],ans=1e9;
        for(int i=2*z;i<=h;i++){
            ans=min(ans,dp[i][i-2*z]);
        }
        if(ans==1e9) ans = -1;
        cout<<ans<<'\n';
    }
}