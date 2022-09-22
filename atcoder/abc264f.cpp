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
ll dp[2000][2000][2][2];
ll n,m;
ll r[2000],c[2000];
string s[2000];
ll solve(char x){
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j][0][0]=dp[i][j][0][1]=dp[i][j][1][0]=dp[i][j][1][1]=1e18;
    if(s[0][0]==x) dp[0][0][0][0]=dp[0][0][1][0]=0,dp[0][0][0][1]=dp[0][0][1][1]=r[0]+c[0];
    else dp[0][0][0][1]=dp[0][0][1][0]=r[0],dp[0][0][0][0]=dp[0][0][1][1]=c[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+1<n){
                if(s[i+1][j]==x){
                    dp[i+1][j][0][0]=min(dp[i+1][j][0][0],dp[i][j][1][0]);
                    dp[i+1][j][0][1]=min(dp[i+1][j][0][1],dp[i][j][1][1]+r[i+1]);
                    dp[i+1][j][1][0]=min(dp[i+1][j][1][0],dp[i][j][1][0]);
                    dp[i+1][j][1][1]=min(dp[i+1][j][1][1],dp[i][j][1][1]+r[i+1]);
                }
                else{
                    dp[i+1][j][0][0]=min(dp[i+1][j][0][0],dp[i][j][1][1]);
                    dp[i+1][j][0][1]=min(dp[i+1][j][0][1],dp[i][j][1][0]+r[i+1]);
                    dp[i+1][j][1][0]=min(dp[i+1][j][1][0],dp[i][j][1][0]+r[i+1]);
                    dp[i+1][j][1][1]=min(dp[i+1][j][1][1],dp[i][j][1][1]);
                }
            }
            if(j+1<m){
                if(s[i][j+1]==x){
                    dp[i][j+1][0][0]=min(dp[i][j+1][0][0],dp[i][j][0][0]);
                    dp[i][j+1][0][1]=min(dp[i][j+1][0][1],dp[i][j][0][1]+c[j+1]);
                    dp[i][j+1][1][0]=min(dp[i][j+1][1][0],dp[i][j][0][0]);
                    dp[i][j+1][1][1]=min(dp[i][j+1][1][1],dp[i][j][0][1]+c[j+1]);
                }
                else{
                    dp[i][j+1][0][0]=min(dp[i][j+1][0][0],dp[i][j][0][0]+c[j+1]);
                    dp[i][j+1][0][1]=min(dp[i][j+1][0][1],dp[i][j][0][1]);
                    dp[i][j+1][1][0]=min(dp[i][j+1][1][0],dp[i][j][0][1]);
                    dp[i][j+1][1][1]=min(dp[i][j+1][1][1],dp[i][j][0][0]+c[j+1]);
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<dp[i][j][0][0]<<'.'<<dp[i][j][0][1]<<'.'<<dp[i][j][1][0]<<'.'<<dp[i][j][1][1]<<' ';
    //     cout<<'\n';
    // }
    return min({dp[n-1][m-1][0][0],dp[n-1][m-1][0][1],dp[n-1][m-1][1][0],dp[n-1][m-1][1][1]});
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
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>r[i];
        for(int i=0;i<m;i++) cin>>c[i];
        for(int i=0;i<n;i++) cin>>s[i];
        cout<<min(solve('0'),solve('1'))<<'\n';
    }
}