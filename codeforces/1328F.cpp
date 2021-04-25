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
        int n,k;
        cin>>n>>k;
        map<int,int>m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            m[x]++;
        }
        int sz=m.size();
        pll a[sz];
        int i=0;
        for(auto j:m)
            a[i++]=j;
        ll prefsum[sz+1]={0},prefcnt[sz+1]={0},suffsum[sz+1]={0},suffcnt[sz+1]={0};
        for(int j=0;j<sz;j++){
            prefsum[j+1]=a[j].ff*a[j].ss;
            prefsum[j+1]+=prefsum[j];
            prefcnt[j+1]=a[j].ss;
            prefcnt[j+1]+=prefcnt[j];
        }
        for(int j=sz-1;j>=0;j--){
            suffsum[j]=a[j].ff*a[j].ss;
            suffsum[j]+=suffsum[j+1];
            suffcnt[j]=a[j].ss;
            suffcnt[j]+=suffcnt[j+1];
        }
        ll ans=LLONG_MAX;
        for(int i=0;i<sz;i++){
            ll need=max(0,k-a[i].ss);
            ll needl=min(need,prefcnt[i]),needr=max(0,need-needl),mov=0;
            //cout<<need<<' '<<needl<<' '<<needr<<' ';
            if(needl)
                mov=(a[i].ff-1)*prefcnt[i]-prefsum[i]+needl;
            if(needr)
                mov+=suffsum[i+1]-(a[i].ff+1)*suffcnt[i+1]+needr;
            //cout<<mov<<'\n';
            ans=min(ans,mov);
            needr=min(need,suffcnt[i+1]),needl=max(0,need-needr),mov=0;
            if(needl)
                mov=(a[i].ff-1)*prefcnt[i]-prefsum[i]+needl;
            if(needr)
                mov+=suffsum[i+1]-(a[i].ff+1)*suffcnt[i+1]+needr;
            ans=min(ans,mov);
        }
        cout<<ans<<'\n';
    }
}