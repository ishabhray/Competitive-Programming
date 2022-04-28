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
        int n,k;
        cin>>n>>k;
        char a[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!='a') dp[i][j]++;
                if(i&&j) dp[i][j]+=min(dp[i][j-1],dp[i-1][j]);
                else if(i) dp[i][j]+=dp[i-1][j];
                else if(j) dp[i][j]+=dp[i][j-1];
            }
        }
        set<ii>s;
        int mx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]<=k){
                    if(i+j==mx) s.insert({i,j});
                    else if(i+j>mx){
                        mx=i+j;
                        s.clear();
                        s.insert({i,j});
                    }
                }
            }
        }
        string ans="";
        for(int i=0;i<=mx;i++) ans+='a';
        if(mx==-1){
            ans+=a[0][0];
            s.insert({0,0});
            mx++;
        }
        mx++;
        while(mx<=2*n-2){
            set<ii>curr;
            char mn='z';
            for(int i=max(0,mx-n+1);i<=min(n-1,mx);i++){
                int j=mx-i;
                if(s.count({i-1,j})||s.count({i,j-1})){
                    if(a[i][j]==mn) curr.insert({i,j});
                    else if(a[i][j]<mn){
                        curr.clear();
                        mn=a[i][j];
                        curr.insert({i,j});
                    }
                }
            }
            ans+=mn;
            mx++;
            s=curr;
        }
        cout<<ans<<'\n';
    }
}
