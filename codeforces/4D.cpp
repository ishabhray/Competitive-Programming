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
int h,w;
bool comp(pair<ii,int> &l,pair<ii,int> &r)
{
    if(l.ff.ff!=r.ff.ff)
        return l.ff.ff<r.ff.ff;
    else
        return l.ff.ss>r.ff.ss;
}
bool comp1(pair<ii,int> &l,pair<ii,int> &r)
{
    if((l.ff.ff<h||l.ff.ss<w)&&r.ff.ff>=h&&r.ff.ss>=w)
        return 1;
    if((r.ff.ff<h||r.ff.ss<w)&&l.ff.ff>=h&&l.ff.ss>=w)
        return 0;
    return 0;
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
        cin>>n>>h>>w;
        pair<ii,int> a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].ff.ff>>a[i].ff.ss;
            a[i].ss=i+1;
        }
        sort(a,a+n,comp1);
        int j=0;
        for(;j<n;j++){
            if(a[j].ff.ff>h&&a[j].ff.ss>w)
                break;
        }
        if(j==n){
            cout<<0;
            return 0;
        }
        sort(a+j,a+n,comp);
        ii x[n-j];
        for(int i=j;i<n;i++){
            x[i-j].ff=a[i].ff.ss;
            x[i-j].ss=a[i].ss;
        }

        int y=n-j;
        int dp[y]={0},ans=1;
        dp[0]=1;
        for(int i=1;i<y;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(x[j].ff<x[i].ff)
                    dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        cout<<ans<<'\n';
        int pre=1e8;
        vi v;
        for(int i=y-1;i>=0&&ans;i--){
            if(dp[i]==ans&&x[i].ff<pre){
                v.pb(x[i].ss);
                ans--;
                pre=x[i].ff;
            }
        }
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i]<<' ';
    }
}