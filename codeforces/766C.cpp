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

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        string s;
        cin>>n>>s;
        int a[26];
        for(int i=0;i<26;i++)
            cin>>a[i];
        int pre[26][n+1];
        memset(pre,0,sizeof(pre));
        for(int i=0;i<n;i++){
            pre[s[i]-'a'][i+1]++;
            for(int j=0;j<26;j++)
                pre[j][i+1]+=pre[j][i];
        }
        int dp[n+1]={0},dp1[n+1],mx=0;
        dp[0]=1;
        dp1[0]=0;
        for(int i=1;i<=n;i++){
            int mn=INT_MAX;
            for(int j=0;j<i;j++){
                int l=i-j;
                bool b=true;
                for(int c=0;c<26;c++){
                    if(pre[c][i]-pre[c][j]&&a[c]<l)
                        b=false;
                }
                if(b){
                    dp[i]=(dp[i]+dp[j])%MOD,mx=max(mx,l);
                    mn=min(mn,dp1[j]);
                    //cout<<i<<' '<<j<<' '<<mn<<'\n';
                }
            }
            dp1[i]=mn+1;
        }
        cout<<dp[n]<<'\n'<<mx<<'\n'<<dp1[n]<<'\n';
    }
}