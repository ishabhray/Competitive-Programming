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
ll dp[505][505],nCr[1005][505];
ll ncr(ll n,ll r)
{
    if(nCr[n][r]!=-1) return nCr[n][r];
    if(n<r)
        return 0;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return nCr[n][r]=fact[n]*x%MOD;
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
    memset(nCr,-1,sizeof(nCr));
    factorial(1005);
    while(te--){
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i>j) dp[i][j]=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(j==i+1){
                    dp[i][j]=(s[i]==s[j]);
                    continue;
                }
                for(int k=i+1;k<=j;k++){
                    if(s[i]==s[k]){
                        ll x=(k-i+1)/2,y=(j-k)/2;
                        (dp[i][j]+=dp[i+1][k-1]*dp[k+1][j]%MOD*ncr(x+y,x)%MOD)%=MOD;
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        cout<<dp[0][n-1]<<'\n';
    }
}