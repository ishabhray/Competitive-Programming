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
ll fact[1001];
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
    //factorial(1000);
    while(t--){
        int h,w;
        cin>>h>>w;
        char a[h][w];
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin>>a[i][j];
        int dp[h][w];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(i==0&&j==0){
                    if(a[i][j]=='#')
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else if(i==0){
                    if(a[i][j]=='.'||a[i][j]==a[i][j-1])
                        dp[i][j]=dp[i][j-1];
                    else
                        dp[i][j]=1+dp[i][j-1];
                }
                else if(j==0){
                    if(a[i][j]=='.'||a[i][j]==a[i-1][j])
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j]=1+dp[i-1][j];
                }
                else{
                    if(a[i][j]=='.')
                        dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                    else{
                        int x,y;
                        if(a[i][j]==a[i-1][j])
                            x=dp[i-1][j];
                        else
                            x=dp[i-1][j]+1;
                        if(a[i][j]==a[i][j-1])
                            y=dp[i][j-1];
                        else
                            y=dp[i][j-1]+1;
                        dp[i][j]=min(x,y);
                        //cout<<x<<' '<<y<<'\n';
                    }
                }
            }
        }
        
        cout<<dp[h-1][w-1];
    }
}