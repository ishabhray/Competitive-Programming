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
        int n,m;
        cin>>n>>m;
        ll dp[n+1][m+1][m+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0]=1;
        for(int i=0;i<n;i++){
            for(int a=0;a<=m;a++){
                for(int b=0;b<=m;b++){
                    for(int c=0;c<=m;c++){
                        for(int d=1;d<=m;d++){
                            if(c){
                                if(d>c) continue;
                                else if(d>b) (dp[i+1][a][b][d]+=dp[i][a][b][c])%=MOD;
                                else if(d>a) (dp[i+1][a][d][c]+=dp[i][a][b][c])%=MOD;
                                else (dp[i+1][d][b][c]+=dp[i][a][b][c])%=MOD;
                            }
                            else{
                                if(b){
                                    if(d>b) (dp[i+1][a][b][d]+=dp[i][a][b][c])%=MOD;
                                    else if(d>a) (dp[i+1][a][d][0]+=dp[i][a][b][c])%=MOD;
                                    else (dp[i+1][d][b][0]+=dp[i][a][b][c])%=MOD;
                                }
                                else{
                                    if(a){
                                        if(d>a) (dp[i+1][a][d][0]+=dp[i][a][b][c])%=MOD;
                                        else (dp[i+1][d][0][0]+=dp[i][a][b][c])%=MOD;
                                    }
                                    else (dp[i+1][d][0][0]+=dp[i][a][b][c])%=MOD;
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans=0;
        for(int a=1;a<=m;a++){
            for(int b=1;b<=m;b++){
                for(int c=1;c<=m;c++){
                    (ans+=dp[n][a][b][c])%=MOD;
                }
            }
        }
        cout<<ans<<'\n';
    }
}