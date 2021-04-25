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
int dp[51][51][51][51],cnt[51][51];;
int solve(int x1,int y1,int x2,int y2){
    //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
    if(x1>x2||y1>y2)
        return 0;
    if(dp[x1][y1][x2][y2]!=-1)
        return dp[x1][y1][x2][y2];
    if(cnt[x2+1][y2+1]+cnt[x1][y1]-cnt[x1][y2+1]-cnt[x2+1][y1]==0)
        return dp[x1][y1][x2][y2]=0;
    if(x2==x1&&y2==y1)
        return dp[x1][y1][x2][y2]=1;
    dp[x1][y1][x2][y2]=max(x2-x1,y2-y1)+1;
    if(x2-x1>=y2-y1){
        for(int i=x1;i<=x2;i++){
            if(cnt[i+1][y2+1]+cnt[i][y1]-cnt[i][y2+1]-cnt[i+1][y1]==0)
                dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],solve(x1,y1,i-1,y2)+solve(i+1,y1,x2,y2));
        }
    }
    if(y2-y1>=x2-x1){
        for(int i=y1;i<=y2;i++){
            if(cnt[x2+1][i+1]+cnt[x1][i]-cnt[x1][i+1]-cnt[x2+1][i]==0)
                dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],solve(x1,y1,x2,i-1)+solve(x1,i+1,x2,y2));
        }
    }
    return dp[x1][y1][x2][y2];
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
        int n;
        cin>>n;
        string a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='#')
                    cnt[i+1][j+1]++;
                cnt[i+1][j+1]+=cnt[i][j+1]+cnt[i+1][j]-cnt[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0,n-1,n-1);
    }
}